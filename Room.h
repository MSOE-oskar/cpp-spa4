//
// Created by sierzegao on 3/26/2025.
//

#ifndef ROOM_H
#define ROOM_H

#include "RoomEntity.h"
#include "Weapon.h"
#include "Enemy.h"
#include "Chest.h"

class Room {
public:
    // my idea is that if a room is set too nullptr that means there's no room there.
    // we can check by just saying something like
    // if(room.northRoom == nullPtr) display there's no room.
    explicit Room(Weapon *w = nullptr, Enemy *e = nullptr, Chest *c = nullptr) {
        northRoom = nullptr;
        eastRoom = nullptr;
        southRoom = nullptr;
        westRoom = nullptr;
    };
    Room *northRoom, *eastRoom, *southRoom, *westRoom;

    // things that can be in the room; nullptr means nothing is there
    Weapon *weapon;
    Enemy *enemy;
    Chest *chest;
    std::string description = "An empty room.\n";

    void displayRoom() const {
        // room description.
        std::cout << description;
    }

    void displayOptions() const {
        std::string rtn = "Press ";
        if (northRoom != nullptr) rtn += "N)orth, ";
        if (eastRoom != nullptr) rtn += "E)ast, ";
        if (southRoom != nullptr) rtn += "S)outh, ";
        if (westRoom != nullptr) rtn += "W)est, ";
        if (weapon != nullptr) rtn += "P)ickup weapon, ";
        if (enemy != nullptr) rtn += "F)ight enemy, ";
        if (chest != nullptr) rtn += "open C)hest, ";
        std::cout << rtn << "or Q)uit.\n";
    }

    std::string getOptions() const {
        std::string rtn = "q"; // quit is always an option.
        if (northRoom != nullptr) rtn += "n";
        if (eastRoom != nullptr) rtn += "e";
        if (southRoom != nullptr) rtn += "s";
        if (westRoom != nullptr) rtn += "w";
        if (weapon != nullptr) rtn += "p";
        if (enemy != nullptr) rtn += "f";
        if (chest != nullptr) rtn += "c";

        return rtn;
    }
};



#endif //ROOM_H
