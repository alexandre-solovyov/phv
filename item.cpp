#include "item.h"
#include <QPainter>

const double PI = 3.14159265;

Item::Item(double theSize, const QString& theForm, const QString& theTranslation)
    : myForm(theForm), myTranslation(theTranslation), myFontSize1(-1), myFontSize2(-1)
{
    myImage.load("d://PhV//ball.png"); //TODO: more universal
    setRect(0, 0, theSize, theSize);
}

int fitFont(const QString& theText, const QFont& theFont, const QRect& theRect)
{
    const int aMin = 10, aMax = 100;
    for(int i=aMin; i<=aMax; i++)
    {
        QFont f = theFont;
        f.setPixelSize(i);
        QFontMetricsF fm(f);
        QSizeF aSize = fm.boundingRect(theText).size();
        if( aSize.width() > theRect.width() || aSize.height() > theRect.height() )
            return i-1;
    }
    return aMax;
}

double Item::radius() const
{
    return rect().width()/2;
}

QPointF Item::center() const
{
    return sceneBoundingRect().center();
}

void Item::setCenter(const QPointF& thePnt)
{
    setPos(pos() + thePnt - center());
}

void Item::paint(QPainter* thePainter, const QStyleOptionGraphicsItem* theOption, QWidget* theWidget)
{
    thePainter->drawPixmap(rect(), myImage, QRect(0, 0, myImage.width(), myImage.height()));

    double r = radius();
    double d = r * sqrt(2)/2;
    QRect aRect(r - d, r - d, 2*d, 2*d);

    QFont aFont = thePainter->font();
    if(myFontSize1 < 0)
        myFontSize1 = fitFont(myForm, aFont, aRect);

    thePainter->setPen(Qt::white);
    aFont.setPixelSize(myFontSize1);
    thePainter->setFont(aFont);
    thePainter->drawText(aRect, Qt::AlignCenter | Qt::AlignCenter, myForm);
}

void Item::touch(Item* theItem, double theAngleDeg, double theOverlap)
{
    QPointF c = theItem->center();
    double r = theItem->radius() + radius() - theOverlap;
    double alpha = theAngleDeg / 180.0 * PI;
    QPointF rot(r*cos(alpha), -r*sin(alpha));
    setCenter(c + rot);
}


