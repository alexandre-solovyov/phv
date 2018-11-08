#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsRectItem>

class Item : public QGraphicsRectItem
{
public:
    Item(double theSize, double theDelta, const QString& theForm, const QString& theTranslation = "");

    virtual void paint(QPainter* thePainter, const QStyleOptionGraphicsItem* theOption, QWidget* theWidget = nullptr);

    double radius() const;
    QPointF center() const;
    void setCenter(const QPointF&);
    void touch(Item* theItem, double theAngleDeg, double theOverlap);

    QColor color() const;
    void setColor(const QColor&);

    int fontSize(int theIndex) const;
    void setFontSize(int theIndex, int theSize);

private:
    void drawText(QPainter* thePainter, const QRectF& theRect, const QString& theText, int& theFontSize);

private:
    QPixmap myImage;
    QString myForm;
    QString myTranslation;
    double myDelta;
    int myFontSize1, myFontSize2;
    QColor myColor;
};

#endif // ITEM_H
