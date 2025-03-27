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
    Chest(ChestType type, std::string hint, int coins) {
        if (type == NORMAL) {
            //normal behavior
            //this->containedItem = containedItem;
            this->coins = coins;
        } else {
            //trap behavior
            //this->containedItem = containedItem;
            this->coins = coins;
            //spawn rats
        }
    } ;
    ChestType type;
    Weapon getWeapon() {
        return containedItem;
    };
    int getCoins() {
        return coins;
    };
private:
    Weapon containedItem;
    int coins;
};

#endif //CHEST_H
