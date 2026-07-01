#ifndef ELOTELTAG_H
#define ELOTELTAG_H

#include "equipo.h"
#include <QString>

class EloTelTag : public Equipo
{
private:
    QString name;

public:
    EloTelTag(const QString& owner,
              const QString& name,
              double x,
              double y,
              double r,
              double theta,
              double dtheta);

    QString getName() const;
};

#endif
