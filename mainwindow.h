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
    QString recorddir;
    QString savepathauto; // for autosave
    QString savepathcstm; // for custom save

    // audio data
    AudioFile<double> sweep;
    AudioFile<double> recording;
    AudioFile<double> out;
    QSoundEffect ir;
    std::vector<std::vector<float>> out_spectrum;
    void checkall();
    int deconvolve();


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

    void on_beg_freq_textChanged(const QString &arg1);

    void on_autosave_radio_toggled(bool checked);

    void on_end_freq_textChanged(const QString &arg1);

    void on_srate_textChanged(const QString &arg1);

    void on_sweepgen_button_clicked();

    void on_playir_button_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *filemodel;
    QFileSystemModel *dirmodel;
};
#endif // MAINWINDOW_H
