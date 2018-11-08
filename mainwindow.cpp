#include "mainwindow.h"
#include "model.h"
#include "item.h"
#include <QGraphicsView>
#include <QGraphicsScene>

const int MAIN_SIZE = 100;
const int SUB_SIZE = 50;
const int OVERLAP = SUB_SIZE/10;

MainWindow::MainWindow(QWidget* theParent)
    : QMainWindow(theParent)
{
    myModel = new Model();
    myView = new QGraphicsView(this);
    myScene = new QGraphicsScene(this);
    myView->setScene(myScene);

    setWindowTitle(tr(""));
    setCentralWidget(myView);
}

MainWindow::~MainWindow()
{
}

void MainWindow::showVerb(const QString& theVerb)
{
    myScene->clear();

    Verb aVerb = myModel->get(theVerb);
    if( aVerb.Forms.empty() )
        return;

    Item* aMainItem = new Item(MAIN_SIZE, aVerb.Main);
    myScene->addItem(aMainItem);
    double delta = -360.0 / aVerb.Forms.count();
    double angle = 90;
    foreach(VerbForm aForm, aVerb.Forms)
    {
        Item* aFormItem = new Item(SUB_SIZE, aForm.Particle, aForm.Translation);
        myScene->addItem(aFormItem);
        aFormItem->touch(aMainItem, angle, OVERLAP);  //TODO
        angle += delta;
    }

    myView->fitInView(myScene->sceneRect(), Qt::KeepAspectRatio);
}
