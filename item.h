#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsRectItem>

class Item : public QGraphicsRectItem
{
public:
    Item(double theSize, const QString& theForm, const QString& theTranslation = "");

    virtual void paint(QPainter* thePainter, const QStyleOptionGraphicsItem* theOption, QWidget* theWidget = nullptr);

    double radius() const;
    QPointF center() const;
    void setCenter(const QPointF&);
    void touch(Item* theItem, double theAngleDeg, double theOverlap);

private:
    QPixmap myImage;
    QString myForm;
    QString myTranslation;
    int myFontSize1, myFontSize2;
};

#endif // ITEM_H
