#ifndef SWEEPGENERATOR_H
#define SWEEPGENERATOR_H

#include <QDialog>
#include "AudioFile.h"
#include <qcustomplot.h>
#include <QSoundEffect>

namespace Ui {
class SweepGenerator;
}

class SweepGenerator : public QDialog
{
    Q_OBJECT

public:
    explicit SweepGenerator(QWidget *parent = nullptr);
    ~SweepGenerator();
    QString savepath;
    QString lastsavedir = "C://";

    AudioFile<int> sweep;

    QSoundEffect sound;

private slots:

    void limXZoom(QCPRange range);

    void on_save_button_clicked();

    void on_gen_button_clicked();

    void on_play_button_clicked();

    void on_srate_currentTextChanged(const QString &arg1);

    void on_fullspectrumbox_stateChanged(int arg1);

private:
    Ui::SweepGenerator *ui;
};

#endif // SWEEPGENERATOR_H
