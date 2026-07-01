#ifndef ELOTELTAGVIEW_H
#define ELOTELTAGVIEW_H

#include <QGraphicsItemGroup>

#include "eloteltag.h"

class EloTelTagView : public QGraphicsItemGroup
{
private:
    EloTelTag* tag;
    double tiempoAcumulado = 0.0; //para el control del reporte

    
public:
    EloTelTagView(EloTelTag* tag);

    void updatePosition(double dt);
};

#endif
