#include "tabletview.h"
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

TabletView::TabletView(Tablet *tablet)
    : tablet(tablet)
{

    auto* onda1 = new QGraphicsEllipseItem(-25,-25,50,50);

    onda1->setBrush(QColor(3,160,55,25));

    auto* onda2 = new QGraphicsEllipseItem(-50,-50,100,100);

    onda2->setBrush(QColor(3,160,55,25));

    auto* onda3 =new QGraphicsEllipseItem(-75,-75,150,150);

    onda3->setBrush(QColor(3,160,55,25));

    addToGroup(onda3);
    addToGroup(onda2);
    addToGroup(onda1);

    auto* rect =
        new QGraphicsRectItem(-10,-7,20,14);

    rect->setBrush(QColor(Qt::green));

    auto* label =
        new QGraphicsTextItem(
            "Tablet\n"
            + tablet->getOwnerName());

    label->setPos(14,-5);
    label->setDefaultTextColor(Qt::darkGreen);

    addToGroup(rect);
    addToGroup(label);

    updatePosition();
}

void TabletView::updatePosition()
{
    setPos(tablet->getX(),
           tablet->getY());
}
