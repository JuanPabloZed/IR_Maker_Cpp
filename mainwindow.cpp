#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "about.h"
#include "sweepgenerator.h"

#include "AudioFile.h"

extern "C"{
#include "pffft.h"
#include "pffft.c"
}
#include <qcustomplot.h>
#include <QPushButton>
#include <QFileDialog>
// #include <QDebug>
#include <QMessageBox>
#include <QFileSystemModel>
#include <QPen>
#include <QSoundEffect>

#include <cmath>

// smooth function for stereo spectra (likely to be reverbs, so will be messy without smoothing)
QVector<double> smooth(QVector<double> &data, int n){
    QVector<double> outvec(data.size());
    double output;
    double val = 1./n;
    QVector<double> b; //Filter coefficients
    QVector<double> m; //Filter memories

    if (n<1)
        n = 1; //Must be > 0 or bad stuff happens

    for (int ii=0; ii<n; ++ii) {
        b.push_back(val);
        m.push_back(0.);
    }

    for (int nn=0; nn<data.size(); ++nn)
    {
        //Apply smoothing filter to signal
        output = 0;
        m[0] = data[nn];
        for (int ii=0; ii<n; ++ii) {
            output+=b[ii]*m[ii];
        }

        //Reshuffle memories
        for (int ii = n-1; ii!=0; --ii) {
            m[ii] = m[ii-1];
        }
        outvec[nn] = output;
    }
    return outvec;
}


// define constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // translates .ui file in actual ui
    ui->setupUi(this);
    // TEMPORAL HIDING OF STUFF
    // ui->testsound->setVisible(false);
    // ui->testir->setVisible(false);

    // initialize the useful paths for no selection detection
    recordpath = "";
    sweeppath = "";
    savepathauto = "";
    savepathcstm = "";

    // set filemodel for the treeview
    QString root = "C:/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(root);
    ui->treeView->setModel(dirmodel);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);

    // set filemodel for listview
    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setNameFilters(QStringList()<<"*.wav");
    filemodel->setNameFilterDisables(false);
    filemodel->setRootPath("");
    ui->files_list->setModel(filemodel);
    this->checkall();

    //Plots initialisation
    QRgb labelrgb = QRgb(0x8bc34a);
    QPen gridpen;
    QPen subgridpen;
    gridpen.setWidth(1);
    subgridpen.setWidth(1);
    gridpen.setColor(QRgb(0x454545));
    subgridpen.setColor(QRgb(0x353535));

    QCPTextElement *irtitle = new QCPTextElement(ui->ir_plot, "Waveform", QFont("sans", 12, QFont::Bold));
    QCPTextElement *freqtitle = new QCPTextElement(ui->freq_plot, "Spectrum", QFont("sans", 12, QFont::Bold));
    irtitle->setTextColor(QColor(labelrgb));
    freqtitle->setTextColor(QColor(labelrgb));
    // IR plot aspect
    ui->ir_plot->setNoAntialiasingOnDrag(true);
    ui->ir_plot->addGraph();
    ui->ir_plot->setBackground(QColor(QRgb(0x242526)));
    ui->ir_plot->plotLayout()->insertRow(0);
    ui->ir_plot->plotLayout()->addElement(0,0,irtitle);

    ui->ir_plot->xAxis->grid()->setPen(gridpen);
    ui->ir_plot->xAxis->grid()->setSubGridVisible(true);
    ui->ir_plot->xAxis->grid()->setSubGridPen(subgridpen);
    ui->ir_plot->xAxis->setBasePen(gridpen);
    ui->ir_plot->xAxis->setTickPen(gridpen);
    ui->ir_plot->xAxis->setSubTickPen(subgridpen);
    ui->ir_plot->xAxis->setLabelColor(labelrgb);
    ui->ir_plot->xAxis->setTickLabelColor(labelrgb);
    ui->ir_plot->xAxis->setLabel("Time (s)");

    ui->ir_plot->yAxis->grid()->setPen(gridpen);
    ui->ir_plot->yAxis->setBasePen(gridpen);
    ui->ir_plot->yAxis->setTickPen(gridpen);
    ui->ir_plot->yAxis->setSubTickPen(gridpen);
    ui->ir_plot->yAxis->setLabelColor(labelrgb);
    ui->ir_plot->yAxis->setTickLabelColor(labelrgb);
    ui->ir_plot->yAxis->setRange(-1.05, 1.05);
    ui->ir_plot->yAxis->grid()->setZeroLinePen(QPen(QColor(QRgb(0x858585)),1));
    ui->ir_plot->yAxis->setLabel("Amplitude (normalized)");

    //Spectrum plot aspect
    ui->freq_plot->setNoAntialiasingOnDrag(true);
    QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);
    QSharedPointer<QCPAxisTickerFixed> yfreqticker(new QCPAxisTickerFixed);
    yfreqticker->setTickStep(20);
    ui->freq_plot->addGraph();
    ui->freq_plot->setBackground(QColor(QRgb(0x242526)));
    ui->freq_plot->plotLayout()->insertRow(0);
    ui->freq_plot->plotLayout()->addElement(0,0,freqtitle);

    ui->freq_plot->xAxis->grid()->setPen(gridpen);
    ui->freq_plot->xAxis->grid()->setSubGridVisible(true);
    ui->freq_plot->xAxis->grid()->setSubGridPen(subgridpen);
    ui->freq_plot->xAxis->setBasePen(gridpen);
    ui->freq_plot->xAxis->setTickPen(gridpen);
    ui->freq_plot->xAxis->setSubTickPen(subgridpen);
    ui->freq_plot->xAxis->setLabelColor(labelrgb);
    ui->freq_plot->xAxis->setTickLabelColor(labelrgb);
    ui->freq_plot->xAxis->setLabel("Frequency(Hz)");
    ui->freq_plot->xAxis->setScaleType(QCPAxis::stLogarithmic);
    ui->freq_plot->xAxis->setTicker(logTicker);
    ui->freq_plot->xAxis->setRange(20, 22000);

    ui->freq_plot->yAxis->grid()->setPen(gridpen);
    ui->freq_plot->yAxis->setTicker(yfreqticker);
    ui->freq_plot->yAxis->setBasePen(gridpen);
    ui->freq_plot->yAxis->setTickPen(gridpen);
    ui->freq_plot->yAxis->setSubTickPen(subgridpen);
    ui->freq_plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->freq_plot->yAxis->setLabelColor(labelrgb);
    ui->freq_plot->yAxis->setTickLabelColor(labelrgb);
    ui->freq_plot->yAxis->setLabel("Amplitude (dB)");
    ui->freq_plot->yAxis->setRange(0, -120);

    // connect plot functions for e.g. zoom limits
    connect(ui->ir_plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(limXZoomIR(QCPRange)));
    connect(ui->freq_plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(limXZoomFreq(QCPRange)));
    connect(ui->freq_plot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(limYZoomFreq(QCPRange)));

    // only ints can be given for custom samples number
    QRegularExpression re("^[0-9]{0,10}");
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(re, this);
    ui->irlengthSamples->setValidator(validator);

}

// define destructor
MainWindow::~MainWindow()
{
    delete ui;
}

