#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // temporal folder to play sounds
    QDir currentdir(QDir::currentPath());
    QDir temp("temp");
    temp.removeRecursively();
    qDebug() << "first removal";
    currentdir.mkdir("temp");
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/img/irmaker.ico"));
    MainWindow w;
    w.show();
    a.exec();
    temp.removeRecursively();
    if (!temp.exists()){
        qDebug() << "temp removed.";
    };
    return 0;
}
