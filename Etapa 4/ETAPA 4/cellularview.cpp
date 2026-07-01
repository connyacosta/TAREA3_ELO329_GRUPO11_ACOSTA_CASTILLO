#include "cellularview.h"
#include "territory.h"
#include "etnube.h"

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QMenu>

CellularView::CellularView(Cellular *cellular, Territory* territory):cellular(cellular), territory(territory)
{
    setHandlesChildEvents(false);
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::AllButtons);
    double width = 12;
    double height = 24;

    auto* radar = new QGraphicsEllipseItem(-75,-75,150,150);
    radar->setBrush(QColor(41,128,185,25));
    radar->setAcceptedMouseButtons(Qt::NoButton);

    addToGroup(radar);

    auto* rect =
        new QGraphicsRectItem(-width/2,
                              -height/2,
                              width,
                              height);

    rect->setBrush(QBrush(Qt::blue));
    rect->setAcceptedMouseButtons(Qt::NoButton);

    auto* label =
        new QGraphicsTextItem(cellular->getOwnerName());

    label->setPos(width/2 + 4, -5);
    label->setDefaultTextColor(Qt::blue);
    label->setAcceptedMouseButtons(Qt::NoButton);

    addToGroup(rect);
    addToGroup(label);

    setPos(cellular->getX(),cellular->getY());

    updatePosition();

}
void CellularView::updatePosition()
{
    setPos(cellular->getX(),
           cellular->getY());
}

void CellularView::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;

    QAction *findMy = menu.addAction("FindMy");

    QAction *selected = menu.exec(event->screenPos());

    if(selected == findMy)
    {
        ETNube::display(
            cellular,
            territory);
    }
}

void CellularView::mousePressEvent(
    QGraphicsSceneMouseEvent *event)
{

    QGraphicsItemGroup::mousePressEvent(event);
}
