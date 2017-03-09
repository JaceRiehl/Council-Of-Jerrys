#include "Action.h"
// ACTION CLASS
Action::Action(Character* actionOwner)
{
    if(actionOwner == nullptr)
        throw invalid_action("Owner is null.");

    owner = actionOwner;
}

Action::~Action()
{
    delete owner;
}

const Character* Action::getOwner() const
{
    return owner;
}
