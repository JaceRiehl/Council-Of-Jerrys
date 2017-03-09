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
    @brief IAgent is an interface for classes that use actions.
*/
class IAgent
{
    public:
        virtual void takeAction(string) = 0;
        virtual void setActions(map<string, Action*>) = 0;

};

#endif // IAGENT_H
