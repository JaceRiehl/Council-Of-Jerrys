#include "Talk.h"

#include <iostream>

using std::cout;
using std::endl;

Talk::Talk(Character* actionOwner) : CharacterAction(actionOwner) {}

Talk::Talk(Character* actionOwner, NPC* actionSubject, Item* item) : CharacterAction(actionOwner, actionSubject), item(item) {}

Talk::~Talk()
{
    if(item != nullptr)
        delete item;
}

bool Talk::execute()
{
    if(subject == nullptr)
        throw invalid_action("** Subject has not been set **");

    cout << subject->getDialog(dialogKey) << endl;

    if(item != nullptr)
        owner->addItem(*item);

    return true;
}
