#include "sweepgenerator.h"
#include "ui_sweepgenerator.h"

SweepGenerator::SweepGenerator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SweepGenerator)
{
    ui->setupUi(this);
}

SweepGenerator::~SweepGenerator()
{
    delete ui;
}