///FUNCTIONS, SLOTS
//other funcs
void MainWindow::checkall(){
    if (ui->browsesweep_button->text() == "Browse sweep file"
        || ui->browsesweep_button->text() == ""
        || ui->begfreq->text() == ""
        || ui->endfreq->text() == ""
        || recordpath == ""
        || ui->srate->text()== "" || ui->srate->text() == "0")
    { ui->createir_button->setEnabled(false); }

    else if (ui->browsesweep_button->text() != "Browse sweep file"
         && ui->browsesweep_button->text() != ""
         && ui->begfreq->text() != ""
         && ui->endfreq->text() != ""
         && recordpath !=""
         && ui->srate->text()!= "" && ui->srate->text() != "0")
    {
        if (ui->customsave_radio->isChecked()
            && ui->browseout_button->text() != "" && ui->browseout_button->text() != "Browse output")
        { ui->createir_button->setEnabled(true); }
        else if (ui->autosave_radio->isChecked())
        { ui->createir_button->setEnabled(true); }
        else
        { ui->createir_button->setEnabled(false); }
    }
}

void MainWindow::convolvetest(){


    // prepare fft
    int testSize = testfile.getNumSamplesPerChannel();
    int irSize = out.getNumSamplesPerChannel();
    int fftsize = 1;
    if (testSize >= irSize) { fftsize <<= (int)(log2(testSize - 1) + 1); }
    else { fftsize <<= (int)(log2(irSize - 1) + 1); }

    testwet.setNumSamplesPerChannel(fftsize);

    PFFFT_Setup *fftsetup = pffft_new_setup(fftsize, PFFFT_REAL);
    // CASES FOR IR FORMAT
    // Mono IR
    if (out.isMono()){
        // prepare wet test file
        testwet.setNumChannels(testfile.getNumChannels());
        // create buffers + work buffer
        float *test_timebuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
        float *test_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
        float *wet_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
        float *work = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
        float *ir_buffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
        // fill ir buffer
        // one ir channel so just compute it now
        for(int i = 0; i < fftsize; i++){
            if (i < irSize){
                // fill
                ir_buffer[i] = out.samples[0][i];
            } else {
                // pad
                ir_buffer[i] = 0;
            }
        }
        pffft_transform(fftsetup, ir_buffer, ir_buffer, work, PFFFT_FORWARD);
        // process loop
        for (int channel = 0; channel < testfile.getNumChannels(); channel++){
            // fill & pad time buffers
            for (int i = 0; i < fftsize; i++){
                // test file
                if (i < testSize){
                    // fill
                    test_timebuffer[i] = testfile.samples[channel][i];
                } else {
                    // pad
                    test_timebuffer[i] = 0;
                }
            }
            // forward fft
            pffft_transform(fftsetup, test_timebuffer, test_freqbuffer, work, PFFFT_FORWARD);

            // convolution
            pffft_zconvolve_accumulate(fftsetup, test_freqbuffer, ir_buffer, wet_freqbuffer, 1.0);

            // backwards fft (re-use test_timebuffer because no more needed anyway)
            pffft_transform(fftsetup, wet_freqbuffer, test_timebuffer, work, PFFFT_BACKWARD);

            // write in audio file
            for(int i = 0; i < fftsize; i++){
                testwet.samples[channel][i] = test_timebuffer[i];
            }

            // clear wet buffer before refill
            for (int i = 0; i < fftsize; i++){
                wet_freqbuffer[i] = 0;
            }
        }
        pffft_aligned_free(test_timebuffer);
        pffft_aligned_free(test_freqbuffer);
        pffft_aligned_free(wet_freqbuffer);
        pffft_aligned_free(ir_buffer);
        pffft_aligned_free(work);
    }
    // STEREO IR
    else if (out.isStereo()){
        testwet.setNumChannels(2);
        float *work = (float *)pffft_aligned_malloc(fftsize * sizeof(float));
        // pre-process ir file
        // one buffer per channel
        float *ir_bufferL = (float *)pffft_aligned_malloc(fftsize*sizeof(float));
        float *ir_bufferR = (float *)pffft_aligned_malloc(fftsize*sizeof(float));
        // fill & pad buffers
        for(int i = 0; i< fftsize; i++){
            if (i < irSize){
                ir_bufferL[i] = out.samples[0][i];
                ir_bufferR[i] = out.samples[1][i];
            }  else {
                ir_bufferL[i] = 0;
                ir_bufferR[i] = 0;
            }
        }
        // forward fft
        pffft_transform(fftsetup, ir_bufferL, ir_bufferL, work, PFFFT_FORWARD);
        pffft_transform(fftsetup, ir_bufferR, ir_bufferR, work, PFFFT_FORWARD);
        // mono testfile
        if (testfile.isMono()){
            // create buffers
            float *test_timebuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
            float *test_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
            float *wet_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
            // fill & pad temporal buffer
            for (int i = 0; i < fftsize; i++){
                if (i < testSize){
                    test_timebuffer[i] = testfile.samples[0][i];
                } else {
                    test_timebuffer[i] = 0;
                }
            }
            // forward fft
            pffft_transform(fftsetup, test_timebuffer, test_freqbuffer, work, PFFFT_FORWARD);
            // convolution + writing
            // left
            pffft_zconvolve_accumulate(fftsetup, test_freqbuffer, ir_bufferL, wet_freqbuffer, 1.0);
            // backwards fft
            pffft_transform(fftsetup, wet_freqbuffer, test_timebuffer, work, PFFFT_BACKWARD);
            for (int i  = 0; i < fftsize; i++){
                testwet.samples[0][i] = test_timebuffer[i];
            }
            // clear wet buffer before refill
            for (int i = 0; i < fftsize; i++){
                wet_freqbuffer[i] = 0;
            }
            // right
            pffft_zconvolve_accumulate(fftsetup, test_freqbuffer, ir_bufferR, wet_freqbuffer, 1.0);
            // backwards fft
            pffft_transform(fftsetup, wet_freqbuffer, test_timebuffer, work, PFFFT_BACKWARD);
            for (int i  = 0; i < fftsize; i++){
                testwet.samples[1][i] = test_timebuffer[i];
            }
            // delete buffers
            pffft_aligned_free(test_timebuffer);
            pffft_aligned_free(test_freqbuffer);
            pffft_aligned_free(wet_freqbuffer);
        }
        // stereo testfile
        else if (testfile.isStereo()){
            // create buffers
            float *test_timebuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
            float *test_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
            float *wet_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
            // LEFT
            // fill & pad temporal buffer
            for (int i = 0; i < fftsize; i++){
                if (i < testSize){
                    test_timebuffer[i] = testfile.samples[0][i];
                } else {
                    test_timebuffer[i] = 0;
                }
            }
            // forward fft
            pffft_transform(fftsetup, test_timebuffer, test_freqbuffer, work, PFFFT_FORWARD);
            // convolution
            pffft_zconvolve_accumulate(fftsetup, test_freqbuffer, ir_bufferL, wet_freqbuffer, 1.0);
            // backwards fft
            pffft_transform(fftsetup, wet_freqbuffer, test_timebuffer, work, PFFFT_BACKWARD);
            for (int i  = 0; i < fftsize; i++){
                testwet.samples[0][i] = test_timebuffer[i];
            }
            // clear wet buffer before refill
            for (int i = 0; i < fftsize; i++){
                wet_freqbuffer[i] = 0;
            }
            // RIGHT
            // fill & pad temporal buffer
            for (int i = 0; i < fftsize; i++){
                if (i < testSize){
                    test_timebuffer[i] = testfile.samples[1][i];
                } else {
                    test_timebuffer[i] = 0;
                }
            }
            // forward fft
            pffft_transform(fftsetup, test_timebuffer, test_freqbuffer, work, PFFFT_FORWARD);
            // convolution
            pffft_zconvolve_accumulate(fftsetup, test_freqbuffer, ir_bufferR, wet_freqbuffer, 1.0);
            // backwards fft
            pffft_transform(fftsetup, wet_freqbuffer, test_timebuffer, work, PFFFT_BACKWARD);
            for (int i  = 0; i < fftsize; i++){
                testwet.samples[1][i] = test_timebuffer[i];
            }
            // delete buffers
            pffft_aligned_free(test_timebuffer);
            pffft_aligned_free(test_freqbuffer);
            pffft_aligned_free(wet_freqbuffer);
        }
        pffft_aligned_free(work);
        pffft_aligned_free(ir_bufferL);
        pffft_aligned_free(ir_bufferR);
    }
    // MULTICHANNEL IR
    else {
        testwet.setNumChannels(out.getNumChannels());
        float *ir_buffer = (float *)pffft_aligned_malloc(fftsize * sizeof(float));
        float *test_timebuffer = (float *)pffft_aligned_malloc(fftsize * sizeof(float));
        float *test_freqbuffer = (float *)pffft_aligned_malloc(fftsize * sizeof(float));
        float *wet_freqbuffer = (float *)pffft_aligned_malloc(fftsize * sizeof(float));
        float *work = (float *)pffft_aligned_malloc(fftsize * sizeof(float));
        for(int channel = 0; channel < out.getNumChannels(); channel++){
            // fill & pad for IR and testfile
            for (int i = 0; i < fftsize; i++){
                if (i < irSize){
                    ir_buffer[i] = out.samples[channel][i];
                } else {
                    ir_buffer[i] = 0;
                }
                if (i < testSize){
                    test_timebuffer[i] = testfile.samples[channel][i];
                } else {
                    test_timebuffer[i] = 0;
                }
            }
            // forward fft
            pffft_transform(fftsetup, ir_buffer, ir_buffer, work, PFFFT_FORWARD);
            pffft_transform(fftsetup, test_timebuffer, test_freqbuffer, work, PFFFT_FORWARD);
            // convolution
            pffft_zconvolve_accumulate(fftsetup, test_freqbuffer, ir_buffer, wet_freqbuffer, 1.0);
            // backwards fft
            pffft_transform(fftsetup, wet_freqbuffer, test_timebuffer, work, PFFFT_BACKWARD);
            // write
            for(int i = 0; i < fftsize; i++){
                testwet.samples[channel][i] = test_timebuffer[i];
            }
            // clear wet buffer before refill
            for (int i = 0; i < fftsize; i++){
                wet_freqbuffer[i] = 0;
            }
        }
        // destroy buffers
        pffft_aligned_free(work);
        pffft_aligned_free(ir_buffer);
        pffft_aligned_free(test_timebuffer);
        pffft_aligned_free(test_freqbuffer);
        pffft_aligned_free(wet_freqbuffer);
    }

    // normalization
    std::vector<double> maxs;
    std::vector<double> mins;
    for (int chan = 0; chan < out.getNumChannels(); chan++)
    {
        maxs.push_back(*std::max_element(testwet.samples[chan].begin(), testwet.samples[chan].end()));
        mins.push_back(abs(*std::min_element(testwet.samples[chan].begin(), testwet.samples[chan].end())));
    }
    double max = *std::max_element(maxs.begin(), maxs.end());
    double min = *std::max_element(mins.begin(), mins.end());
    double absmax = std::max(max, min);
    // normalize all output channels
    for (int channel = 0; channel < testwet.getNumChannels(); channel++)
    {
        for (int i = 0; i < testwet.getNumSamplesPerChannel(); i++)
        {
            testwet.samples[channel][i] /= absmax;
        }
    }
    // trimming ?

}

