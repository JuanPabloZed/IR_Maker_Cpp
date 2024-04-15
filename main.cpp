#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // temporal folder to play sounds
    QDir currentdir(QDir::currentPath());
    currentdir.mkdir("temp");
    QDir temp("temp");
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/img/irmaker.ico"));
    MainWindow w;
    w.show();
    a.exec();

    temp.removeRecursively();
    return 0;
}
