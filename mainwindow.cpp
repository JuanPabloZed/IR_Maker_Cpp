#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "about.h"
#include "sweepgenerator.h"

#include "AudioFile.h"
#include "pffft.h"
// #include "qcustomplot.h"

#include <QCustomPlot/qcustomplot.h>
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileSystemModel>
#include <QPen>

#include <cmath>


// define constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // translates .ui file in actual ui
    ui->setupUi(this);


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
    ui->spectrogram_plot->setVisible(false);

    QCPTextElement *irtitle = new QCPTextElement(ui->ir_plot, "Waveform", QFont("sans", 12, QFont::Bold));
    QCPTextElement *freqtitle = new QCPTextElement(ui->freq_plot, "Spectrum", QFont("Arial", 12, QFont::Bold));
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
    ui->freq_plot->yAxis->setBasePen(gridpen);
    ui->freq_plot->yAxis->setTickPen(gridpen);
    ui->freq_plot->yAxis->setLabelColor(labelrgb);
    ui->freq_plot->yAxis->setTickLabelColor(labelrgb);
    ui->freq_plot->yAxis->setLabel("Amplitude (dB)");

    // connect plot functions for e.g. zoom limits
    connect(ui->ir_plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(limXZoomIR(QCPRange)));

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
        || ui->beg_freq->text() == "" || ui->beg_freq->text() == "0"
        || ui->end_freq->text() == "" || ui->beg_freq->text() == "0"
        || recordpath == ""
        || ui->srate->text()== "" || ui->srate->text() == "0")
    { ui->createir_button->setEnabled(false); }

    else if (ui->browsesweep_button->text() != "Browse sweep file"
         && ui->browsesweep_button->text() != ""
         && ui->beg_freq->text() != "" && ui->beg_freq->text() != "0"
         && ui->end_freq->text() != "" && ui->end_freq->text() != "0"
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

int MainWindow::deconvolve(){
    // load existing files
    qDebug() << "load sweep";
    sweep.load(sweeppath.toStdString()); // CHANGE TO FUNC ARG
    qDebug() << "load recording";
    recording.load(recordpath.toStdString()); // CHANGE TO FUNC ARG
    // directly assign the number of output channels
    out.setNumChannels(recording.getNumChannels());

    // create invess
    float invess_temp[sweep.getNumSamplesPerChannel()];
    double k;
    double R = log(20000.0/20.0); // change to values in ui
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
    out.setNumSamplesPerChannel(fftsize);
    // get necessary buffers
    // time buffers
    float *rec_timebuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
    float *invess_timebuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
    // frequency domain buffers
    float *rec_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
    float *invess_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
    float *out_freqbuffer = (float *) pffft_aligned_malloc(fftsize * sizeof(float));
    // work buffer for computation efficiency
    float *work = (float*) pffft_aligned_malloc(fftsize*sizeof(float));

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
    pffft_transform(fftsetup, (const float *)invess_timebuffer, invess_freqbuffer, work, PFFFT_FORWARD);
    pffft_aligned_free(invess_timebuffer); // won't be needed anymore

    //* start of processing loop
    for (int channel = 0; channel < recording.getNumChannels(); channel++)
    {
        // get the rec channel & pad the rest
        for (int i = 0; i < fftsize; i++)
        {
            if (i < recSize)
            {   // fill
                rec_timebuffer[i] = recording.samples[channel][i];
            } else
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
        std::vector<float> outtemp;
        for (int i = 0; i < fftsize; i++){
            outtemp.push_back(temp[i]);
        }
        out_spectrum.push_back(outtemp);
        //- backwards fft
        // use rec buffers since they won't be used anymore and are the right size
        pffft_transform(fftsetup, out_freqbuffer, rec_timebuffer, work, PFFFT_BACKWARD);
        //- write in audio file
        for (int i = 0; i < fftsize; i++)
        {
            out.samples[channel][i] = rec_timebuffer[i];
        }
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
    for (int channel = 0; channel < out.getNumChannels(); channel++)
    {
        for (int i = 0; i < out.getNumSamplesPerChannel(); i++)
        {
            out.samples[channel][i] /= absmax;
        }
    }

    //- destroy buffers
    pffft_aligned_free(invess_freqbuffer);
    pffft_aligned_free(rec_freqbuffer);
    pffft_aligned_free(rec_timebuffer);

    //- trim left side if mono or stereo (if multichannel, just trim convolution delay)
    // trim convolution delay
    for (int chan = 0; chan < out.getNumChannels(); chan++)
    {
        out.samples[chan].erase(out.samples[chan].begin(), std::next(out.samples[chan].begin(), invessSize));
    }
    double thresh = 0.006;
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
        thresh = 0.0005;
        cutlength = out.getNumSamplesPerChannel();
        threshhit = false;
        while (!threshhit){
            if (std::abs(out.samples[0][cutlength] > thresh)){
                threshhit = true;
            } else {
                cutlength--;
            }
        }
        out.samples[0].erase(std::next(out.samples[0].begin(), cutlength), out.samples[0].end());

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
    return fftsize;
}

void MainWindow::limXZoomIR(QCPRange range){
    double lowbound = 0;
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


// buttons
void MainWindow::on_createir_button_clicked()
{
    // check sample rates (NEED TO BE PCM)
    // TODO : ADD QMESSAGEBOX IF NOT PCM)
    if (sweep.getSampleRate() != recording.getSampleRate()){
        QMessageBox::warning(this,"Non matching sample rates","Sample rates between the sweep and the recording are not the same. The resulting IR won't be as clean as it can be.");
    }
    // recordings are ok

    // COMPUTE DECONVOLUTION BY REVERSE CONVOLUTION TECHNIQUE
    int fftsize = this->deconvolve();

    switch(ui->bitdepth_combo->currentIndex())
    {
    case 0: // 16 bits
        out.setBitDepth(16);
        break;
    case 1: // 24 bits
        out.setBitDepth(24);
        break;
    case 2: // 32bits
        out.setBitDepth(32);
        break;
    }

    // OUTPUT
    if (ui->autosave_radio->isChecked()){
        QDir autosaveroot(recorddir);
        QFileInfo recinfo(recordpath);
        // create output folder if not already done
        if (!QDir(recorddir + QString("/IR")).exists()){
            autosaveroot.mkdir("IR");
        }
        savepathauto = recorddir + QString("/IR/") + recinfo.baseName() + QString(" - IR.wav");
        // TODO : SAVE FILE AT SAVEPATHAUTO
        out.save(savepathauto.toStdString());
    } else {
        // TODO : SAVE FILE AT SAVEPATHCSTM
        out.save(savepathcstm.toStdString());
    }

    // PLOTTING
    if (out.isMono()){
    // temporal
    QPen graphsPen;
    graphsPen.setWidth(2);
    graphsPen.setColor(QColor(QRgb(0x8bc34a)));
    QVector<double> x{};
    QVector<double> y{};
    for(int i=0;i<out.getNumSamplesPerChannel(); i++){
        x.push_back((double)i/out.getSampleRate());
        y.push_back(out.samples[0][i]);
    }
    ui->ir_plot->graph(0)->setData(x,y);
    ui->ir_plot->graph(0)->rescaleAxes();
    ui->ir_plot->axisRect()->setRangeZoom(Qt::Horizontal);
    ui->ir_plot->axisRect()->setRangeDrag(Qt::Horizontal);
    ui->ir_plot->setInteraction(QCP::iRangeDrag, true);
    ui->ir_plot->setInteraction(QCP::iRangeZoom, true);
    ui->ir_plot->graph(0)->setPen(graphsPen);

    ui->ir_plot->replot();

    // spectrum
    QVector<double> xfreq{};
    QVector<double> yfreq{};
    for (int i = 0; i < fftsize/2; i++){
        xfreq.push_back(i * (out.getSampleRate()/(float)fftsize));
        yfreq.push_back(20*log10(sqrt(out_spectrum[0][2*i]*out_spectrum[0][2*i] + out_spectrum[0][2*i + 1]*out_spectrum[0][2*i + 1])));
    }
    ui->freq_plot->graph(0)->setData(xfreq, yfreq);
    ui->freq_plot->graph(0)->rescaleAxes();
    ui->freq_plot->xAxis->setRange(20, 22000);
    ui->freq_plot->graph(0)->setPen(graphsPen);

    ui->freq_plot->replot();
    // out_spectrum[0].erase(out_spectrum[0].begin(), out_spectrum[0].end());
    out_spectrum.erase(out_spectrum.begin());
    }
    // now that ir is created, it's possible to play it
    // ui->playir_button->setEnabled(true);
}


void MainWindow::on_browsesweep_button_clicked()
{
    // get path of sweep
    QString sweeppath = QFileDialog::getOpenFileName(this, "Select a sweep file", "C://","WAV files (*.wav)");
    if (sweeppath == ""){
        this->checkall();
        return;
    }
    // store sweep data & info
    sweep.load(sweeppath.toStdString());
    if (sweep.getBitDepth()>=32){
        QMessageBox::critical(this, "64 bits files not supported", "The selected file has a 64-bit bit depth."
                                "Only 16, 24 & 32-bit depths are supported. Please select a sweep file with compatible bit depth.");
        return;
    }
    qDebug() << sweep.getBitDepth();
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

    sweep.load(sweeppath.toStdString());
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


void MainWindow::on_autosr_check_stateChanged(int arg1)
{
    if (ui->autosr_check->isChecked()){
        ui->srate->setEnabled(false);
    } else {
        ui->srate->setEnabled(true);
    }
}


void MainWindow::on_files_list_clicked(const QModelIndex &index)
{
    recordpath  = filemodel->filePath(index);
    // check if special characters in file name
    bool recloaded = recording.load(recordpath.toStdString());
    if (!recloaded){
        QMessageBox::critical(this,"File name with special characters","The file you selected has special characters (letters with accents, punctuation...) that cannot be read. Please either rename your file, or select another one.");
        this->checkall();
        return;
    }
    if (sweep.getSampleRate() != recording.getSampleRate()){
        QMessageBox::warning(this,"Non matching sample rates","Sample rates between the sweep and the recording are not the same. The resulting IR won't be as clean as it can be.");
    }
    // automatically set output samplerate to recording's samplerate if option is checked
    if (ui->autosr_check->isChecked()){
        ui->srate->setText(QString::number(recording.getSampleRate()));
    }

    this->checkall();
}


void MainWindow::on_browseout_button_clicked()
{
    savepathcstm = QFileDialog::getSaveFileName(this, "Select saving location", "C://", "WAV files (*.wav)");
    QStringList list = savepathcstm.split("/");
    // change button text to file name
    ui->browseout_button->setText(list[list.size()-1]);
    this->checkall();
}


void MainWindow::on_about_button_clicked()
{
    About aboutdial;
    aboutdial.exec();

}


void MainWindow::on_beg_freq_textChanged(const QString &arg1)
{ this->checkall(); }


void MainWindow::on_end_freq_textChanged(const QString &arg1)
{ this->checkall(); }


void MainWindow::on_autosave_radio_toggled(bool checked)
{ this->checkall(); }


void MainWindow::on_srate_textChanged(const QString &arg1)
{ this->checkall(); }


void MainWindow::on_sweepgen_button_clicked()
{
    SweepGenerator sweepwindow;
    sweepwindow.exec();
}

