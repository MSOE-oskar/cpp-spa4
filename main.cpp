//
// Created by sierzegao on 3/25/2025.
//

#include <iostream>
#include <vector>
#include "Room.h"
#include "Player.h"

void setupRooms();
Room* performAction(char input);

void pickupItemInCurrentRoom();
void fightEnemyInCurrentRoom();
void openChestInCurrentRoom();

Weapon weapons[4] = {
    Weapon("Stick", "A small piece of a tree, with a small carved top, does very little damage", 10),
    Weapon("Dagger", "Small knife used by ancient ninja masters", 20),
    Weapon("Sword", "Crafted with iron from the depths of the forbidden caves", 30),
    Weapon("Magical Wand", "A wand crafted by the almighty Grand Wizard, contains years of magical knowledge", 40)
};

Enemy enemies[6] = {
    Enemy("Rats", "A crowd of hungry rats appeared", "sounds of scurrying around", 45, 10,5),
    Enemy("Racoon", "A demon of the night a racoon is here", "sounds of tiny paws around", 45, 10,5),
    Enemy("Possum", "A possum will help you play dead", "sounds of a tail whipping around", 45, 10,5),
    Enemy("Spider", "A giant spider has found you ", "sounds of soft footsteps and scraping", 100, 20,20),
    Enemy("Spider", "A giant spider has found you ", "sounds of soft footsteps and scraping", 100, 20,20),
    Enemy("Rats", "A crowd of hungry rats appeared", "sounds of scurrying around", 45, 10,5),
};
Chest chests[3] = {
    Chest(NORMAL, &weapons[1], nullptr, "Bling sounds of chest",  50),
    Chest(TRAPPED, nullptr, &enemies[0], "Buzz sounds of chest", 0),
    Chest(TRAPPED, nullptr, &enemies[3], "Buzz sounds of chest", 0)
};
//
// coords: y  x
Room rooms[5][5] = {
    {Room(), Room(), Room(), Room(), Room()},
    {Room(), Room(), Room(), Room(), Room()},
    {Room(), Room(), Room(), Room(), Room()},
    {Room(), Room(), Room(), Room(), Room()},
    {Room(), Room(), Room(), Room(), Room()}
};
Room *currentRoom = nullptr;
Player *player;


int main()
{
    // Hello Everyone
    // :D

    // game setup
    std::cout << "||==================================================================================================\n"
                 "||         8b    d8    db    8888P 888888     88''Yb 88   88 88b 88 88b 88 888888 88''Yb            \n"
                 "||         88b  d88   dPYb     dP  88__       88__dP 88   88 88Yb88 88Yb88 88__   88__dP            \n"
                 "||         88YbdP88  dP__Yb   dP   88''       88'Yb  Y8   8P 88 Y88 88 Y88 88''   88'Yb             \n"
                 "||         88 YY 88 dP''''Yb d8888 888888     88  Yb `YbodP' 88  Y8 88  Y8 888888 88  Yb            \n"
                 "||==================================================================================================\n"
                 "|| Looks like you need some help. Don't worry, your only goal is to escape the maze. \n"
                 "|| You can move by clicking corresponding letter on keyboard E)ast, S)outh, N)orth, W)est. \n"
                 "|| In the maze there are a few dangers you need to be aware of. \n"
                 "|| The maze is littered with GIANT spiders that want to eat you, \n"
                 "|| they have soft footsteps and make a scraping sound as they walk. \n"
                 "|| If you encounter one you must fight them with a weapon or else succumb to their attacks. \n"
                 "|| If a weapon is near you there will be an option to P)ick it up. \n"
                 "|| Crowds of rats are another danger you can hear them scurrying around. \n"
                 "|| A racoon might appear you can hear their tiny paws. \n"
                 "|| A possum can also show up but its tail whipping gives it away. \n"
                 "|| They won't kill you right away, but they will cause you to lose health. \n"
                 "|| There are chests in the maze that can give you gold (bling sound) \n"
                 "|| but be careful a chest can also be a trap chest (buzz sound) that will spawn in a crowd of rats. \n"
                 "||==================================================================================================\n";

    char input;
    player = new Player();
    setupRooms();
    currentRoom = &rooms[0][2];

    // game loop
    do {
        // display current status
        currentRoom->displayRoom();

        // ask for input
        currentRoom->displayOptions();
        std::cin >> input;
        input = std::tolower(input);

        // perform action
        // we're getting the new room to move into from the action.
        // some actions keep you in the same room.
        Room *newRoom = performAction(input);

        // update current room
        currentRoom = newRoom;
    } while (input != 'q' && player->state != DEAD);

    return 0;
}