int MainWindow::deconvolve(){

    // directly assign the number of output channels
    out.setNumChannels(recording.getNumChannels());

    // create invess
    std::vector<float> invess_temp(sweep.getNumSamplesPerChannel());
    double k;
    // double R = log((int)(sweep.getSampleRate()*0.5)/20.0); // change to values in ui
    double R = log(ui->endfreq->text().toFloat()/ui->begfreq->text().toFloat()); // change to values in ui
    int i = 0;
    for (std::vector<double>::reverse_iterator riter = sweep.samples[0].rbegin();
         riter != sweep.samples[0].rend(); riter++)
    {
        k = exp((((float) i/sweep.getSampleRate()) * R ) / (sweep.getNumSamplesPerChannel()/(float) sweep.getSampleRate()));
        invess_temp[i] = *riter / k;
        i += 1;
    }
    //- preparation for processing loop
    // set fft size to the adequate length
    int recSize = recording.getNumSamplesPerChannel();
    int invessSize = sweep.getNumSamplesPerChannel();
    int fftsize = 1;
    if (recSize >= invessSize)
    { fftsize <<= (int)(log2(recSize - 1) + 1); }
    else { fftsize <<= (int)(log2(invessSize - 1) + 1); }


    // resize the out buffer
    out.setNumSamplesPerChannel(fftsize);

    // get necessary buffers
    float *invess_timebuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
    // frequency domain buffers
    float *invess_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
    // work buffer for computation efficiency
    float *workinvess = (float*) pffft_aligned_malloc(fftsize*sizeof(float));

    // prepare the fft
    PFFFT_Setup *fftsetup = pffft_new_setup(fftsize, PFFFT_REAL);

    // fill & pad invess buffer since it's supposed to be a mono file
    for (int i = 0; i < fftsize; i++)
    {
        if (i < invessSize)
        {   // fill
            invess_timebuffer[i] = invess_temp[i];
        } else
        {   // pad
            invess_timebuffer[i] = 0;
        }
    }
    // fft the invess for same reason
    pffft_transform(fftsetup, (const float *)invess_timebuffer, invess_freqbuffer, workinvess, PFFFT_FORWARD);
    pffft_aligned_free(invess_timebuffer); // won't be needed anymore
    pffft_aligned_free(workinvess); // won't be needed anymore


    //* start of processing loop
    for (int channel = 0; channel < recording.getNumChannels(); channel++)
    {
        // time buffer
        float *rec_timebuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
        // freq & phase buffer
        float *rec_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
        float *out_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
        // work buffer for computation efficiency
        float *work = (float*) pffft_aligned_malloc(fftsize*sizeof(float));
        // get the rec channel & pad the rest
        for (int i = 0; i < fftsize; i++)
        {
            if (i < recSize)
            {   // fill
                rec_timebuffer[i] = recording.samples[channel][i];
            }
            else
            {   // pad
                rec_timebuffer[i] = 0;
            }
        }
        //- forward fft
        pffft_transform(fftsetup, (const float *)rec_timebuffer, rec_freqbuffer, work, PFFFT_FORWARD);
        //- convolution
        pffft_zconvolve_accumulate(fftsetup, rec_freqbuffer, invess_freqbuffer, out_freqbuffer, 1.0); // manually scale after operation
        // get output spectrum
        float *temp = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
        pffft_zreorder(fftsetup, out_freqbuffer, temp, PFFFT_FORWARD);
        // std::vector<float> outtemp;
        // for (int i = 0; i < fftsize; i++){
        //     outtemp.push_back(temp[i]);
        // }

        // out_spectrum.push_back(outtemp);
        //- backwards fft
        // use rec buffers since they won't be used anymore and are the right size
        pffft_transform(fftsetup, out_freqbuffer, rec_timebuffer, work, PFFFT_BACKWARD);
        //- write in audio file
        for (int i = 0; i < fftsize; i++)
        {
            out.samples[channel][i] = rec_timebuffer[i];
        }

        pffft_aligned_free(rec_timebuffer);
        pffft_aligned_free(rec_freqbuffer);
        pffft_aligned_free(out_freqbuffer);
        pffft_aligned_free(work);
        pffft_aligned_free(temp);

    }

    pffft_destroy_setup(fftsetup);
    //- normalize
    // get absolute maximum
    std::vector<double> maxs;
    std::vector<double> mins;
    for (int chan = 0; chan < out.getNumChannels(); chan++)
    {
        maxs.push_back(*std::max_element(out.samples[chan].begin(), out.samples[chan].end()));
        mins.push_back(abs(*std::min_element(out.samples[chan].begin(), out.samples[chan].end())));
    }
    double max = *std::max_element(maxs.begin(), maxs.end());
    double min = *std::max_element(mins.begin(), mins.end());
    double absmax = std::max(max, min);
    // normalize all output channels
    for (int channel = 0; channel < recording.getNumChannels(); channel++)
    {
        for (int i = 0; i < out.getNumSamplesPerChannel(); i++)
        {
            out.samples[channel][i] /= absmax;
        }
    }

    //- destroy buffers
    pffft_aligned_free(invess_freqbuffer);

    // trim right side for cab IRs
    // also trim right side because cab IRs have to be short
    double thresh = 0.0005;
    int cutlength = out.samples[0].size();
    bool threshhit = false;
    if (ui->CutTailBox->isChecked()){
        while (!threshhit){
            if (std::abs(out.samples[0][cutlength]) > thresh){
                threshhit = true;
            } else {
                cutlength--;
            }
        }
        out.samples[0].erase(std::next(out.samples[0].begin(), cutlength), out.samples[0].end());
    }
    //- trim left side
    if (ui->trimbox->isChecked()){
        // trim convolution delay
        for (int chan = 0; chan < recording.getNumChannels(); chan++)
        {
            out.samples[chan].erase(out.samples[chan].begin(), std::next(out.samples[chan].begin(), invessSize - (ui->srate->text().toInt()*0.2)));
        }
        double thresh = 0.005;
        bool threshhit = false;
        int cutlength = 0;
        if (out.isMono()){
            while (!threshhit){
                if (std::abs(out.samples[0][cutlength]) > thresh){
                    threshhit = true;
                } else {
                    cutlength++;
                }
            }
            out.samples[0].erase(out.samples[0].begin(), std::next(out.samples[0].begin(), cutlength));
            // also trim right side because cab IRs have to be short
            // thresh = 0.0005;
            // cutlength = out.samples[0].size();
            // threshhit = false;
            // while (!threshhit){
            //     if (std::abs(out.samples[0][cutlength]) > thresh){
            //         threshhit = true;
            //     } else {
            //         cutlength--;
            //     }
            // }
            // out.samples[0].erase(std::next(out.samples[0].begin(), cutlength), out.samples[0].end());

        } else if (out.isStereo()){
            while (!threshhit){
                if (std::abs(out.samples[0][cutlength]) > thresh || out.samples[1][cutlength] > thresh){
                    threshhit = true;
                } else {
                    cutlength++;
                }
            }
            out.samples[0].erase(out.samples[0].begin(), std::next(out.samples[0].begin(), cutlength));
            out.samples[1].erase(out.samples[1].begin(), std::next(out.samples[1].begin(), cutlength));
        }

        // trim right side if wanted by the user
        if (ui->irlengthbox->isChecked()){
            if (ui->irlength->text() == ""){
                QMessageBox::critical(this, "No IR length provided", "Please specify the desired length of your IR, or uncheck the \"Custom IR Length\" option.");
            }
            else if (ui->irlengthSamples->text().toInt() > out.getNumSamplesPerChannel()){
                QMessageBox::critical(this, "Custom length longer than file length",
                                      "The wanted length of the IR is greater than the actual length of the file, "
                                      "which is " + QString::number(out.getNumSamplesPerChannel()) + " samples. "
                                      "Please specify a length that is smaller than "
                                      + QString::number(out.getNumSamplesPerChannel()) + " samples. "
                                      "Keeping the file's original length.") ;
            } else {
                int length = ui->irlengthSamples->text().toInt();
                for (int chan=0; chan < recording.getNumChannels(); chan++){
                    out.samples[chan].erase(std::next(out.samples[chan].begin(), length), out.samples[chan].end());
                }
            }
        }
    }
    //- get actual spectrum for IR (take trim into account)
    // new fft transform so new fft size + new setup
    int irfftsize = 1 << (int)(log2(out.getNumSamplesPerChannel() - 1) + 1);
    PFFFT_Setup *irsetup = pffft_new_setup(irfftsize, PFFFT_REAL);
    // necessary buffers
    float *ir_timebuffer = (float *) pffft_aligned_malloc(irfftsize * sizeof(float));
    float *ir_freqbuffer = (float *) pffft_aligned_malloc(irfftsize * sizeof(float));
    float *ir_tempbuffer = (float *) pffft_aligned_malloc(irfftsize * sizeof(float));
    // mono IR
    if (out.isMono()){
    // fill the time buffer
    for (int i = 0; i<irfftsize; i++){
        if (i<out.getNumSamplesPerChannel()){
            ir_timebuffer[i] = out.samples[0][i];
        } else {
            ir_timebuffer[i] = 0;
        }
    }
    // fft transform + reorder for easier processing
    pffft_transform(irsetup, ir_timebuffer, ir_tempbuffer, ir_freqbuffer, PFFFT_FORWARD);
    pffft_zreorder(irsetup, ir_tempbuffer, ir_freqbuffer, PFFFT_FORWARD);
    // prepare spectrum to be sent in out_spectrum
    std::vector<float> irfreq;
    for (int i = 0; i < irfftsize; i++){
        irfreq.push_back(ir_freqbuffer[i]);
    }
    out_spectrum.push_back(irfreq);
    }
    // stereo IR
    else if (out.isStereo()){
        for (int chan = 0; chan < 2; chan++){
            // fill the time buffer
            for (int i = 0; i<irfftsize; i++){
                if (i <= out.getNumSamplesPerChannel()){
                    ir_timebuffer[i] = out.samples[chan][i];
                } else {
                    ir_timebuffer[i] = 0;
                }
            }
            // fft transform + reorder for easier processing
            pffft_transform(irsetup, ir_timebuffer, ir_tempbuffer, ir_freqbuffer, PFFFT_FORWARD);
            pffft_zreorder(irsetup, ir_freqbuffer, ir_tempbuffer, PFFFT_FORWARD);
            // prepare spectrum to be sent in out_spectrum
            std::vector<float> irfreq;
            for (int i = 0; i < irfftsize; i++){
                irfreq.push_back(ir_freqbuffer[i]);
            }
            out_spectrum.push_back(irfreq);
        }
    }
    // destroy fft variables
    pffft_destroy_setup(irsetup);
    pffft_aligned_free(ir_timebuffer);
    pffft_aligned_free(ir_freqbuffer);
    pffft_aligned_free(ir_tempbuffer);

    return irfftsize;
}

