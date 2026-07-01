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
    //convertimos los grados
    this->theta = theta * M_PI / 180.0;
    this->dtheta = dtheta * M_PI / 180.0;
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

void Equipo::setX(double value)
{
    x = value;
}

void Equipo::setY(double value)
{
    y = value;
}

void Equipo::move(double dt,
                  double width,
                  double height)
{
    theta += ((double)rand()/RAND_MAX - 0.5) * dtheta;

    x += r * cos(theta) * dt;
    y += r * sin(theta) * dt;

    if(x < 0)
    {
        x = 0;
        theta = M_PI - theta;
    }

    if(x > width)
    {
        x = width;
        theta = M_PI - theta;
    }

    if(y < 0)
    {
        y = 0;
        theta = - theta;
    }

    if(y > height)
    {
        y = height;
        theta = - theta;
    }
}