// assign items to rooms randomly, for the start of the game
void setupRooms() {
    //
    // FIRST ROW
    // 0, 0
    rooms[0][0].eastRoom = &rooms[0][1];
    rooms[0][0].chest = &chests[0];
    // 0, 1
    rooms[0][1].westRoom = &rooms[0][0];
    rooms[0][1].eastRoom = &rooms[0][2];
    // 0, 2
    rooms[0][2].westRoom = &rooms[0][1];
    rooms[0][2].southRoom = &rooms[1][2];
    rooms[0][2].weapon = &weapons[0];
    // 0, 3
    rooms[0][3].eastRoom = &rooms[0][4];
    rooms[0][3].chest = &chests[1];
    // 0, 4
    rooms[0][4].westRoom = &rooms[0][3];
    rooms[0][4].southRoom = &rooms[1][4];
    //
    // SECOND ROW
    // 1, 0
    rooms[1][0].southRoom = &rooms[2][0];
    rooms[1][0].eastRoom = &rooms[1][1];
    rooms[1][0].enemy = &enemies[1];
    // 1, 1
    rooms[1][1].southRoom = &rooms[2][1];
    rooms[1][1].westRoom = &rooms[1][0];
    // 1, 2
    rooms[1][2].northRoom = &rooms[0][2];
    rooms[1][2].eastRoom = &rooms[1][3];
    // 1, 3
    rooms[1][3].eastRoom = &rooms[1][4];
    rooms[1][3].westRoom = &rooms[1][2];
    // 1, 4
    rooms[1][4].northRoom = &rooms[0][4];
    rooms[1][4].southRoom = &rooms[2][4];
    rooms[1][4].westRoom = &rooms[1][3];
    //
    // THIRD ROW
    // 2, 0
    rooms[2][0].northRoom = &rooms[1][0];
    rooms[2][0].weapon = &weapons[2];
    // 2, 1
    rooms[2][1].northRoom = &rooms[1][1];
    rooms[2][1].eastRoom = &rooms[2][2];
    rooms[2][1].southRoom = &rooms[3][1];
    // 2, 2
    rooms[2][2].eastRoom = &rooms[2][3];
    rooms[2][2].westRoom = &rooms[2][1];
    // 2, 3
    rooms[2][3].eastRoom = &rooms[2][4];
    rooms[2][3].southRoom = &rooms[3][3];
    rooms[2][3].westRoom = &rooms[2][2];
    // 2, 4
    rooms[2][4].northRoom = &rooms[1][4];
    rooms[2][4].southRoom = &rooms[3][4];
    rooms[2][4].westRoom = &rooms[2][3];
    rooms[2][4].enemy = &enemies[1];
    //
    // FOURTH ROW
    // 3, 0
    rooms[3][0].eastRoom = &rooms[3][1];
    rooms[3][0].southRoom = &rooms[4][0];
    // 3, 1
    rooms[3][1].northRoom = &rooms[2][1];
    rooms[3][1].westRoom = &rooms[3][0];
    // 3, 2
    rooms[3][2].eastRoom = &rooms[3][3];
    rooms[3][2].enemy = &enemies[5];
    // 3, 3
    rooms[3][3].northRoom = &rooms[2][3];
    rooms[3][3].westRoom = &rooms[3][2];
    // 3, 4
    rooms[3][4].northRoom = &rooms[2][4];
    rooms[3][4].southRoom = &rooms[4][4];
    //
    // FIFTH ROW
    // 4, 0
    rooms[4][0].northRoom = &rooms[3][0];
    rooms[4][0].eastRoom = &rooms[4][1];

    // 4, 1
    rooms[4][1].eastRoom = &rooms[4][2];
    rooms[4][1].westRoom = &rooms[4][0];
    // 4, 2
    rooms[4][2].westRoom = &rooms[4][1];
    rooms[4][0].chest = &chests[2];
    // TODO: end room
    // 4, 3
    rooms[4][3].eastRoom = &rooms[4][4];
    rooms[4][3].weapon = &weapons[3];
    // 4, 4
    rooms[4][4].northRoom = &rooms[3][4];
    rooms[4][4].westRoom = &rooms[4][3];
    rooms[4][4].enemy = &enemies[4];
}

