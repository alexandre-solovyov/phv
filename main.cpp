#include "mainwindow.h"
#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication anApp(argc, argv);
    MainWindow aWindow;

    QRect aScreen = anApp.screens().first()->geometry();
    const int W = 800, H = 600;
    int x0 = ( aScreen.width() - W ) / 2;
    int y0 = ( aScreen.height() - H ) / 2;
    aWindow.setGeometry(x0, y0, W, H);
    aWindow.show();

    anApp.processEvents();
    aWindow.showVerb("put");

    return anApp.exec();
}
