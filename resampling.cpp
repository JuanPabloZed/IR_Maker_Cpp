#include <iostream>
#include <string>
#include <assert.h>
#include <cstdint>
#include "AudioFile.h"
#define _USE_MATH_DEFINES
#include <math.h>

inline double sinc(double x) { return x == 0.0 ? 1.0 : sin(M_PI * x)/(M_PI*x); }

inline double hann_window(double x) { return 0.5 * (1 - cos(2 * M_PI * x)); }


enum Coeffs { b0, b1, b2, a1, a2 };
enum State { w1, w2 };

struct AntiAliasingFilter {

    double stage1[5];
    double stage2[5];
    
    double state1[2];
    double state2[2];
};

AudioFile<double>::AudioBuffer resample(AudioFile<double>::AudioBuffer &input_file, double current_samplerate, double target_samplerate) {

    int n_zero_crossing = 8;
    int interpolation_length = 2*n_zero_crossing + 1;
    double target_time_increment = 1/target_samplerate;
    
    int num_channels = input_file.size();
    int num_samples = input_file[0].size();
    double time_increment = 1/current_samplerate;
    
    int target_num_samples = (int)floor(num_samples * target_samplerate/current_samplerate);

    std::vector<double> input_signal(num_samples + 2 * n_zero_crossing + 1);

    AudioFile<double>::AudioBuffer output_buffer;
    output_buffer.resize(num_channels);
    
    for (int channel = 0; channel < num_channels; channel++) {
        output_buffer[channel].resize(target_num_samples);
    }
    
    AntiAliasingFilter filter;    
    bool anti_alias = target_samplerate < current_samplerate;
      
    // setup the anti aliasing filter if needed
    if (anti_alias) {
        double frequency = 0.5 * 0.9 * (target_samplerate);
    
        // Q factor for order 4 butterworth response 
        double Q_stage1 = 0.54119610;
        double Q_stage2 = 1.3065630;
        
        double w0 = M_PI * 2 * frequency / current_samplerate;
        double cosw0 = cos(w0);
        double sinw0 = sin(w0);
        
        double alpha_stage1 = sinw0/(2.0f*Q_stage1);
        double alpha_stage2 = sinw0/(2.0f*Q_stage2);
        
        double a0inv = 1.0/(1.0 + alpha_stage1);
    
        filter.stage1[b0] = ((1.0 - cosw0) * 0.5 * a0inv);
        filter.stage1[b1] = (2.0 * filter.stage1[b0]);
        filter.stage1[b2] = (filter.stage1[b0]);
        filter.stage1[a1] = (-2.0 * cosw0 * a0inv);
        filter.stage1[a2] = ((1.0 - alpha_stage1) * a0inv);
    
        a0inv = 1.0/(1.0 + alpha_stage2);
    
        filter.stage2[b0] = ((1.0 - cosw0) * 0.5 * a0inv);
        filter.stage2[b1] = (2.0 * filter.stage2[b0]);
        filter.stage2[b2] = (filter.stage2[b0]);
        filter.stage2[a1] = (-2.0 * cosw0 * a0inv);
        filter.stage2[a2] = ((1.0 - alpha_stage2) * a0inv);
        
        filter.state1[w1] = 0.0;
        filter.state1[w2] = 0.0;
        
        filter.state2[w1] = 0.0;
        filter.state2[w2] = 0.0;
    }

    // iterate over every channel of the input signal
    for (int channel_index = 0; channel_index < num_channels; channel_index++) {

        filter.state1[w1] = 0.0;
        filter.state1[w2] = 0.0;
        filter.state2[w1] = 0.0;
        filter.state2[w2] = 0.0;        

        double time_position = 0.0;
        std::copy(input_file[channel_index].begin(), 
                  input_file[channel_index].end(), 
                  input_signal.begin() + n_zero_crossing);
        
        if (anti_alias) {
            for (int index = 0; index < input_signal.size(); index++) {
                double *coeffs = filter.stage1;
                double *state = filter.state1;
                
                double input_sample = input_signal[index];
                
                double w = input_sample - coeffs[a1]*state[w1] - coeffs[a2]*state[w2];
                input_sample = coeffs[b0]*w + coeffs[b1]*state[w1] + coeffs[b2]*state[w2];
                
                state[w2] = state[w1];
                state[w1] = w;
                
                coeffs = filter.stage2;
                state = filter.state2;
                
                w = input_sample - coeffs[a1]*state[w1] - coeffs[a2]*state[w2];
                input_sample = coeffs[b0]*w + coeffs[b1]*state[w1] + coeffs[b2]*state[w2];
                
                state[w2] = state[w1];
                state[w1] = w;

                input_signal[index] = input_sample;
            }
        }
    
        for (int index = 0; index < output_buffer[channel_index].size(); index++) {
       
            double floating_index = time_position * current_samplerate;
            int input_buffer_index = (int)floor(floating_index) + n_zero_crossing;
            double interpolation_factor = floating_index - (double)(input_buffer_index - n_zero_crossing);
            double result_sample = 0.0;
    
            for (int zero_cross_index = -n_zero_crossing; zero_cross_index <= n_zero_crossing; zero_cross_index++) {
                double sinc_value = sinc((zero_cross_index + interpolation_factor));
                double signal_value = input_signal[input_buffer_index + zero_cross_index];
                double hann_value = hann_window((zero_cross_index + n_zero_crossing + interpolation_factor)/(interpolation_length - 1));
                double temp_result = signal_value * sinc_value * hann_value;
                result_sample += temp_result;
            }
    
            output_buffer[channel_index][index] = (double)result_sample;
    
            time_position += target_time_increment;
        }
    }

    return output_buffer;
}


int main() {

    std::string filepath = "guitar441k.wav";
    // std::string filepath = "01 Butt Scratcher.wav";
    AudioFile<double> input_file;
    input_file.load(filepath);

    double target_samplerate = 48000.0;
    
    std::cout << "input samplerate : " << input_file.getSampleRate() << '\n';
    std::cout << "target samplerate : " << target_samplerate << '\n'; 

    AudioFile<double>::AudioBuffer output_buffer = resample(input_file.samples, input_file.getSampleRate(), target_samplerate);

    AudioFile<double> output_file;
    output_file.setSampleRate(target_samplerate);
    output_file.setAudioBuffer(output_buffer);
    
    bool ok = output_file.save("output_file.wav", AudioFileFormat::Wave);
    
    
    // AudioFile<double>::AudioBuffer output_buffer_return = resample(output_buffer, target_samplerate, input_file.getSampleRate());
    // AudioFile<double> output_file_return;
    // output_file_return.setSampleRate(input_file.getSampleRate());
    // output_file_return.setAudioBuffer(output_buffer_return);
    
    // bool ok2 = output_file_return.save("output_file_return.wav", AudioFileFormat::Wave);
    
    return 0;
}