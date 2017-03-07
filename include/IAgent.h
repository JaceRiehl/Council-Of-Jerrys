#ifndef IAGENT_H
#define IAGENT_H

#include "Action.h"
#include "Character.h"
#include <string>
#include <iostream>

using namespace std;

class IAgent
{
    public:
        IAgent(){};
        virtual ~IAgent(){};
        virtual void takeAction(string action, Character* character) = 0;
};

#endif // IAGENT_H
