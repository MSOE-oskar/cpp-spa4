//
// Created by sierzegao on 3/26/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#define MAX_WEAPONS 5


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

    Weapon* getWeapon();
    void selectWeapon(int index);
    void addWeapon(Weapon *weapon);
    void displayWeapons();

private:
    int coins;
    int health;
    int weaponCount;
    Weapon* currentWeapon;
    Weapon* weapons[MAX_WEAPONS];
};


#endif //PLAYER_H
