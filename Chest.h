//
// Created by sierzegao on 3/26/2025.
//

#ifndef CHEST_H
#define CHEST_H

#include "RoomEntity.h"
#include "Weapon.h"
#include "Enemy.h"

enum ChestType {
    NORMAL,
    TRAPPED
};

class Chest : public RoomEntity {
public:
    // Probably based on the chest type, you set the name, description, and hint.
    Chest(ChestType type, Weapon *containedWeapon, Enemy *containedEnemy, std::string hint, int coins) {
        this->description = "A golden chest";
        this->hint = hint;
        this->type = type;
        if (type == NORMAL) {
            //normal behavior
            this->name = "Normal Chest";
            this->containedWeapon = containedWeapon;
            this->containedEnemy = nullptr;
            this->coins = coins;

        } else {
            //trap behavior
            this->name = "Trap Chest";
            this->containedEnemy = containedEnemy;
            this->containedWeapon = nullptr;
            this->coins = coins;
        }
    } ;
    ChestType type;
    Enemy* getEnemy() {
        return containedEnemy;
    };
    Weapon* getWeapon() {
        return containedWeapon;
    };
    int getCoins() {
        return coins;
    };
private:
    Weapon *containedWeapon;
    Enemy *containedEnemy;
    int coins;
};

#endif //CHEST_H
