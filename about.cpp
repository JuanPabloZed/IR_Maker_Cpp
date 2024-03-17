#include "about.h"
#include "ui_about.h"
#include <QPixmap>

About::About(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::About)
{
    ui->setupUi(this);

    QPixmap pix(":/img/img/irmaker.ico");
    int h, w;
    h = ui->label_2->height();
    w = ui->label_2->width();
    ui->label_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

About::~About()
{
    delete ui;
}
