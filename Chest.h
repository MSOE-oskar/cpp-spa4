//
// Created by sierzegao on 3/26/2025.
//

#ifndef CHEST_H
#define CHEST_H

#include "RoomEntity.h"
#include "Weapon.h"

enum ChestType {
    NORMAL,
    TRAPPED
};

class Chest : public RoomEntity {
public:
    // Probably based on the chest type, you set the name, description, and hint.
    Chest(ChestType type, Weapon containedItem, int coins);
    ChestType type;
    Weapon getWeapon();
    int getCoints();
private:
    Weapon containedItem;
    int coins;
};

#endif //CHEST_H
