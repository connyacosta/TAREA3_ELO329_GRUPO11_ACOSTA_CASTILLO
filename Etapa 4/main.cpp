#include <QApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <iostream>
#include <QTextStream>
#include <QTimer>

#include "territory.h"
#include "territoryview.h"
#include "cellular.h"
#include "cellularview.h"
#include "eloteltag.h"
#include "eloteltagview.h"
#include "tablet.h"
#include "tabletview.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString filename =
        QFileDialog::getOpenFileName(
            nullptr,
            "Seleccionar configuración",
            "",
            "Text Files (*.txt)");

    if(filename.isEmpty())
        return 0;

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly))
        return 0;

    QTextStream in(&file);

    QString imageFile;
    in >> imageFile;

    QFileInfo configInfo(filename);

    QString imagePath =
        configInfo.absolutePath() + "/" + imageFile;

    double dt;
    in >> dt;

    int persons;
    in >> persons;

    Territory territory;

    for(int i=0;i<persons;i++)
    {
        QString owner;
        int numTags;
        int hasTablet;

        in >> owner >> numTags >> hasTablet;

        double x,y,r,theta,dtheta;

        in >> x >> y >> r >> theta >> dtheta;

        auto* cellular =
            new Cellular(owner,
                         x,
                         y,
                         r,
                         theta,
                         dtheta);

        std::cout
            << owner.toStdString()
            << " -> ("
            << x
            << ", "
            << y
            << ")"
            << std::endl;

        territory.addEquipment(cellular);

        // Agregar tags
        for(int j=0;j<numTags;j++)
        {
            QString tagName;

            double tx,ty,tr,tth,tdth;

            in >> tagName
                >> tx
                >> ty
                >> tr
                >> tth
                >> tdth;

            auto* tag =
                new EloTelTag(
                    owner,
                    tagName,
                    tx,
                    ty,
                    tr,
                    tth,
                    tdth);

            territory.addEquipment(tag);
        }

        // Agregar tablets
        if(hasTablet)
        {
            double tx,ty,tr,tth,tdth;

            in >> tx
                >> ty
                >> tr
                >> tth
                >> tdth;

            auto* tablet =
                new Tablet(
                    owner,
                    tx,
                    ty,
                    tr,
                    tth,
                    tdth);

            territory.addEquipment(tablet);
        }
    }

    TerritoryView view(imagePath);
    std::vector<CellularView*> cellularViews;
    std::vector<EloTelTagView*> tagViews;
    std::vector<TabletView*> tabletViews;

    for(auto eq : territory.getEquipments())
    {
        Cellular* cell =
            dynamic_cast<Cellular*>(eq);

        if(cell)
        {
            auto* cv = new CellularView(cell, &territory);
            cellularViews.push_back(cv);

            view.getScene()->addItem(cv);
        }

        if(auto* tag =
            dynamic_cast<EloTelTag*>(eq))
        {
            auto* tv =
                new EloTelTagView(tag);

            tagViews.push_back(tv);

            view.getScene()->addItem(tv);
        }


        if(auto* tablet =
            dynamic_cast<Tablet*>(eq))
        {
            auto* tv =
                new TabletView(tablet);

            tabletViews.push_back(tv);

            view.getScene()->addItem(tv);
        }


    }
    QTimer timer;

    QObject::connect(
        &timer,
        &QTimer::timeout,
        [&]()
        {
            for(auto eq:territory.getEquipments())
            {
                eq->move(
                    dt,
                    view.getWidth(),
                    view.getHeight());
            }

            for(auto v : cellularViews)
                v->updatePosition();

            for(auto v : tagViews)
                v->updatePosition(dt);

            for(auto v : tabletViews)
                v->updatePosition(dt);
        });
    timer.start(dt * 1000);

    view.resize(1200,800);
    view.show();

    return app.exec();
}
