#ifndef TERRITORY_H
#define TERRITORY_H

#include <vector>
#include "equipo.h"

class Territory
{
private:
    std::vector<Equipo*> equipments;

public:
    void addEquipment(Equipo* eq);

    const std::vector<Equipo*>& getEquipments() const;
};

#endif
