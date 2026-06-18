#include "tabletview.h"
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

TabletView::TabletView(Tablet *tablet)
    : tablet(tablet)
{
    auto* rect =
        new QGraphicsRectItem(
            -10,
            -7,
            20,
            14);

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
