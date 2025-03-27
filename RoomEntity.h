//
// Created by sierzegao on 3/26/2025.
//



#ifndef ROOMENTITY_H
#define ROOMENTITY_H

#include <string>

class RoomEntity {
public:
    std::string getName() {
        return name;
    };
    std::string getDescription() {
        return description;
    };
    std::string getHint() {
        return hint;
    };
protected:
    std::string hint = "";
    std::string name = "";
    std::string description = "";
};

#endif //ROOMENTITY_H
