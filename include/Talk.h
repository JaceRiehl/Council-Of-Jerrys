#ifndef TALK_H
#define TALK_H

#include "CharacterAction.h"
#include "NPC.h"
#include "Exceptions.h"
/**
    @file Talk.h
    @author Nathan Tipper
    @date March 7, 2017
    @brief An action which talks to the subject.
*/
class Talk : public CharacterAction
{
    public:
        /**
            @brief A constructor for the talk class that takes a Character*.
        /*
        Talk(Character*);
        Talk(Character*, NPC*, Item* = nullptr);
        virtual ~Talk();

        bool execute();

    private:
        Item* item;
        const string dialogKey = "talk";
};

#endif // TALK_H