void MainWindow::limXZoomIR(QCPRange range){
    const double lowbound = 0;
    double upbound = out.getNumSamplesPerChannel()/(double)out.getSampleRate();
    QCPRange fixedRange(range);
    if (fixedRange.lower < lowbound){
        fixedRange.lower = lowbound;
        fixedRange.upper = lowbound + range.size();
        if (fixedRange.upper > upbound)
            { fixedRange.upper = upbound; }
        ui->ir_plot->xAxis->setRange(fixedRange);
    } else if (fixedRange.upper > upbound){
        fixedRange.upper = upbound;
        fixedRange.lower = upbound - range.size();
        if (fixedRange.lower < lowbound)
            { fixedRange.lower = lowbound; }
        ui->ir_plot->xAxis->setRange(fixedRange);
    }
    return;
}

void MainWindow::limXZoomFreq(QCPRange range){
    const double lowbound = 20;
    const double upbound = 22000;
    QCPRange fixedRange(range);
    if (fixedRange.lower < lowbound){
        fixedRange.lower = lowbound;
        fixedRange.upper = lowbound + range.size();
        if (fixedRange.upper > upbound)
        { fixedRange.upper = upbound; }
        ui->freq_plot->xAxis->setRange(fixedRange);
    } else if (fixedRange.upper > upbound){
        fixedRange.upper = upbound;
        fixedRange.lower = upbound - range.size();
        if (fixedRange.lower < lowbound)
        { fixedRange.lower = lowbound; }
        ui->freq_plot->xAxis->setRange(fixedRange);
    }
    return;
}

