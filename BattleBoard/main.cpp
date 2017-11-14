#include "vieMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vieMainWindow w;
    w.show();
    return a.exec();
}
