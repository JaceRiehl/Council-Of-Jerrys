#include "Level.h"

Level::Level(PlayableCharacter &jerry, string n, vector<Room> room)
{
    openingMessage = openMes;
    roomResults = r;
    rooms = room;
    name = n;
}

string Level::run()
{
    string returned = "Level finished";
    state = RUNNING;


    int result = rooms[0]->run();
    while(result != -1)
    {
       result = rooms[result];
    }

    state = Finished;
    return returned;
}

State Level::returnState()
{
    return state;
}

string Level::getName()
{
    return name;
}
