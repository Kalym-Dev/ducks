#include <iostream>
#include <random>
#include "Farm.h"
#ifndef GRISHA_HUNTER_H
#define GRISHA_HUNTER_H

class Hunter{
private:
    int m_max_duck_quantity;
    int m_min_duck_quantity;
    Farm* m_hunter_farm;
public:
    Hunter(int max_duck_quantity, int min_duck_quantity, Farm* hunter_farm): m_max_duck_quantity(max_duck_quantity), m_min_duck_quantity(min_duck_quantity), m_hunter_farm(hunter_farm){
        srand(time(0));
    }

    int getMaxduckquantity();
    int getMinduckquantity();

    void setMaxduckquantity(int max_duck_quantity);
    void setMinuckquantity(int min_duck_quantity);

    int getHuntingquantity();

    Farm* getHunterFarm() { return m_hunter_farm;}
    void setHunterFarm(Farm* farm) { m_hunter_farm = farm;}
};

#endif //GRISHA_HUNTER_H
