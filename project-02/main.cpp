// Kuanysh Kairbek
// 256285
// kuanysh.kairbek@student.tut.fi

#include "mainwindow.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
