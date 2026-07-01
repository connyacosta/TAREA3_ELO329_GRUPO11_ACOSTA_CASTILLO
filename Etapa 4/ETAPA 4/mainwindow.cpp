#include "mainwindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(TerritoryView *view,
                       QTimer *timer,
                       QWidget *parent)
    : QMainWindow(parent),
    territoryView(view),
    timer(timer)
{
    setCentralWidget(view);

    QMenu *simulation =
        menuBar()->addMenu("Simulation");

    QAction *play =
        simulation->addAction("Play");

    QAction *pause =
        simulation->addAction("Pause");

    connect(play,
            &QAction::triggered,
            timer,
            [this]()
            {
                this->timer->start(100);
            });

    connect(pause,
            &QAction::triggered,
            timer,
            &QTimer::stop);
}
