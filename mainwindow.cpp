#include "mainwindow.h"
#include "./ui_mainwindow.h"
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

    // set filemodel for listview
    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath(root);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setNameFilters(QStringList()<<"*.wav");
    filemodel->setNameFilterDisables(false);
    ui->files_list->setModel(filemodel);


}
// define destructor
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createir_button_clicked()
{
    // check if everything is ok before computing
    // sweep in mono
    if (sweeppath != "") {
        if (!sweep.isMono()){
            QMessageBox::critical(this, "Non-mono sweep file", "Sweep file is not mono. Please choose a mono sweep file.");
            return;
    }
    } else {
        QMessageBox::critical(this, "No sweep file selected", "No sweep file has been selected. Please select a sweep file.");
        // make browsesweep_button's border red ?
        return;
    }
    // recordings are ok

    // compute

    // now that ir is created, it's possible to play it
    ui->playir_button->setEnabled(true);
}


void MainWindow::on_browsesweep_button_clicked()
{
    // get path of sweep
    QString sweeppath = QFileDialog::getOpenFileName(this, "Select a sweep file", "C://","WAV files (*.wav)");

    // store sweep data & info
    sweep.load(sweeppath.toStdString());
    // check if mono
    if (!sweep.isMono()){
        ui->browsesweep_button->setText("Browse sweep file");
        QMessageBox::critical(this,"Sweep file : mono only", "Mono-only sweep files are supported. Please choose a mono file.");
        ui->createir_button->setEnabled(false);
        return;
    } else {
        ui->createir_button->setEnabled(true);
    }

    // change button text to file name
    QFileInfo sweepinfo(sweeppath);
    QString sweepname(sweepinfo.baseName());
    ui->browsesweep_button->setText(sweepname);
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString dirpath = dirmodel->fileInfo(index).absoluteFilePath();
    ui->files_list->setRootIndex(filemodel->setRootPath(dirpath));
}




void MainWindow::on_customsave_radio_toggled(bool checked)
{
    if (ui->customsave_radio->isChecked()){
        ui->browseout_button->setEnabled(checked);
    } else {
        ui->browseout_button->setEnabled(checked);
    }
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
}

