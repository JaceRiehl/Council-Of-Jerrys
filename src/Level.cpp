#include "Level.h"

Level::Level(string n, PlayableCharacter& pc, map<string, Room*> levelRooms, string openingText) : name(n), jerry(pc), rooms(levelRooms), openingMessage(openingText){}

string Level::run()
{
    string returned = "Level finished";
    state = RUNNING;


    while(nextRoom != "exit")
    {
        Room* currentRoom = rooms[nextRoom];
        nextRoom = currentRoom->run();
    }

    state = FINISHED;
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
