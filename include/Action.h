#ifndef ACTION_H
#define ACTION_H
#include "Character.h"

class Action
{
    public:
        Action(Character*);
        virtual ~Action();
        virtual bool execute() = 0;

        const Character* getOwner() const;

    protected:
        Character* owner;

};

#endif // ACTION_H
