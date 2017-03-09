#ifndef ACTION_H
#define ACTION_H
#include "Character.h"
#include "Exceptions.h"

class Action
{
    public:
        /**
            @brief A constructor for the Action class that takes a Character*.
            @pre A valid character is given.
            @post The owner of the Action is set to the Character.
            @param The Character who will be the owner of the Action.
            @return None.
        */
        Action(Character*);
        virtual ~Action();

        /**
            @brief execute allows all derived classes of Action to implement their own execute behaviour.
            @pre None.
            @post None.
            @param None.
            @return None.
        */
        virtual bool execute() = 0;

        /**
            @brief Accessor method for the owner of the Action.
            @pre None.
            @post The owner of the Action is returned.
            @param None.
            @return The owner of the Action.
        */
        const Character* getOwner() const;

    protected:
        Character* owner;

};

#endif // ACTION_H
