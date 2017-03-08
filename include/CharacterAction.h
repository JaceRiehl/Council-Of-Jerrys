#ifndef CHARACTERACTION_H
#define CHARACTERACTION_H

#include "Action.h"
#include "NPC.h"

class CharacterAction : public Action
{
    public:
        CharacterAction(Character*);
        CharacterAction(Character*, NPC*);
        virtual ~CharacterAction();

        virtual bool execute() = 0;
        void setSubject(NPC*);
    protected:
        NPC* subject;
};

#endif // CHARACTERACTION_H
