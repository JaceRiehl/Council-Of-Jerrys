#ifndef IAGENT_H
#define IAGENT_H

#include "Action.h"
#include "Character.h"
#include <string>
#include <iostream>

using namespace std;
/**
    @file IAgent.h
    @author Michel Martel
    @date March 4, 2017
    @brief IAgent acts as a container for future derivative character classes to take actions.
*/
class IAgent
{
    public:
        IAgent(){};
        virtual ~IAgent(){};
        virtual void takeAction(string action, Character* character) = 0;
};

#endif // IAGENT_H
