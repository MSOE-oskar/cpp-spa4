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
        std::string rtn;
        if (northRoom != nullptr) rtn += northRoom->getRoomHint("north");
        if (eastRoom != nullptr) rtn += eastRoom->getRoomHint("east");
        if (southRoom != nullptr) rtn += southRoom->getRoomHint("south");
        if (westRoom != nullptr) rtn += westRoom->getRoomHint("west");
        if (weapon != nullptr) rtn += "There is a(n) " + weapon->getName() + " in the room\n";
        if (enemy != nullptr) rtn += enemy->getDescription() + "\n";
        if (chest != nullptr) rtn += "There is a chest in the room. \n";
        if (rtn.empty()) rtn += description;
        std::cout << rtn;
    }

    void displayOptions() const {
        std::string rtn = "Press ";

        // if there is an enemy in the room, they can't run away.
        if (enemy != nullptr) rtn += "F)ight enemy, ";
        else {
            if (northRoom != nullptr) rtn += "N)orth, ";
            if (eastRoom != nullptr) rtn += "E)ast, ";
            if (southRoom != nullptr) rtn += "S)outh, ";
            if (westRoom != nullptr) rtn += "W)est, ";
        }

        if (weapon != nullptr) rtn += "P)ickup weapon, ";
        if (chest != nullptr) rtn += "open C)hest, ";
        std::cout << rtn << "V)iew weapons, seL)ect weapon, or Q)uit.\n";
    }

    std::string getOptions() const {
        std::string rtn = "qvl"; // quit, inventory, select item is always an option.
        if (enemy != nullptr) rtn += "f";
        else
        {
            if (northRoom != nullptr) rtn += "n";
            if (eastRoom != nullptr) rtn += "e";
            if (southRoom != nullptr) rtn += "s";
            if (westRoom != nullptr) rtn += "w";
        }
        if (weapon != nullptr) rtn += "p";
        if (chest != nullptr) rtn += "c";

        return rtn;
    }

    // since there are multiple things that can give a hint,
    // but only one thing per room,
    // this makes it so we only have to call one function.
    std::string getRoomHint(std::string direction) const {
        if (this->chest != nullptr) return "You hear " + chest->getHint() + " to your " + direction + "\n";
        if (this->enemy != nullptr) return "You hear " + enemy->getHint() + " to your " + direction + "\n";
        // no hint
        return "";
    }
};



#endif //ROOM_H
