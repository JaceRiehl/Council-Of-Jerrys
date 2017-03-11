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
