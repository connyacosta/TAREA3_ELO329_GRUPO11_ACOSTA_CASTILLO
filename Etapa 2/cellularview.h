#ifndef CELLULARVIEW_H
#define CELLULARVIEW_H

#include <QGraphicsItemGroup>
#include "cellular.h"

class CellularView : public QGraphicsItemGroup
{
public:
    CellularView(Cellular* cellular);
    void updatePosition();

private:
    Cellular* cellular;
};

#endif
