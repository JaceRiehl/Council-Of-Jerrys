#include "Level.h"

Level::Level(string n, map<string,Action> sitRes, vector<Situation> sit)
{
    situations = sit;
    name = n;
    situationResults = sitRes;
}

string Level::run()
{
    string returned;
    state = RUNNING;

    return returned;
}

State Level::returnState()
{
    return state;
}
