#include "eloteltagview.h"
#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>

EloTelTagView::EloTelTagView(EloTelTag *tag)
    : tag(tag)
{
    auto* circle =
        new QGraphicsEllipseItem(-6,-6,12,12);

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

void EloTelTagView::updatePosition()
{
    setPos(tag->getX(),
           tag->getY());
}
