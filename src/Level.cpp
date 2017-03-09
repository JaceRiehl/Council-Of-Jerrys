#include "Level.h"

Level::Level(PlayableCharacter& pc, string n, vector<Room> room)
{
    *jerry = pc;
    name = n;
}

string Level::run()
{
    string returned = "Level finished";
    state = RUNNING;


    int result = 0;
    while(result != -1)
    {
       result = rooms[result].run();
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