Room* performAction(char input) {
    // invalid option.
    if (currentRoom->getOptions().find(input) == std::string::npos) {
        std::cout << "|| Invalid Option. Please try again\n";
        return currentRoom;
    }

    // all options
    switch (input){
        case 'n':
            return currentRoom->northRoom;
        case 'e':
            return currentRoom->eastRoom;
        case 's':
            return currentRoom->southRoom;
        case 'w':
            return currentRoom->westRoom;
        case 'p':
            pickupItemInCurrentRoom();
            break;
        case 'f':
            fightEnemyInCurrentRoom();
            break;
        case 'c':
            openChestInCurrentRoom();
            break;
    }

    // if we pick up weapon, fight enemy, or open chest, we stay in current room.
    return currentRoom;
}

void pickupItemInCurrentRoom() {
    player->addWeapon(currentRoom->weapon);
    std :: cout << "Picked up " << currentRoom -> weapon->getName() << ".\n";
    currentRoom->weapon = nullptr;
};

void fightEnemyInCurrentRoom() {
    // dealDamage returns true if the enemy is alive
    // in hindsight there should be an EnemyState like PlayerState
    // but it's okay
    Enemy *currentEnemy = currentRoom->enemy;
    player->state = FIGHTING;
    bool enemyDead = false;

    // if player has no weapon they should die.
    if (player->getWeapon() == nullptr) {
        player->state = DEAD;
    }

    while (!enemyDead && player->state == FIGHTING) {
        // damage enemy
        enemyDead = currentEnemy->dealDamage(player->getWeapon()->getDamage());
        if (!enemyDead) {
            std::cout << "You dealt damage to the " << currentEnemy->getName() << " but the they are not dead yet. Keep fighting.\n";
            // damage player
            player->setHealth(player->getHealth() - currentEnemy->getDamage());
            std::cout <<"You got hit - shake it off you can still do this.\n";
        }
    };

    // if enemy died, add the gold to the player and remove from room
    if (enemyDead) {
        player->setCoins(player->getCoins() + currentEnemy->getCoins());
        player->state = IDLE;
        currentRoom->enemy = nullptr;
        std::cout << "You killed the beast, bested them in battle.\n";

    } else if (player->state == DEAD) {
        std::cout << "You died in battle. The villager cry for you. They still want their freedom\n";
    }
};

void openChestInCurrentRoom()
{
    std::cout << "You opened a "<< currentRoom->chest->getName() << "\n";
    if (currentRoom->chest->type == TRAPPED) {
        //assigns first rat as enemy in room
        currentRoom->enemy = currentRoom->chest->getEnemy();
        //removes trap chest
        currentRoom->chest = nullptr;
    } else {
        //adds weapon to room
        currentRoom->weapon = currentRoom->chest->getWeapon();
        //do I have to do something with gold
        player->setCoins(player->getCoins() + currentRoom->chest->getCoins());
        //remove normal chest
        currentRoom->chest = nullptr;
    }
};


