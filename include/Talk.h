#ifndef TALK_H
#define TALK_H

#include "CharacterAction.h"
#include "NPC.h"
#include "Window.h"
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
            @brief A constructor for the Talk class that can specify the subject
            and an item.
            @pre A Character* is given.
            @post The owner is set to the Character* and subject and item are also
            set, if given.
            @param Owner of the Action.
            @param Subject of the Action.
            @param Item to give to the owner.
            @return None.
        */
        Talk(Character*, NPC*, Item* = nullptr);
        virtual ~Talk();

        /**
            @brief Gets the dialog that relates to the Talk action and
            gives the Item to the owner if it exists.
            @pre Subject has been set.
            @post Subject's dialog is displayed and item is given, if it exists.
            @param None.
            @return If successful.
        */
        bool execute();

    private:
        Item* item;
        const string dialogKey = "talk";
};

#endif // TALK_H
