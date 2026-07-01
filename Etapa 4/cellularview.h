#ifndef CELLULARVIEW_H
#define CELLULARVIEW_H

#include <QGraphicsItemGroup>
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsSceneMouseEvent>
#include "cellular.h"
#include "territory.h"

class CellularView : public QGraphicsItemGroup
{
public:
    CellularView(Cellular* cellular, Territory* territory);
    void updatePosition();

private:
    Cellular* cellular;
    Territory* territory;


protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif
