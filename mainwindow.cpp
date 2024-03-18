#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "about.h"
#include "sweepgenerator.h"
#include "AudioFile.h"
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileSystemModel>

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

}
// define destructor
MainWindow::~MainWindow()
{
    delete ui;
}

///FUNCTIONS, SLOTS

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


void MainWindow::on_createir_button_clicked()
{
    // check sample rates (NEED TO BE PCM)
    // TODO : ADD QMESSAGEBOX IF NOT PCM)
    if (sweep.getSampleRate() != recording.getSampleRate()){
        QMessageBox::warning(this,"Non matching sample rates","Sample rates between the sweep and the recording are not the same. The resulting IR won't be as clean as it can be.");
    }
    // recordings are ok

    // compute

    // output
    if (ui->autosave_radio->isChecked()){
        QDir autosaveroot(recorddir);
        QFileInfo recinfo(recordpath);
        // create output folder if not already done
        if (!QDir(recorddir + QString("/IR")).exists()){
            autosaveroot.mkdir("IR");
        }
        savepathauto = recorddir + QString("/IR/") + recinfo.baseName() + QString(" - IR.wav");
        // TODO : SAVE FILE AT SAVEPATHAUTO
    } else {
        // TODO : SAVE FILE AT SAVEPATHCSTM
    }
    // now that ir is created, it's possible to play it
    ui->playir_button->setEnabled(true);
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
    // check if mono
    if (!sweep.isMono()){
        ui->browsesweep_button->setText("Browse sweep file");
        QMessageBox::critical(this,"Sweep file : mono only", "Mono-only sweep files are supported. Please choose a mono file.");
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

