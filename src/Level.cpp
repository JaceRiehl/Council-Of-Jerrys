#include "Level.h"

Level::Level(string n, PlayableCharacter& pc, map<string, Room*> levelRooms, string openingText) : name(n), jerry(pc), rooms(levelRooms), openingMessage(openingText)
{
    nextRoom = "Jerry's Garage";
}

string Level::run()
{
    string returned = "Level finished";
    state = RUNNING;


    while(nextRoom != terminatingString)
    {
        Room* currentRoom = rooms[nextRoom];
        nextRoom = currentRoom->run();
    }

    return returned;
}

int Level::returnState()
{
    return state;
}

string Level::getName()
{
    return name;
}
