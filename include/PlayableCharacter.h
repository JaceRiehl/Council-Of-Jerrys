#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H

#include "Character.h"
#include "IAgent.h"
#include "Action.h"
#include <map>
#include <string>
#include <iostream>

using namespace std;

class PlayableCharacter : public Character
{
    public:
        PlayableCharacter(string);
        PlayableCharacter(string, vector<Item>);
        virtual ~PlayableCharacter(){};
        //void setActions(map<string, Action> actions);
        //void takeAction(string action, Character* character);

    private:
        //map<string, Action> actions;
};

#endif // PLAYABLECHARACTER_H
