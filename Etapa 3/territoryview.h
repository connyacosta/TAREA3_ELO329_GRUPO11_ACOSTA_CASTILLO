#ifndef TERRITORYVIEW_H
#define TERRITORYVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class TerritoryView : public QGraphicsView
{
public:
    TerritoryView(const QString& imageFile);

    QGraphicsScene* getScene();
    double getWidth() const;
    double getHeight() const;

private:
    QGraphicsScene* scene;
};

#endif
