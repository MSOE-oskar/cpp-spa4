//
// Created by sierzegao on 3/26/2025.
//

#ifndef WEAPON_H
#define WEAPON_H

#include "RoomEntity.h"

class Weapon : public RoomEntity {
public:
    Weapon(std::string name, std::string description, int damage) {
        this->damage = damage;
        this->name = name;
        this->description = description;
    }

    int getDamage() {
        return damage;
    }

private:
    int damage;
};



#endif //WEAPON_H
