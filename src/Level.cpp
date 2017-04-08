#include "Level.h"

Level::Level(string n, PlayableCharacter* pc, map<string, Room*> levelRooms, string openingText) : key(n), jerry(pc), rooms(levelRooms), openingMessage(openingText)
{
    nextRoom = "town";
}

Level::Level(string levelKey, string startingRoom, map<string, Room*> levelRooms) : key(levelKey), nextRoom(startingRoom), rooms(levelRooms)
{
    #ifdef RELEASE

    ioInfo = new IOInfo();

    #else

    ioInfo = new IOInfo("../data/levelTestOutput", "");

    #endif // RELEASE
}

string Level::run(PlayableCharacter* player)
{
    state = RUNNING;

    Window window;
    window.display(openingMessage, ioInfo->getOutputStream());

    while(true)
    {
        if(rooms.find(nextRoom) == rooms.end())
            break;
        Room* currentRoom = rooms[nextRoom];
        XMLSaveData::Data.room = nextRoom.c_str();
        nextRoom = currentRoom->run(player);
    }

    return nextRoom;
}

void Level::setStartingRoom(string room)
{
    if(isAllAscii(room))
    {
        nextRoom = room;
        return;
    }

    cerr << "INVALID STRING!" << endl;

}

bool Level::isNotAscii(int c)
{
    return (c < 0) || (c >= 128);
}

bool Level::isAllAscii(string s)
{
    for(const auto& c : s)
    {
        if(isNotAscii(c))
            return false;
    }

    return true;
}

int Level::returnState()
{
    return state;
}

const string Level::getKey() const
{
    return key;
}
