//
// Created by sierzegao on 3/26/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"

enum PlayerState
{
    IDLE,
    FIGHTING,
    DEAD,
};

class Player {
public:
    Player();
    PlayerState state = IDLE;

    int getCoins();
    void setCoins(int coins);
    int getHealth();
    void setHealth(int health);

    Weapon getWeapon();
    void selectWeapon();
    void addWeapon();

private:
    int coins;
    int health;
    Weapon currentWeapon;
    std::vector<Weapon> weapons;
};



#endif //PLAYER_H
