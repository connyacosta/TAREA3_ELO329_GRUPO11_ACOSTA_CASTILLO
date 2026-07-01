#include "tablet.h"

Tablet::Tablet(const QString& owner,
               double x,
               double y,
               double r,
               double theta,
               double dtheta)
    : Equipo(owner,x,y,r,theta,dtheta)
{
}
