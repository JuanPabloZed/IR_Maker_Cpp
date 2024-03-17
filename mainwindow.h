#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "AudioFile.h"
//#include "pffft.h"
#include <QMainWindow>
#include <QFileSystemModel>

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
    QString savepathauto; // for autosave
    QString savepathcstm; // for custom save

    // audio data
    AudioFile<int> sweep;
    AudioFile<int> out;

private slots:
    void on_createir_button_clicked();
    void on_browsesweep_button_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_customsave_radio_toggled(bool checked);

    void on_autosr_check_stateChanged(int arg1);


    void on_files_list_clicked(const QModelIndex &index);

    void on_browseout_button_clicked();

    void on_about_button_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *filemodel;
    QFileSystemModel *dirmodel;
};
#endif // MAINWINDOW_H
