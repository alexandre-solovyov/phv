#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Model;
class QGraphicsView;
class QGraphicsScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* theParent = 0);
    ~MainWindow();

    void showVerb(const QString&);

private:
    Model* myModel;
    QGraphicsView* myView;
    QGraphicsScene* myScene;
};

#endif // MAINWINDOW_H
