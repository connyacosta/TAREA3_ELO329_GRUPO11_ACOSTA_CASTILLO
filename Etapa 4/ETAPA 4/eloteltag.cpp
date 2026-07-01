#include "eloteltag.h"

EloTelTag::EloTelTag(const QString& owner,
                     const QString& name,
                     double x,
                     double y,
                     double r,
                     double theta,
                     double dtheta)
    : Equipo(owner,x,y,r,theta,dtheta),
    name(name)
{
}

QString EloTelTag::getName() const
{
    return name;
}
