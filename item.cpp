#include "item.h"
#include <QPainter>

const double PI = 3.14159265;

Item::Item(double theSize, double theDelta, const QString& theForm, const QString& theTranslation)
    : myForm(theForm), myTranslation(theTranslation), myFontSize1(-1), myFontSize2(-1), myDelta(theDelta),
      myColor(Qt::white)
{
    myImage.load("d://PhV//ball.png"); //TODO: more universal
    setRect(0, 0, theSize, theSize);
}

int fitFont(const QString& theText, const QFont& theFont, const QRectF& theRect)
{
    const int aMin = 2, aMax = 100;
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
    double delta = r * myDelta;

    //printf("draw %i %i\n", myFontSize1, myFontSize2);

    bool isDouble = !myTranslation.isEmpty();
    QRectF aRect1(r - d, r - d - delta, 2*d, isDouble ? d : 2*d);
    drawText(thePainter, aRect1, myForm, myFontSize1);

    if(isDouble)
    {
        QRectF aRect2(r - d, r - delta, 2*d, d);
        drawText(thePainter, aRect2, myTranslation, myFontSize2);
    }
}

void Item::touch(Item* theItem, double theAngleDeg, double theOverlap)
{
    QPointF c = theItem->center();
    double r = theItem->radius() + radius() - theOverlap;
    double alpha = theAngleDeg / 180.0 * PI;
    QPointF rot(r*cos(alpha), -r*sin(alpha));
    setCenter(c + rot);
}

void Item::drawText(QPainter* thePainter, const QRectF& theRect, const QString& theText, int& theFontSize)
{
    QFont aFont = thePainter->font();
    if(theFontSize < 0)
        theFontSize = fitFont(theText, aFont, theRect);

    thePainter->setPen(myColor);
    aFont.setPixelSize(theFontSize);
    thePainter->setFont(aFont);
    thePainter->drawText(theRect, Qt::AlignCenter, theText);

    //thePainter->drawRect(theRect);
}

QColor Item::color() const
{
    return myColor;
}

void Item::setColor(const QColor& theColor)
{
    myColor = theColor;
}

int Item::fontSize(int theIndex) const
{
    switch(theIndex)
    {
    case 1: return myFontSize1;
    case 2: return myFontSize2;
    default: return -1;
    }
}

void Item::setFontSize(int theIndex, int theSize)
{
    switch(theIndex)
    {
    case 1: myFontSize1 = theSize; break;
    case 2: myFontSize2 = theSize; break;
    default: break;
    }
}
