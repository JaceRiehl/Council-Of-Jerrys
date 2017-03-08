#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H

#include "Character.h"
#include "IAgent.h"
#include "Exceptions.h"
#include "Action.h"
#include <map>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

/**
    @file PlayableCharacter.h
    @author Michel Martel & Nathan Tipper
    @date March 4, 2017
    @brief PlayableCharacter derives from the Character class and represents playable characters who can take actions.
*/
class PlayableCharacter : public Character, IAgent
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

        /**
            @brief setActions assigns the actions of the PlayableCharacter.
            @pre A map of string->Action* is given.
            @post The map is stored within the PlayableCharacter.
            @param The map that the players actions will be assigned to.
            @return None.
        */
        void setActions(map<string, Action*> actions);

        /**
            @brief takeAction activates an action given the key of the action.
            @pre The key of an action is given.
            @post The action has run its execute command.
            @param The key of the action.
            @return None.
        */
        void takeAction(string action);

    private:
        map<string, Action*> actions;
};

#endif // PLAYABLECHARACTER_H
