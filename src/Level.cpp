#include "Level.h"

Level::Level(string n, map<string,Action> sitRes, vector<Situation> sit)
{
    situations = sit;
    name = n;
    situationResults = sitRes;
}

string Level::run()
{
    string returned = "Situation over";
    state = RUNNING;
    for(int i = 0; i < situations.size(); i++)
    {
        while(situations[i]->run() != )

    }
    state = Finished;
    return returned;
}

State Level::returnState()
{
    return state;
}
