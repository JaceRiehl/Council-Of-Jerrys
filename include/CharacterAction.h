#ifndef CHARACTERACTION_H
#define CHARACTERACTION_H

#include "Action.h"

class CharacterAction : public Action
{
    public:
        CharacterAction(Character*);
        CharacterAction(Character*, Character*);
        virtual ~CharacterAction();

        virtual bool execute() = 0;
        void setSubject(Character*);
    protected:
        Character* subject;
};

#endif // CHARACTERACTION_H
