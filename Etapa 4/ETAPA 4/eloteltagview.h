#ifndef ELOTELTAGVIEW_H
#define ELOTELTAGVIEW_H

#include <QGraphicsItemGroup>

#include "eloteltag.h"

class EloTelTagView : public QGraphicsItemGroup
{
private:
    EloTelTag* tag;

public:
    EloTelTagView(EloTelTag* tag);

    void updatePosition();
};

#endif
