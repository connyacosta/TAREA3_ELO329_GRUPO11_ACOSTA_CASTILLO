#ifndef TABLET_H
#define TABLET_H

#include "equipo.h"

class Tablet : public Equipo
{
public:
    Tablet(const QString& owner,
           double x,
           double y,
           double r,
           double theta,
           double dtheta);
};

#endif
