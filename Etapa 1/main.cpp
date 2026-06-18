#include <QApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <iostream>
#include <QTextStream>

#include "territory.h"
#include "territoryview.h"
#include "cellular.h"
#include "cellularview.h"

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

        // Saltar tags en esta etapa
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
        }

        // Saltar tablet en esta etapa
        if(hasTablet)
        {
            double tx,ty,tr,tth,tdth;

            in >> tx
                >> ty
                >> tr
                >> tth
                >> tdth;
        }
    }

    TerritoryView view(imagePath);

    for(auto eq : territory.getEquipments())
    {
        Cellular* cell =
            dynamic_cast<Cellular*>(eq);

        if(cell)
        {
            auto* cv =
                new CellularView(cell);

            view.getScene()->addItem(cv);
        }
    }

    view.resize(1200,800);
    view.show();

    return app.exec();
}
