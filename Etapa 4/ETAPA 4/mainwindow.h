#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "territoryview.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(TerritoryView *view,
               QTimer *timer,
               QWidget *parent = nullptr);

private:
    TerritoryView *territoryView;
    QTimer *timer;


};

#endif
