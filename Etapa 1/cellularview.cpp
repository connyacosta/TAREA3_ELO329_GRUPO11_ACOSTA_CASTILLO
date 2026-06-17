#include "cellularview.h"

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>

CellularView::CellularView(Cellular *cellular)
{
    double width = 12;
    double height = 24;

    auto* rect =
        new QGraphicsRectItem(-width/2,
                              -height/2,
                              width,
                              height);

    rect->setBrush(QBrush(Qt::blue));

    auto* label =
        new QGraphicsTextItem(cellular->getOwnerName());

    label->setPos(width/2 + 4, -5);
    label->setDefaultTextColor(Qt::blue);

    addToGroup(rect);
    addToGroup(label);

    setPos(cellular->getX(),
           cellular->getY());
}
