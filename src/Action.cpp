#include "Action.h"
// ACTION CLASS
Action::Action(Character* actionOwner) : owner(actionOwner) {}

Action::~Action()
{
    delete owner;
}

const Character* Action::getOwner() const
{
    return owner;
}
