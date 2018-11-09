#include <mainwindow.h>
#include <model.h>
#include <item.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>

const int MAIN_SIZE = 200;
const int SUB_SIZE = MAIN_SIZE/2;
const int OVERLAP = SUB_SIZE/10;
const double MAIN_DELTA = 0.2;
const double SUB_DELTA = -0.1;
double FULL_CIRCLE = 360.0;
double START_ANGLE = 90.0;

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

    Item* aMainItem = new Item(MAIN_SIZE, MAIN_DELTA, aVerb.Main);
    myScene->addItem(aMainItem);
    double delta = -FULL_CIRCLE / aVerb.Forms.count();
    double angle = START_ANGLE;
    foreach(VerbForm aForm, aVerb.Forms)
    {
        Item* aFormItem = new Item(SUB_SIZE, SUB_DELTA, aForm.Particle, aForm.Translation);
        myScene->addItem(aFormItem);
        aFormItem->touch(aMainItem, angle, OVERLAP);
        aFormItem->setColor(Qt::yellow);
        angle += delta;
    }
    QApplication::processEvents();

    int min1=-1, min2=-2;
    for(int i=0; i<2; i++)
    {
        foreach(QGraphicsItem* item, myScene->items())
        {
            Item* anItem = dynamic_cast<Item*>(item);
            if( anItem && anItem!=aMainItem )
            {
                if(i==0)
                {
                    if(min1<0 || anItem->fontSize(1)<min1)
                        min1 = anItem->fontSize(1);
                    if(min2<0 || anItem->fontSize(2)<min2)
                        min2 = anItem->fontSize(2);
                }
                else
                {
                    //printf("set %i %i\n", min1, min2);
                    anItem->setFontSize(1, min1);
                    anItem->setFontSize(2, min2);
                }
            }
        }
    }
    myView->fitInView(myScene->sceneRect(), Qt::KeepAspectRatio);
}
