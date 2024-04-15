#include "sweepgenerator.h"
#include "ui_sweepgenerator.h"
#include "AudioFile.h"
#include <cmath>
#include <QSoundEffect>


SweepGenerator::SweepGenerator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SweepGenerator)
{
    ui->setupUi(this);
    this->setModal(false);
    ui->spectro_plot->setVisible(false);

    QRgb labelrgb = QRgb(0x8bc34a);
    QPen gridpen;
    QPen subgridpen;
    gridpen.setWidth(1);
    subgridpen.setWidth(1);
    gridpen.setColor(QRgb(0x454545));
    subgridpen.setColor(QRgb(0x353535));
    QCPTextElement *plottitle = new QCPTextElement(ui->sweep_plot, "Waveform", QFont("sans", 12, QFont::Bold));
    plottitle->setTextColor(QColor(labelrgb));

    ui->sweep_plot->setNoAntialiasingOnDrag(true);
    ui->sweep_plot->addGraph();
    ui->sweep_plot->setBackground(QColor(QRgb(0x242526)));
    ui->sweep_plot->plotLayout()->insertRow(0);
    ui->sweep_plot->plotLayout()->addElement(0,0,plottitle);

    ui->sweep_plot->xAxis->grid()->setPen(gridpen);
    ui->sweep_plot->xAxis->grid()->setSubGridVisible(true);
    ui->sweep_plot->xAxis->grid()->setSubGridPen(subgridpen);
    ui->sweep_plot->xAxis->setBasePen(gridpen);
    ui->sweep_plot->xAxis->setTickPen(gridpen);
    ui->sweep_plot->xAxis->setSubTickPen(subgridpen);
    ui->sweep_plot->xAxis->setLabelColor(labelrgb);
    ui->sweep_plot->xAxis->setTickLabelColor(labelrgb);
    ui->sweep_plot->xAxis->setLabel("Time (s)");

    ui->sweep_plot->yAxis->grid()->setPen(gridpen);
    ui->sweep_plot->yAxis->setBasePen(gridpen);
    ui->sweep_plot->yAxis->setTickPen(gridpen);
    ui->sweep_plot->yAxis->setSubTickPen(gridpen);
    ui->sweep_plot->yAxis->setLabelColor(labelrgb);
    ui->sweep_plot->yAxis->setTickLabelColor(labelrgb);
    ui->sweep_plot->yAxis->setRange(-1.05, 1.05);
    ui->sweep_plot->yAxis->grid()->setZeroLinePen(QPen(QColor(QRgb(0x858585)),1));
    ui->sweep_plot->yAxis->setLabel("Amplitude (normalized)");

    connect(ui->sweep_plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(limXZoom(QCPRange)));

}

SweepGenerator::~SweepGenerator()
{
    delete ui;
}

void SweepGenerator::limXZoom(QCPRange range){
    double lowbound = 0;
    double upbound = sweep.getNumSamplesPerChannel()/(double)sweep.getSampleRate();
    QCPRange fixedRange(range);
    if (fixedRange.lower < lowbound){
        fixedRange.lower = lowbound;
        fixedRange.upper = lowbound + range.size();
        if (fixedRange.upper > upbound)
        { fixedRange.upper = upbound; }
        ui->sweep_plot->xAxis->setRange(fixedRange);
    } else if (fixedRange.upper > upbound){
        fixedRange.upper = upbound;
        fixedRange.lower = upbound - range.size();
        if (fixedRange.lower < lowbound)
        { fixedRange.lower = lowbound; }
        ui->sweep_plot->xAxis->setRange(fixedRange);
    }
    return;
}

void SweepGenerator::on_save_button_clicked()
{
    savepath = QFileDialog::getSaveFileName(this,"Select saving location","C://", "WAV files (*.wav)");
    QStringList list = savepath.split("/");
    if (list[list.size()-1] == QString("")){
        ui->save_button->setText("Browse...");
        ui->gen_button->setEnabled(false);
        return;
    } else {
        ui->save_button->setText(list[list.size()-1]);
        ui->gen_button->setEnabled(true);
    }
}


