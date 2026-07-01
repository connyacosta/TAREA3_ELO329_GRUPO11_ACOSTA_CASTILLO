#ifndef TABLETVIEW_H
#define TABLETVIEW_H

#include <QGraphicsItemGroup>

#include "tablet.h"

class TabletView : public QGraphicsItemGroup
{
private:
    Tablet* tablet;

public:
    TabletView(Tablet* tablet);
    void updatePosition(double dt);
};

#endif
