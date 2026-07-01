#ifndef ELOTELTAGVIEW_H
#define ELOTELTAGVIEW_H

#include <QGraphicsItemGroup>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include "eloteltag.h"

class EloTelTagView : public QGraphicsItemGroup
{
private:
    EloTelTag* tag;

    // Atributos para el radas
    bool estaBuscando;    //para controlar el radar cuando el sistema está funcionando/encendido
    double radioActual;   //El radio del circulo que simula el radar va de 0 a 50

public:
    EloTelTagView(EloTelTag* tag);

    void updatePosition();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    // Función para activar el radar cuando pasen los 4 segundos
    void dispararRadar();

    // Función para que la animación avance en cada tick del reloj principal
    void avanzarAnimacionRadar(double dt);
};

#endif