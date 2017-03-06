#include "Action.h"

Action::Action()
{
    name = "";
}

Action::Action(string name) : name(name) {}

Action::Action(string name, string owner) : name(name), owner(owner) {}
