//
// Created by sierzegao on 3/26/2025.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "RoomEntity.h"

class Enemy : public RoomEntity {
public:
    Enemy(std::string name, std::string description, std::string hint, int health, int damage, int coinsOnDeath) {

        this->name = name;
        this->description = description;
        this->hint = hint;

        this->health = health;
        this->damage = damage;
        this->coinsOnDeath = coinsOnDeath;
    };
    int getDamage() {
        return damage;
    };
    int getHealth() {
        return health;
    };
    int getCoins() {
        return coinsOnDeath;
    };
    // returns true if dealing this much damage kills him
    bool dealDamage(int damage) {
        if (damage >= health) {
            return true;
        }
        health -= damage;
        return false;
    };
private:
    int health;
    int damage;
    int coinsOnDeath;
};



#endif //ENEMY_H
