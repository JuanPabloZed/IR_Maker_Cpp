#ifndef SWEEPGENERATOR_H
#define SWEEPGENERATOR_H

#include <QDialog>

namespace Ui {
class SweepGenerator;
}

class SweepGenerator : public QDialog
{
    Q_OBJECT

public:
    explicit SweepGenerator(QWidget *parent = nullptr);
    ~SweepGenerator();

private:
    Ui::SweepGenerator *ui;
};

#endif // SWEEPGENERATOR_H