void SweepGenerator::on_gen_button_clicked()
{
    double f1 = ui->beg_freq->text().toDouble();
    double f2 = ui->end_freq->text().toDouble();
    float dur = ui->duration->text().toFloat();
    double R = log(f2 / f1);
    std::vector<int> sweepbuffer(dur * ui->srate->currentText().toInt());

    sweep.setNumChannels(1);
    switch(ui->bitdepth->currentIndex()){
    case 0: // 16 bit
        qDebug() << "case 0";
        sweep.setBitDepth(16);
        break;
    case 1: // 24 bit
        qDebug() << "case 1";
        sweep.setBitDepth(24);
        break;
    case 2: //32 bit
        qDebug() << "case 2";
        sweep.setBitDepth(32);
        break;
    }
    qDebug() << "sweep bit depth : " << sweep.getBitDepth();
    sweep.setNumSamplesPerChannel(ui->srate->currentText().toInt() * ui->duration->text().toDouble());
    sweep.setSampleRate(ui->srate->currentText().toInt());

    for (int i = 0; i < dur * ui->srate->currentText().toInt(); i++){
        double t = i / (double) ui->srate->currentText().toInt();
        sweepbuffer[i] = sin(2*M_PI*f1 * dur/R * (exp(t*R/dur)-1)) * pow(2,sweep.getBitDepth()-1);
    }

    if (ui->fadebox->isChecked()){
        int endfade = dur * ui->srate->currentText().toInt() / 50;
        for (int i = 0; i < endfade; i++){
            sweepbuffer[i] *= i/double(endfade);
        }
        int coef = 0;
        for (int i = dur * ui->srate->currentText().toInt(); i > dur * ui->srate->currentText().toInt() - endfade; i--){
            sweepbuffer[i] *= coef++/double(endfade);
        }
    }
    for (int i=0; i < dur * ui->srate->currentText().toInt(); i++){
        sweep.samples[0][i] = sweepbuffer[i];
    }
    qDebug() << "sweep bit depth : " << sweep.getBitDepth();
    sweep.save(savepath.toStdString());

    ui->sweep_plot->clearGraphs();
    QPen graphsPen;
    graphsPen.setWidth(2);
    graphsPen.setColor(QColor(QRgb(0x8bc34a)));
    QPen gridpen;
    gridpen.setWidth(1);
    gridpen.setColor(QRgb(0x454545));
    QSharedPointer<QCPAxisTicker> monoticker (new QCPAxisTicker);
    QVector<double> x{};
    QVector<double> y{};
    int max = *std::max_element(sweep.samples[0].begin(), sweep.samples[0].end());
    for(int i = 0;i < sweep.getNumSamplesPerChannel(); i++){
        x.push_back((double)i/sweep.getSampleRate());
        y.push_back(sweep.samples[0][i] / (double)max);
    }
    ui->sweep_plot->addGraph()->setData(x,y);
    ui->sweep_plot->yAxis->grid()->setPen(gridpen);
    ui->sweep_plot->yAxis->setTicker(monoticker);
    ui->sweep_plot->rescaleAxes();
    ui->sweep_plot->axisRect()->setRangeZoom(Qt::Horizontal);
    ui->sweep_plot->axisRect()->setRangeDrag(Qt::Horizontal);
    ui->sweep_plot->setInteraction(QCP::iRangeDrag, true);
    ui->sweep_plot->setInteraction(QCP::iRangeZoom, true);
    ui->sweep_plot->graph(0)->setPen(graphsPen);

    ui->sweep_plot->replot();

    ui->play_button->setEnabled(true);
    sound.setSource(QUrl("c:/"));
}


void SweepGenerator::on_play_button_clicked()
{
    qDebug() << "source set at " << sound.source();
    QUrl source = QUrl::fromLocalFile(savepath);
    sound.setSource(source);
    sound.setVolume(1.0f);
    sound.play();

}

