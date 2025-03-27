//
// Created by sierzegao on 3/26/2025.
//



#ifndef ROOMENTITY_H
#define ROOMENTITY_H

#include <string>

class RoomEntity {
public:
    std::string getName();
    std::string getDescription();
    std::string getHint();
private:
    std::string hint = "";
    std::string name = "";
    std::string description = "";
};

#endif //ROOMENTITY_H
