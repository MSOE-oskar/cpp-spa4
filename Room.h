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
    Room(Weapon *w, Enemy *e, Chest *c);
    Room *northRoom = nullptr, *eastRoom = nullptr, *southRoom = nullptr, *westRoom = nullptr;

    // things that can be in the room; nullptr means nothing is there
    Weapon *weapon = nullptr;
    Enemy *enemy = nullptr;
    Chest *chest = nullptr;
};



#endif //ROOM_H