void MainWindow::limYZoomFreq(QCPRange range){
    double upbound = 0;
    double lowbound = -120;
    QCPRange fixedRange(range);
    if (fixedRange.lower < lowbound){
        fixedRange.lower = lowbound;
        fixedRange.upper = lowbound + range.size();
        if (fixedRange.upper > upbound)
        { fixedRange.upper = upbound; }
        ui->freq_plot->yAxis->setRange(fixedRange);
    } else if (fixedRange.upper > upbound){
        fixedRange.upper = upbound;
        fixedRange.lower = upbound - range.size();
        if (fixedRange.lower < lowbound)
        { fixedRange.lower = lowbound; }
        ui->freq_plot->yAxis->setRange(fixedRange);
    }
    return;
}


// buttons
void MainWindow::on_createir_button_clicked()
{
    // temporarily disable test ir button to show that it's computing
    ui->testir->setEnabled(false);

    // remove previous temporary output file
    QFile tempoutfile(outuuidurl);

    if (tempoutfile.exists()){
        tempoutfile.remove();
    }

    QFile tempwetfile(testuuidurl);

    if (tempwetfile.exists()){
        tempwetfile.remove();
    }
    // check sample rates (NEED TO BE PCM)
    // TODO : ADD QMESSAGEBOX IF NOT PCM)
    if (sweep.getSampleRate() != recording.getSampleRate()){
        QMessageBox::warning(this,"Non matching sample rates","Sample rates between the sweep and the recording are not the same. The resulting IR won't be as clean as it can be.");
    }
    // recordings are ok



    // COMPUTE DECONVOLUTION BY REVERSE CONVOLUTION TECHNIQUE
    // BEGIN FOR LOOP
    QModelIndexList selectedList = ui->files_list->selectionModel()->selectedIndexes();
    int fftsize = 1;
    for (int index = 0; index < selectedList.size(); index++)
    {
        // clear output spectrum
        if (out_spectrum.size() != 0){
            for (int i=0; i <= out_spectrum.size(); i++){
                out_spectrum.erase(out_spectrum.begin());
            }
        }
        // SELECT RECORDING FILES IN SELECTED LIST
        recordpath  = filemodel->filePath(selectedList[index]);
        // check if special characters in file name
        bool recloaded = recording.load(recordpath.toStdString());
        if (!recloaded){
            QMessageBox::critical(this,"File name with special characters","Selected file(s) or element(s) in its path contain special characters (accents, punctuation...) that cannot be read. "
                                                                             "Either rename the file or the problematic element(s) in its path with ASCII characters, or select another file.");
            this->checkall();
            return;
        }
        if (sweep.getSampleRate() != recording.getSampleRate() && ui->browsesweep_button->text() != "Browse sweep file"){
            QMessageBox::warning(this, "Non-matching sample rates", "Sample rates for the sweep (" + QString::number(sweep.getSampleRate())
                                                                        + "Hz) and for the recording (" + QString::number(recording.getSampleRate()) + " Hz) are not the same. "
                                                                        + "The resulting IR might not be what you expect.");
        }
        if (recording.getNumSamplesPerChannel() < sweep.getNumSamplesPerChannel()){
            QMessageBox::critical(this,"File(s) in batch shorter than sweep","At least one of the selected files is shorter than the sweep. The operation is impossible. "
                                                                   "Please choose files that are longer than the sweep, or a shorter sweep.");
            this->checkall();
            return;
        }
        // automatically set output samplerate to recording's samplerate if option is checked
        if (ui->autosr_check->isChecked()){
            ui->srate->setText(QString::number(recording.getSampleRate()));
        }
        fftsize = this->deconvolve();
        out.setSampleRate(ui->srate->text().toInt());



        // bit depth
        switch(ui->bitdepth_combo->currentIndex())
        {
        case 0: // 16 bits
            out.setBitDepth(16);
            break;
        case 1: // 24 bits
            out.setBitDepth(24);
            break;
        case 2: // 32bits, need to create another AudioFile element to prevent floating point conversion
            out.setBitDepth(32);

            break;
        }

        // fill the output file with buffer data

        // OUTPUT
        QFileInfo recinfo(recordpath);
        if (selectedList.size()==1)
        {
            const auto uuid = QUuid::createUuid();
            auto new_filename = QString("temp/") + uuid.toString(QUuid::WithoutBraces) + ".wav";

            if (ui->autosave_radio->isChecked()){
                QDir autosaveroot(recorddir);

                // create output folder if not already done
                if (!QDir(recorddir + QString("/IR")).exists()){
                    autosaveroot.mkdir("IR");
                }
                savepathauto = recorddir + QString("/IR/") + recinfo.baseName() + QString(" - IR.wav");
                out.save(savepathauto.toStdString());
                QFile::copy(savepathauto, new_filename);
            } else {
                out.save(savepathcstm.toStdString());
                QFile::copy(savepathcstm, new_filename);
            }

            outuuidurl = new_filename;

        } else {

            if (ui->autosave_radio->isChecked()){
                QDir autosaveroot(recorddir);
                // create output folder if not already done
                if (!QDir(recorddir + QString("/IR")).exists()){
                    autosaveroot.mkdir("IR");
                }
                savepathauto = recorddir + QString("/IR/") + recinfo.baseName() + QString(" - IR.wav");
                out.save(savepathauto.toStdString());
            } else {
                QString dircstm = savepathcstm;
                savepathcstm = savepathcstm + QString("/") + recinfo.baseName() + QString(" - IR.wav");
                out.save(savepathcstm.toStdString());
                savepathcstm = dircstm;
            }
        }
    }

    if (selectedList.size()>1 && ui->showgraphsbox->isChecked()){ui->showgraphsbox->setChecked(false);}

    if (!(ui->showgraphsbox->isChecked())){
        QMessageBox::information(this, "Processing done", "Done !");
    }

    // PLOTTING (no plot if batch rendering)
    if (selectedList.size()==1)
    {
    // set default yaxis ticker for ir_plot
    ui->ir_plot->yAxis->setTicker(QSharedPointer<QCPAxisTicker>(new QCPAxisTicker));
    // MONO OUTPUT
    if (out.isMono()){
        ui->ir_plot->clearGraphs();
        ui->freq_plot->clearGraphs();
        // temporal
        QPen graphsPen;
        graphsPen.setWidth(2);
        graphsPen.setColor(QColor(QRgb(0x8bc34a)));
        QPen gridpen;
        gridpen.setWidth(1);
        gridpen.setColor(QRgb(0x454545));
        QSharedPointer<QCPAxisTicker> monoticker (new QCPAxisTicker);
        QVector<double> x{};
        QVector<double> y{};
        for(int i=0;i<out.getNumSamplesPerChannel(); i++){
            x.push_back((double)i/out.getSampleRate());
            y.push_back(out.samples[0][i]);
        }
        ui->ir_plot->addGraph()->setData(x,y);
        ui->ir_plot->yAxis->grid()->setPen(gridpen);
        ui->ir_plot->yAxis->setTicker(monoticker);
        ui->ir_plot->rescaleAxes();
        ui->ir_plot->yAxis->setRange(-1.05, 1.05);
        ui->ir_plot->axisRect()->setRangeZoom(Qt::Horizontal);
        ui->ir_plot->axisRect()->setRangeDrag(Qt::Horizontal);
        ui->ir_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->ir_plot->graph(0)->setPen(graphsPen);

        ui->ir_plot->replot();

        // spectrum
        ui->freq_plot->setVisible(true);
        QVector<double> xfreq{};
        QVector<double> yfreq{};
        std::vector<double> ytemp;
        for (int i = 0; i < fftsize/2; i++){
            xfreq.push_back(i * (out.getSampleRate()/(float)fftsize));
            ytemp.push_back(20*log10(sqrt(out_spectrum[0][2*i]*out_spectrum[0][2*i] + out_spectrum[0][2*i + 1]*out_spectrum[0][2*i + 1])));
        }
        double freqmax = *std::max_element(ytemp.begin(), ytemp.end());
        for (int i = 0; i < fftsize/2; i++){
            yfreq.push_back(ytemp[i] - freqmax);
        }
        ui->freq_plot->addGraph()->setData(xfreq, yfreq);
        ui->freq_plot->graph(0)->rescaleAxes();
        ui->freq_plot->xAxis->setRange(20, 22000);
        ui->freq_plot->yAxis->setRange(0,-120);
        ui->freq_plot->graph(0)->setPen(graphsPen);

        ui->freq_plot->replot();
        // reset the spectrum container for next deconvolutions
        // out_spectrum.erase(out_spectrum.begin());
    }
    // STEREO OUTOPUT
    else if (out.isStereo()){
        // data computing (for spectrum, bc delay from smoothing operation - no delay for temporal)
        QVector<double> xfreq{};
        QVector<double> yfreqL{};
        QVector<double> yfreqR{};
        QVector<double> yfreqLsmooth{};
        QVector<double> yfreqRsmooth{};
        std::vector<double> ytempL;
        std::vector<double> ytempR;
        for (int i = 0; i < fftsize/2; i++){
            xfreq.push_back(i * (out.getSampleRate()/(float)fftsize));
            ytempL.push_back(20*log10(sqrt(out_spectrum[0][2*i]*out_spectrum[0][2*i] + out_spectrum[0][2*i + 1]*out_spectrum[0][2*i + 1])));
            ytempR.push_back(20*log10(sqrt(out_spectrum[1][2*i]*out_spectrum[1][2*i] + out_spectrum[1][2*i + 1]*out_spectrum[1][2*i + 1])));
        }
        double freqmaxL = *std::max_element(ytempL.begin(), ytempL.end());
        double freqmaxR = *std::max_element(ytempR.begin(), ytempR.end());
        for (int i = 0; i < fftsize/2; i++){
            yfreqL.push_back(ytempL[i] - freqmaxL);
            yfreqR.push_back(ytempR[i] - freqmaxR);
        }
        yfreqLsmooth = smooth(yfreqL, 150);
        yfreqRsmooth = smooth(yfreqR, 150);
        // graph
        ui->ir_plot->clearGraphs();
        ui->freq_plot->clearGraphs();
        QPen graphsPenL;
        QPen graphsPenR;
        graphsPenL.setWidth(2);
        graphsPenR.setWidth(2);
        graphsPenL.setColor(QColor(QRgb(0xd43b30)));
        graphsPenR.setColor(QColor(QRgb(0x8bc34a)));
        QVector<double> x{};
        QVector<double> yL{};
        QVector<double> yR{};
        for(int i=0;i<out.getNumSamplesPerChannel(); i++){
            x.push_back((double)i/out.getSampleRate());
            yL.push_back(out.samples[0][i] + 2.1);
            yR.push_back(out.samples[1][i]);
        }
        QSharedPointer <QCPAxisTickerText> textticker(new QCPAxisTickerText());
        QVector<double> ystereoticks = {0,2.1};
        QVector<QString> ystereoticklabels = {"Right", "Left"};
        textticker->setTicks(ystereoticks, ystereoticklabels);
        QPen stereogridpen;
        stereogridpen.setColor(QColor(QRgb(0x858585)));
        ui->ir_plot->yAxis->setTicker(textticker);
        ui->ir_plot->yAxis->grid()->setPen(stereogridpen);
        ui->ir_plot->addGraph()->setData(x,yL);
        ui->ir_plot->addGraph()->setData(x,yR);
        ui->ir_plot->rescaleAxes();
        ui->ir_plot->yAxis->setRange(-1.1, 3.2);
        ui->ir_plot->axisRect()->setRangeZoom(Qt::Horizontal);
        ui->ir_plot->axisRect()->setRangeDrag(Qt::Horizontal);
        ui->ir_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->ir_plot->graph(0)->setPen(graphsPenL);
        ui->ir_plot->graph(1)->setPen(graphsPenR);

        ui->ir_plot->replot();

        // spectrum
        ui->freq_plot->setVisible(true);
        QPen freqPenL;
        QPen freqPenR;
        freqPenL.setWidth(1);
        freqPenR.setWidth(1);
        freqPenL.setColor(QColor(QRgb(0xf45b50)));
        freqPenR.setColor(QColor(QRgb(0x8bc34a)));
        ui->freq_plot->addGraph()->setData(xfreq, yfreqLsmooth);
        ui->freq_plot->addGraph()->setData(xfreq, yfreqRsmooth);
        ui->freq_plot->xAxis->setRange(20,22000);
        ui->freq_plot->yAxis->setRange(0,-100);
        ui->freq_plot->graph(0)->setPen(freqPenL);
        ui->freq_plot->graph(1)->setPen(freqPenR);

        ui->freq_plot->replot();
        // reset the spectrum container for next deconvolutions
        // out_spectrum.erase(out_spectrum.begin());
        // out_spectrum.erase(out_spectrum.begin());

    } else { // MULTICHANNEL OUTPUT
        ui->ir_plot->clearGraphs();
        ui->freq_plot->clearGraphs();
        ui->freq_plot->setVisible(false);

        QPen graphPen;
        graphPen.setWidth(2);
        graphPen.setColor(QColor(QRgb(0x8bc34a)));
        QVector<double> x{};
        QVector<QVector<double>> y;
        for (int chan = 0; chan < out.getNumChannels(); chan++){
            y.push_back({});
            for (int i =0; i < out.getNumSamplesPerChannel(); i++){
                if (chan == 0){
                    x.push_back((double)i / out.getSampleRate());
                }
                y[chan].push_back((out.samples[chan][i] * 0.9f)/2 + (out.getNumChannels() - chan));
            }
        }
        QPen gridpen;
        gridpen.setColor(QColor(QRgb(0x858585)));

        ui->ir_plot->yAxis->setLabel("Channels");
        ui->ir_plot->yAxis->setSubTicks(false);
        ui->ir_plot->yAxis->grid()->setSubGridVisible(false);
        ui->ir_plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
        ui->ir_plot->yAxis->grid()->setPen(gridpen);
        for (int chan = 0; chan < out.getNumChannels(); chan++){
            ui->ir_plot->addGraph()->setData(x, y[chan]);
            ui->ir_plot->graph(chan)->setPen(graphPen);
        }
        // QVector<QString> yticklabels;
        // QVector<double> yticks;
        QSharedPointer<QCPAxisTickerText> yticker(new QCPAxisTickerText);
        ui->ir_plot->yAxis->setTicker(yticker);
        for (int i = 0; i < out.getNumChannels() ; i++){
            yticker->addTick(i+1, QString::number(out.getNumChannels()-i));
        }
        ui->ir_plot->rescaleAxes();
        // ui->ir_plot->xAxis->setRange(0, out.getNumSamplesPerChannel() / out.getSampleRate());
        ui->ir_plot->yAxis->setRange(0.5, out.getNumChannels()+0.5);
        ui->ir_plot->axisRect()->setRangeZoom(Qt::Horizontal);
        ui->ir_plot->axisRect()->setRangeDrag(Qt::Horizontal);
        ui->ir_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

        ui->ir_plot->replot();

    }
    // now that ir is created, it's possible to play it
    ui->playir_button->setEnabled(true);
    ui->testsound->setEnabled(true);

    // tests for reconvolution of testfile
    if (testfile.getNumChannels() > 2 && out.getNumChannels() <= 2){
        ui->testsound->setText("Browse test file");
        ui->testir->setEnabled(false);
        QMessageBox::critical(this, "Multichannel test file for non_multichannel IR", "The selected file is multichannel, which cannot be used to test a non-multichannel IR. Please select a non-multichannel (i.e. mono or stereo) test file.");
        return;
    } else if (testfile.getLengthInSeconds() != 0 && testfile.getSampleRate() != out.getSampleRate()){
        ui->testsound->setText("Browse test file");
        ui->testir->setEnabled(false);
        return;
    } else {
        this->convolvetest();
        // save test wet
        testwet.setSampleRate(out.getSampleRate());
        testwet.setBitDepth(24);
        const auto uuid = QUuid::createUuid();
        auto new_filename = QString("temp/") + uuid.toString(QUuid::WithoutBraces) + ".wav";
        testuuidurl = new_filename;

        testwet.save(new_filename.toStdString());
        ui->testir->setEnabled(true);
        }
    } else {
        ui->showgraphsbox->setChecked(false);
        ui->playir_button->setEnabled(false);
        ui->testir->setEnabled(false);
        ui->testsound->setEnabled(false);
        ui->ir_plot->clearGraphs();
        ui->freq_plot->clearGraphs();
    }
}


