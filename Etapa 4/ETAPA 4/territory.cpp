#include "territory.h"

void Territory::addEquipment(Equipo *eq)
{
    equipments.push_back(eq);
}

const std::vector<Equipo*>& Territory::getEquipments() const
{
    return equipments;
}
