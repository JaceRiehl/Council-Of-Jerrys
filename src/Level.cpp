#include "Level.h"

Level::Level(string n, PlayableCharacter* pc, map<string, Room*> levelRooms, string openingText) : key(n), jerry(pc), rooms(levelRooms), openingMessage(openingText)
{
    nextRoom = "town";
}

Level::Level(string levelKey, string startingRoom, map<string, Room*> levelRooms) : key(levelKey), nextRoom(startingRoom), rooms(levelRooms) {}

string Level::run()
{
    state = RUNNING;

    Window window;
    //window.display(openingMessage, cout);

    while(true)
    {
        if(rooms.find(nextRoom) == rooms.end())
            break;
        Room* currentRoom = rooms[nextRoom];
        nextRoom = currentRoom->run();
    }

    return nextRoom;
}

int Level::returnState()
{
    return state;
}

const string Level::getKey() const
{
    return key;
}
