#include "Level.h"

Level::Level(string n, PlayableCharacter& pc, map<string, Room*> levelRooms, string openingText) : name(n), jerry(pc), rooms(levelRooms), openingMessage(openingText)
{
    nextRoom = "town";
}

string Level::run()
{
    string nextLevel = "mini_earth";

    state = RUNNING;

    Window window;
    //window.display(openingMessage, cout);

    while(nextRoom != terminatingString)
    {
        //window.display("Going into " + nextRoom, cout);
        Room* currentRoom = rooms[nextRoom];
        nextRoom = currentRoom->run();
    }

    return nextLevel;
}

int Level::returnState()
{
    return state;
}

string Level::getName()
{
    return name;
}
