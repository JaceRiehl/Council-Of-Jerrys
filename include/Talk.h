#ifndef TALK_H
#define TALK_H

#include "CharacterAction.h"
#include "NPC.h"
#include "Exceptions.h"
#include <typeinfo>

class Talk : public CharacterAction
{
    public:
        Talk(Character*);
        Talk(Character*, Character*, Item* = nullptr);
        virtual ~Talk();

        bool execute();

    private:
        Item* item;
        const string dialogKey = "talk";
};

#endif // TALK_H
