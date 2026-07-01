#include "eloteltagview.h"
#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>

EloTelTagView::EloTelTagView(EloTelTag *tag, )
    : tag(tag)
{

    auto* onda1 = new QGraphicsEllipseItem(-25,-25,50,50);

    onda1->setBrush(QColor(231,76,60,25));

    auto* onda2 = new QGraphicsEllipseItem(-50,-50,100,100);

    onda2->setBrush(QColor(231,76,60,25));

    auto* onda3 = new QGraphicsEllipseItem(-75,-75,150,150);

    onda3->setBrush(QColor(231,76,60,25));

    addToGroup(onda3);
    addToGroup(onda2);
    addToGroup(onda1);

    auto* circle = new QGraphicsEllipseItem(-6,-6,12,12);

    circle->setBrush(QColor(Qt::red));

    auto* label =
        new QGraphicsTextItem(
            tag->getOwnerName()
            + "\n"
            + tag->getName());

    label->setPos(12,-5);
    label->setDefaultTextColor(Qt::red);

    addToGroup(circle);
    addToGroup(label);

    updatePosition();
}

void EloTelTagView::updatePosition(double dt)
{
    setPos(tag->getX(),tag->getY());
    tiempoAcumulado += dt;
    // CADA 4 SEGUNDOS SE EJECUTA EL REPORTE
    if (tiempoAcumulado >= 4.0) {
        tiempoAcumulado = 0.0; // Resetear el contador inmediatamente para los próximos 4s
}
}