#include "equipo.h"
#include <cmath>
#include <cstdlib>

Equipo::Equipo(const QString& owner,
               double x,
               double y,
               double r,
               double theta,
               double dtheta)
    : ownerName(owner),
    x(x),
    y(y),
    r(r),
    theta(theta),
    dtheta(dtheta)
{
}

double Equipo::getX() const
{
    return x;
}

double Equipo::getY() const
{
    return y;
}

QString Equipo::getOwnerName() const
{
    return ownerName;
}

void Equipo::move(double dt)
{
    theta += ((double)rand() / RAND_MAX - 0.5) * dtheta;

    x += r * cos(theta) * dt;
    y += r * sin(theta) * dt;
}
