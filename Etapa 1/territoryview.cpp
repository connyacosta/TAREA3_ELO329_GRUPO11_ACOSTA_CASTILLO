#include "territoryview.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>

TerritoryView::TerritoryView(const QString& imageFile)
{
    scene = new QGraphicsScene(this);

    QPixmap pix(imageFile);

    if (pix.isNull())
    {
        qDebug() << "No se pudo cargar la imagen:"
                 << imageFile;
    }
    else
    {
        qDebug() << "Imagen cargada:"
                 << imageFile;
    }

    scene->addPixmap(pix);

    scene->setSceneRect(pix.rect());

    setScene(scene);
    setDragMode(QGraphicsView::ScrollHandDrag);

}

