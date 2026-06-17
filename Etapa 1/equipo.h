#ifndef EQUIPO_H
#define EQUIPO_H

#include <QString>

class Equipo
{
protected:
    QString ownerName;
    double x;
    double y;

    double r;
    double theta;
    double dtheta;

public:
    Equipo(const QString& owner,
           double x,
           double y,
           double r,
           double theta,
           double dtheta);

    virtual ~Equipo() = default;

    double getX() const;
    double getY() const;

    QString getOwnerName() const;

    virtual void move(double dt);
};

#endif
