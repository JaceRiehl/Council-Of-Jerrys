#ifndef CHARACTERACTION_H
#define CHARACTERACTION_H

#include "Action.h"

class CharacterAction : public Action
{
    public:
        CharacterAction();
        CharacterAction(string);
        CharacterAction(string, string);
        CharacterAction(string, string, string);
        virtual ~CharacterAction();

        virtual bool execute() = 0;
        void setSubject(string);
    protected:
        string subject;
};

#endif // CHARACTERACTION_H