void MainWindow::on_browsesweep_button_clicked()
{
    // get path of sweep
    sweeppath = QFileDialog::getOpenFileName(this, "Select the sweep file used for recording the response", lastSweepDir,"WAV files (*.wav)");
    if (sweeppath == ""){
        this->checkall();
        return;
    }
    // store sweep data & info
    bool loaded = sweep.load(sweeppath.toStdString());
    if (!loaded){
        QMessageBox::critical(this, "Invalid sweep path", "Selected sweep or element in its path contain special characters (accents, punctuation...) that cannot be read. "
                                                          "Either rename the file or the problematic(s) element(s) in its path, or select another file.");
        return;
    }
    if (sweep.getBitDepth()>32){
        QMessageBox::critical(this, "64 bits files not supported", "The selected file has a 64-bit bit depth."
                                "Only 16, 24 & 32-bit depths are supported. Please select a sweep file with compatible bit depth.");
        return;
    }

    if (ui->files_list->isEnabled() && recording.getSampleRate() != sweep.getSampleRate()){
        QMessageBox::warning(this, "Non-matching sample rates", "Sample rates for the sweep (" + QString::number(sweep.getSampleRate())
                                                                + "Hz) and for the recording (" + QString::number(recording.getSampleRate()) + " Hz) are not the same."
                                                                + "The resulting IR might not be what you expect.");
    }
    // check if mono-sounding
    if (sweep.isStereo()){
        ui->browsesweep_button->setText("Browse sweep file");
        QMessageBox::warning(this,"Stereo sweep file", "The selected sweep file is stereo. "
                                "It will be converted to mono for the deconvolution."
                                "If left and right channels are the same (e.g sounds mono), no problem will occur."
                                "However if they are not, please select another file.");
        return;
    } else if (!sweep.isMono() && !sweep.isStereo()){
        QMessageBox::critical(this, "Multi-channel sweep not supported", "The selected sweep file is multichannel."
                                "Please select a mono file, or a mono-sounding stereo sweep file.");
        return;
    }
    // change button text to file name
    QFileInfo sweepinfo(sweeppath);
    QString sweepname(sweepinfo.baseName());
    ui->browsesweep_button->setText(sweepname);
    lastSweepDir = sweepinfo.dir().absolutePath();
    sweep.load(sweeppath.toStdString());
    if (ui->fullrangebox->isChecked()){
        ui->begfreq->setText("20");
        ui->endfreq->setText(QString::number(sweep.getSampleRate()/2));
    }
    this->checkall();
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    if (!ui->files_list->isEnabled()){
        ui->files_list->setEnabled(true);
    }
    recorddir = dirmodel->fileInfo(index).absoluteFilePath();
    ui->files_list->setRootIndex(filemodel->setRootPath(recorddir));
}


