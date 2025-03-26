//
// Created by sierzegao on 3/26/2025.
//

#ifndef ROOM_H
#define ROOM_H

#include "RoomEntity.h"

class Room {
public:
    // my idea is that if a room is set too nullptr that means there's no room there.
    // we can check by just saying something like
    // if(room.northRoom == nullPtr) display there's no room.
    Room(RoomEntity entity, Room* n = nullptr, Room* e = nullptr, Room* s = nullptr, Room* w = nullptr);
    Room *northRoom, *eastRoom, *southRoom, *westRoom;
    RoomEntity *entity;
};



#endif //ROOM_H
