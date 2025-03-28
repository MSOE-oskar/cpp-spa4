
#include "Player.h"

#include <iostream>

Player::Player() {
    this->coins = 0;
    this->health = 100;
    this->state = IDLE;
    this->weaponCount = 0;
    this->currentWeapon = nullptr;

    for (int i = 0; i < MAX_WEAPONS; ++i) {
        this->weapons[i] = nullptr;
    }
}

int Player::getCoins(){
    return coins;
}
void Player::setCoins(int coins){
    this->coins = coins;
}

int Player::getHealth(){
    return health;
}

void Player::setHealth(int health){
    this->health = health;
    if (health <= 0) {
        health = 0;
        state = DEAD; // Update player state if health reaches zero
    }
}

Weapon* Player::getWeapon() {
    return currentWeapon;
}

void Player::selectWeapon(int index){
    // indexed like this since the player enters 1 for the first weapon.
    if (index >= 1 && index <= weaponCount) {
        currentWeapon = weapons[index - 1];
        std::cout << "Weapon selected: " << currentWeapon->getName()
                  << " (Damage: " << currentWeapon->getDamage() << ")" << std::endl;
    } else {
        std::cerr << "Invalid weapon index! Choose between 1 and " << weaponCount << "." << std::endl;
    }
}

void Player::addWeapon(Weapon *weapon) {
    if (weaponCount < MAX_WEAPONS) {
        weapons[weaponCount++] = weapon;
        if (weaponCount == 1) {
            currentWeapon = weapon; // Equip the first weapon automatically
        }
        std::cout << "Weapon added: " << weapon->getName() << std::endl;
    } else {
        std::cerr << "Cannot carry more than " << MAX_WEAPONS << " weapons!" << std::endl;
    }
}

void Player::displayWeapons() {
    if (weaponCount == 0) {
        std::cout << "You have no weapons!" << std::endl;
        return;
    }

    std::cout << "Current Weapon Inventory: " << std::endl;
    // print weapon names and description
    for(int i = 0; i < weaponCount; i++){
        std::cout << "Weapon " << i+1 << ": " << weapons[i]->getName() << ": " << weapons[i]->getDescription() << std::endl;
    }
}