void MainWindow::on_customsave_radio_toggled(bool checked)
{
    if (ui->customsave_radio->isChecked()){
        ui->browseout_button->setEnabled(checked);
    } else {
        ui->browseout_button->setEnabled(checked);
    }
    this->checkall();
}


void MainWindow::on_browseout_button_clicked()
{
    AudioFile<double> test;

    if (ui->files_list->selectionModel()->selectedIndexes().size() == 1)
    {
        savepathcstm = QFileDialog::getSaveFileName(this, "Select saving location", lastSaveDir, "WAV files (*.wav)");
    } else {
        savepathcstm = QFileDialog::getExistingDirectory(this, "Select saving location (no need to specify file name)", lastSaveDir);
    }
    QFileInfo customOutInfo(savepathcstm);
    QStringList list = savepathcstm.split("/");
    // change button text to file name
    if (savepathcstm == ""){
        ui->browseout_button->setText("Browse output");
        return;
    } else {
        ui->browseout_button->setText(list[list.size()-1]);
        lastSaveDir = customOutInfo.dir().absolutePath();
        }

    // bool loaded = test.load(savepathcstm.toStdString());

    this->checkall();
}


void MainWindow::on_autosr_check_stateChanged(int arg1)
{
    if (ui->autosr_check->isChecked()){
        ui->srate->setEnabled(false);
        ui->srate->setText(QString::number(recording.getSampleRate()));
    } else {
        ui->srate->setEnabled(true);
    }
}


void MainWindow::on_files_list_clicked(const QModelIndex &index)
{
    if (ui->files_list->selectionModel()->selectedIndexes().size() == 1)
    {
        recordpath  = filemodel->filePath(index);
        // check if special characters in file name
        bool recloaded = recording.load(recordpath.toStdString());
        if (!recloaded){
            QMessageBox::critical(this,"File name with special characters","Selected file or element(s) in its path contain special characters (accents, punctuation...) that cannot be read. "
                                                                            "Either rename the file or the problematic(s) element(s) in its path, or select another file.");
            this->checkall();
            return;
        }
        if (sweep.getSampleRate() != recording.getSampleRate() && ui->browsesweep_button->text() != "Browse sweep file"){
            QMessageBox::warning(this, "Non-matching sample rates", "Sample rates for the sweep (" + QString::number(sweep.getSampleRate())
                                                                        + "Hz) and for the recording (" + QString::number(recording.getSampleRate()) + " Hz) are not the same. "
                                                                        + "The resulting IR might not be what you expect.");
        }
        if (recording.getNumSamplesPerChannel() < sweep.getNumSamplesPerChannel()){
            QMessageBox::critical(this,"File shorter than sweep","Selected file is shorter than the sweep. The operation is impossible. "
                                                                             "Please choose files that are longer than the sweep, or a shorter sweep.");
            this->checkall();
            return;
        }
        // automatically set output samplerate to recording's samplerate if option is checked
        if (ui->autosr_check->isChecked()){
            ui->srate->setText(QString::number(recording.getSampleRate()));
        }
    }
    this->checkall();
}


