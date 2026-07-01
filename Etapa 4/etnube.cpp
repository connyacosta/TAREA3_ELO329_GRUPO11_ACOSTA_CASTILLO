#include "etnube.h"
#include "cellular.h"
#include "eloteltag.h"
#include "tablet.h"

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <cmath>

void ETNube::display(Equipo *equipo, Territory *territory)
{
    QDialog dialog;

    dialog.setWindowTitle("Reporte FindMy");

    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    layout->addWidget(
        new QLabel("REPORTE DE ESTADO"));

    QString tipoEquipo;

    if(dynamic_cast<Cellular*>(equipo))
    {
        tipoEquipo = "Cellular";
    }
    else if(dynamic_cast<EloTelTag*>(equipo))
    {
        tipoEquipo = "Tag";
    }
    else if(dynamic_cast<Tablet*>(equipo))
    {
        tipoEquipo = "Tablet";
    }

    layout->addWidget(
        new QLabel(
            "Tipo: " + tipoEquipo));

    layout->addWidget(
        new QLabel(
            "Dueño: "
            + equipo->getOwnerName()));

    layout->addWidget(
        new QLabel(
            QString("Posición: (%1,%2)")
                .arg(equipo->getX())
                .arg(equipo->getY())));

    double miX = equipo->getX();
    double miY = equipo->getY();

    bool encontro = false;

    for(auto otro : territory->getEquipments())
    {
        if(otro == equipo)
            continue;

        double dx =
            otro->getX() - miX;

        double dy =
            otro->getY() - miY;

        double distancia =
            sqrt(dx*dx + dy*dy);

        if(distancia < 160)
        {
            encontro = true;

            QString tipo;

            if(dynamic_cast<Cellular*>(otro))
            {
                tipo = "Cellular";
            }
            else if(dynamic_cast<EloTelTag*>(otro))
            {
                tipo = "Tag";
            }
            else if(dynamic_cast<Tablet*>(otro))
            {
                tipo = "Tablet";
            }

            layout->addWidget(
                new QLabel(
                    QString("%1 de %2 (%3,%4)")
                        .arg(tipo)
                        .arg(otro->getOwnerName())
                        .arg(otro->getX())
                        .arg(otro->getY())));
        }
    }

    if(!encontro)
    {
        layout->addWidget(
            new QLabel(
                "No se detectaron dispositivos cercanos"));
    }



    QPushButton *closeButton =
        new QPushButton("Cerrar");

    layout->addWidget(closeButton);

    QObject::connect(
        closeButton,
        &QPushButton::clicked,
        &dialog,
        &QDialog::accept);

    dialog.exec();

}
