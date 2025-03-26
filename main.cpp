//
// Created by sierzegao on 3/25/2025.
//

#include <iostream>
#include <vector>
#include "Room.h"
#include "Player.h"

void createRooms(Room* rooms);
// Weapon weapons[10] = {};
// Chest chests[10] = {};
// Enemy enemies[10] = {};
//
// Room rooms[100] = {
//     // need to figure out how we'll initialize the rooms
//     // im thinking we just create them first and set the pointers later
// };
Room *currentRoom = nullptr;
Player *player;

int main()
{
    // Hello Everyone
    // :D

    // game setup
    std::cout << "||==================================================================================================\n"
                 "||         8b    d8    db    8888P 888888     88''Yb 88   88 88b 88 88b 88 888888 88''Yb\n"
                 "||         88b  d88   dPYb     dP  88__       88__dP 88   88 88Yb88 88Yb88 88__   88__dP\n"
                 "||         88YbdP88  dP__Yb   dP   88''       88'Yb  Y8   8P 88 Y88 88 Y88 88''   88'Yb \n"
                 "||         88 YY 88 dP''''Yb d8888 888888     88  Yb `YbodP' 88  Y8 88  Y8 888888 88  Yb\n"
                 "||==================================================================================================\n"
                 "|| Looks like you need some help.\n"
                 "|| Don't worry, your only goal is to escape the maze.\n"
                 "|| You can move by clicking corresponding letter on keyboard E)ast, S)outh, N)orth, W)est.\n"
                 "|| In the maze there are a few dangers you need to be aware of.\n"
                 "|| The maze is littered with GIANT spiders that want to eat you,\n"
                 "|| they have soft footsteps and make a scraping sound as they walk.\n"
                 "|| If you encounter one you must fight them with a weapon or else succumb to their attacks.\n"
                 "|| If a weapon is near you there will be an option to P)ick it up.\n"
                 "|| Crowds of rats are another danger you can hear them scurrying around.\n"
                 "|| They won’t kill you right away, but they will cause you to lose health.\n"
                 "|| There are chests in the maze that can give you gold (bling sound)\n"
                 "|| but be careful a chest can also be a trap chest (buzz sound) that will spawn in a crowd of rats.\n"
                 "||==================================================================================================\n";

    // game loop

    // display current status

    // ask for input

    // perform action

    return 0;
}
