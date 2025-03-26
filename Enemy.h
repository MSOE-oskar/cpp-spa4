//
// Created by sierzegao on 3/26/2025.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "RoomEntity.h"

class Enemy : public RoomEntity {
public:
    Enemy(std::string name, std::string description, std::string hint, int health, int damage, int coinsOnDeath);
    int getDamage();
    int getHealth();
    int getCoins();
    bool dealDamage(int damage); // returns true if dealing this much damage kills him
private:
    int health;
    int damage;
    int coinsOnDeath;
};



#endif //ENEMY_H
