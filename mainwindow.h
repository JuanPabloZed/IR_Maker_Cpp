#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "AudioFile.h"
#include "qcustomplot.h"
#include <QMainWindow>
#include <QFileSystemModel>
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // construcor, destructor
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //info for processing
    QString sweeppath;
    QString recordpath;
    QString testpath;
    QString recorddir;
    QString savepathauto; // for autosave
    QString savepathcstm; // for custom save

    // batch rendering option
    bool batchrender = false;

    // audio data
    AudioFile<double> sweep;
    AudioFile<double> recording;
    AudioFile<double> testfile;
    AudioFile<double> testwet;
    AudioFile<double> out;
    std::vector<std::vector<float>> out_spectrum;
    void checkall();
    int deconvolve();
    void convolvetest();
    QString outuuidurl;
    QString testuuidurl;
    QString lastSweepDir = "C://";
    QString lastSaveDir = "C://";


private slots:
    void limXZoomIR(QCPRange);

    void limXZoomFreq(QCPRange);

    void limYZoomFreq(QCPRange);

    void on_createir_button_clicked();

    void on_browsesweep_button_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_customsave_radio_toggled(bool checked);

    void on_autosr_check_stateChanged(int arg1);

    void on_files_list_clicked(const QModelIndex &index);

    void on_browseout_button_clicked();

    void on_about_button_clicked();

    void on_autosave_radio_toggled(bool checked);

    void on_srate_textChanged(const QString &arg1);

    void on_sweepgen_button_clicked();

    void on_playir_button_clicked();

    void on_irlengthbox_stateChanged(int arg1);

    void on_trimbox_stateChanged(int arg1);

    void on_showgraphsbox_stateChanged(int arg1);

    void on_testsound_clicked();

    void on_testir_clicked();

    void on_irlengthSamples_editingFinished();

    void on_irlength_editingFinished();

    void on_irlengthSamples_textChanged(const QString &arg1);

    void on_fullrangebox_stateChanged(int arg1);

    void on_begfreq_textChanged(const QString &arg1);

    void on_endfreq_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *filemodel;
    QFileSystemModel *dirmodel;
};
#endif // MAINWINDOW_H
