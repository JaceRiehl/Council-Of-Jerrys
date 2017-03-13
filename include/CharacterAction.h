#ifndef CHARACTERACTION_H
#define CHARACTERACTION_H

#include "Action.h"
#include "NPC.h"

class CharacterAction : public Action
{
    public:
        /**
            @brief A constructor for the Action class that takes a Character* and NPC*
            @pre A non-null Character* is given.
            @post The owner of the Action is set to the Character and the subject
            is set to the NPC.
            @param The Character who will be the owner of the Action.
            @param The subject of the Action.
            @return None.
        */
        CharacterAction(Character*, string, NPC*, vector<string> = {}, vector<Item> = {});
        virtual ~CharacterAction();

        virtual bool execute() = 0;

        /**
            @brief Sets the subject of the Action.
            @pre None.
            @post The subject is set to the NPC*
            @param The subject of the Action.
            @return None.
        */
        void setSubject(NPC*);
    protected:
        NPC* subject;
};

#endif // CHARACTERACTION_H
