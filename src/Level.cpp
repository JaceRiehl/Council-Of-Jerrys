#include "Level.h"

Level::Level(string n, vector<Situation> sit, string openMes)
{
    openingMessage = openMes;
    situations = sit;
    name = n;
}

string Level::run()
{
    string returned = "Situation over";
    state = RUNNING;
    cout << openingMessage << endl;

    for(int i = 0; i < situations.size(); i++)
    {
        //string result, sitRes;
        //result = situations[i]->run();
        situationResults.push_back(situations[i]->run());

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
