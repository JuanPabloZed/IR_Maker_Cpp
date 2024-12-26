#include <iostream>
#include <audiofile.h>
#include <fftw/fftw3.h>
// using std::cout, std::endl, std::cin;
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Fonction pour créer un signal sinusoïdal
void generate_signal(std::vector<double>& signal, int n, double frequency, double sample_rate) {
    for (int i = 0; i < n; ++i) {
        signal[i] = std::sin(2 * M_PI * frequency * i / sample_rate);
    }
}

int main() {
    // Paramètres du signal
    const double sample_rate = 44100.0; // Fréquence d'échantillonnage en Hz
    const double signal_freq = 500.0;   // Fréquence du signal sinusoïdal en Hz
    const int N = 32768;           // Nombre d'échantillons

    // Signal en entrée (réel)
    std::vector<double> signal(N);

    // Générer un signal sinusoïdal
    generate_signal(signal, N, signal_freq, sample_rate);

    // Créer des tableaux pour la FFT
    fftw_complex* in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    fftw_complex* out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    // Remplir l'entrée FFT avec des données réelles
    for (int i = 0; i < N; ++i) {
        in[i][0] = signal[i];   // Partie réelle
        in[i][1] = 0.0;         // Partie imaginaire (initialisée à zéro)
    }

    // Plan de FFT
    fftw_plan p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    // Exécution de la FFT
    fftw_execute(p);

    // Affichage des résultats
    std::cout << "Spectre de fréquence :\n";
    for (int i = 0; i < N/2; ++i) {
        double real = out[i][0];
        double imag = out[i][1];
        double magnitude = std::sqrt(real * real + imag * imag);
        double frequency = (i * sample_rate) / N; // Fréquence correspondante

        // Affichage de la magnitude du spectre
        std::cout << "Fréquence: " << frequency << " Hz, Magnitude: " << magnitude << std::endl;
    }

    // Libération des ressources
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);

    return 0;
}
