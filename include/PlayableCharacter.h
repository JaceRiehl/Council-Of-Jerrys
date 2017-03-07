#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H

#include "Character.h"
#include "IAgent.h"
#include "Action.h"
#include <map>
#include <string>
#include <iostream>

using namespace std;

/**
    @file PlayableCharacter.h
    @author Michel Martel & Nathan Tipper
    @date March 4, 2017
    @brief PlayableCharacter derives from the Character class and represents playable characters who can take actions.
*/
class PlayableCharacter : public Character
{
    public:
        /**
            @brief Constructor for the PlayableCharacter class which sets the name of the PlayableCharacter.
            @pre A string with length between 1 and 30 is given.
            @post The PlayableCharacter's name is set to the given string.
            @param Name of the PlayableCharacter.
            @return None.
        */
        PlayableCharacter(string);

        /**
            @brief Constructor for the PlayableCharacter class which sets the name of the PlayableCharacter.
            @pre A string with length between 1 and 30 is given.
            @post The PlayableCharacter's name is set to the given string.
            @param Name of the PlayableCharacter.
            @return None.
        */
        PlayableCharacter(string, vector<Item>);
        virtual ~PlayableCharacter(){};
        //void setActions(map<string, Action> actions);
        //void takeAction(string action, Character* character);

    private:
        //map<string, Action> actions;
};

#endif // PLAYABLECHARACTER_H
