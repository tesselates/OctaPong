#include "mainwindow.hpp"
#include <PongApp>

int main(int argc, char *argv[])
{
    PongApp a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