void MainWindow::on_about_button_clicked()
{
    About aboutdial;
    aboutdial.exec();

}


void MainWindow::on_autosave_radio_toggled(bool checked)
{ this->checkall(); }


void MainWindow::on_srate_textChanged(const QString &arg1)
{
    this->checkall();
}


void MainWindow::on_sweepgen_button_clicked()
{
    SweepGenerator sweepwindow;
    sweepwindow.exec();
}


void MainWindow::on_playir_button_clicked()
{

    QSoundEffect *soundir = new QSoundEffect;

    soundir->setSource(QUrl::fromLocalFile(outuuidurl));
    soundir->setVolume(1.0f);
    soundir->play();

}


void MainWindow::on_irlengthbox_stateChanged(int state)
{
    if (state == Qt::Checked){
        ui->irlength->setEnabled(true);
        ui->irlengthSamples->setEnabled(true);

    } else {
        ui->irlength->setEnabled(false);
        ui->irlengthSamples->setEnabled(false);
    }
}


void MainWindow::on_trimbox_stateChanged(int state)
{
    if (ui->trimbox->isChecked() && (!ui->CutTailBox->isChecked())){
        ui->irlengthbox->setEnabled(true);
    } else {
        ui->irlengthbox->setEnabled(false);
        ui->irlengthbox->setChecked(false);
    }
    this->checkall();
}


void MainWindow::on_showgraphsbox_stateChanged(int state)
{
    QSize size;
    size.setWidth(this->width());
    if (state == Qt::Checked){
        ui->splitter->setVisible(true);
        ui->widget_3->setMaximumHeight(290);
        size.setHeight(700);
        ui->widget_3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        this->setMinimumHeight(610);
    } else {
        ui->splitter->setVisible(false);
        size.setHeight(300);
        ui->widget_3->setMaximumHeight(16777215);
        ui->widget_3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        this->setMinimumHeight(300);
    }
    this->resize(size);
}


void MainWindow::on_testsound_clicked()
{
    QFile tempwetfile(testuuidurl);

    if (tempwetfile.exists()){
        tempwetfile.remove();
    }
    //get the user-defined test file
    testpath = QFileDialog::getOpenFileName(this, "Select the audio file you want to try with the IR", "C://", "WAV files (*.wav)");
    // special characters in file name/path
    if (testpath == ""){
        return;
    }
    bool loaded = testfile.load(testpath.toStdString());
    if (!loaded){
        QMessageBox::critical(this, "Invalid test file path", "Selected file or element(s) in its path contain special characters (accents, punctuation...) that cannot be read. "
                                                              "Either rename the file or the problematic(s) element(s) in its path, or select another file.");
        return;
    }
    // control test file (length, format...)
    if (testfile.getBitDepth() > 32){
        QMessageBox::critical(this, "Invalid bitdepth", "Selected file has a " + QString::number(testfile.getBitDepth()) + " bit bitdepth. "
                                                        "Supported bitdepths are 16, 24 and 32 bit PCM.");
        return;
    }
    // if multichannel testfile but mono/stereo ir
    if (testfile.getNumChannels() > 2 && out.getNumChannels() <= 2){
        QMessageBox::critical(this, "Multichannel test file for non-multi channel IR", "Selected file is multichannel but IR is not. Please select either a mono or stereo test file.");
        return;
    }
    //if multichannel IR but non multichannel testfile
    if(out.getNumChannels()>2 && testfile.getNumChannels() <= 2){
        QMessageBox::critical(this, "Multichannel incompatibility", "Selected test file is not multichannel whereas the IR is. Please select a multichannel test file.");
        return;
    }

    // if non matching sample rates
    if (testfile.getSampleRate() != out.getSampleRate()){
        QMessageBox::critical(this, "Non-matching sample rates", "The test file and the IR have a different sample rate (" + QString::number(testfile.getSampleRate()) + "Hz and " + QString::number(out.getSampleRate())+ "Hz). "
                                                                 "Please select a test file with a sample rate of " + QString::number(out.getSampleRate()) + "Hz.");
        return;
    }

    // length (just to warn that convolution will be long)
    if (testfile.getNumSamplesPerChannel() > 60 * out.getSampleRate()){
        // user can continue to proceed with buttons
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Long test file", "Selected test file is more than a minute long, the longer your test file is, the longer it takes to compute it. Proceed anyways ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::No){
            ui->testsound->setText("Browse test sound");
            return;
        }
    }
    // change button text to file name
    if (testpath == ""){
        ui->browseout_button->setText("Browse test sound");
    } else {
        QFileInfo testinfo(testpath);
        QString testname(testinfo.baseName());
        ui->testsound->setText(testname);
    }

    // convolution
    if (testfile.getLengthInSeconds() > 10){
        testfile.setNumSamplesPerChannel(10*testfile.getSampleRate());
    }
    this->convolvetest();
    // save test wet
    testwet.setSampleRate(out.getSampleRate());
    testwet.setBitDepth(24);


    const auto uuid = QUuid::createUuid();
    auto new_filename = QString("temp/") + uuid.toString(QUuid::WithoutBraces) + ".wav";
    testuuidurl = new_filename;

    testwet.save(new_filename.toStdString());
    // when all done, activate the test ir button
    ui->testir->setEnabled(true);

}


void MainWindow::on_testir_clicked()
{
    QSoundEffect *wetsound = new QSoundEffect;
    if (wetsound->isPlaying()){
        wetsound->stop();
        wetsound->setSource(QUrl::fromLocalFile(outuuidurl));
        return;
    } else {
        wetsound->setSource(QUrl::fromLocalFile(testuuidurl));
        wetsound->setVolume(1.0f);
        wetsound->play();
        return;
    }
}


void MainWindow::on_irlengthSamples_editingFinished()
{
    float durms = ui->irlengthSamples->text().toFloat() / ui->srate->text().toFloat() * 1000;
    ui->irlength->setText(QString::number(durms));
}


void MainWindow::on_irlength_editingFinished()
{
    float numsamples = ui->irlength->text().toFloat() / 1000 * ui->srate->text().toFloat();
    ui->irlengthSamples->setText(QString::number((int)numsamples));
}


void MainWindow::on_irlengthSamples_textChanged(const QString &arg1)
{
    if (ui->irlengthSamples->text().toFloat() != ui->irlengthSamples->text().toInt()){
        ui->irlengthSamples->setText(QString::number(ui->irlengthSamples->text().toInt()));
    }
}


void MainWindow::on_fullrangebox_stateChanged(int arg1)
{
    if (ui->fullrangebox->isChecked()){
        ui->freqwidget->setEnabled(false);
        if (ui->browsesweep_button->text() != "Browse sweep file"){
            ui->begfreq->setText("20");
            ui->endfreq->setText(QString::number(sweep.getSampleRate()/2));
        }
    } else {
        ui->freqwidget->setEnabled(true);
    }
    this->checkall();
}

void MainWindow::on_begfreq_textChanged(const QString &arg1)
{
    this->checkall();
}


void MainWindow::on_endfreq_textChanged(const QString &arg1)
{
    this->checkall();
}


void MainWindow::on_CutTailBox_stateChanged(int state)
{
    if (ui->trimbox->isChecked() && (!ui->CutTailBox->isChecked())){
        ui->irlengthbox->setEnabled(true);
    } else {
        ui->irlengthbox->setEnabled(false);
        ui->irlengthbox->setChecked(false);

    }

    this->checkall();
}

