#include "Talk.h"

#include <iostream>

using std::cout;
using std::endl;

Talk::Talk(Character* actionOwner) : CharacterAction(actionOwner) {}

Talk::Talk(Character* actionOwner, Character* actionSubject, Item* item) : CharacterAction(actionOwner, actionSubject), item(item) {}

Talk::~Talk()
{
    if(item != nullptr)
        delete item;
}

bool Talk::execute()
{
    if(subject == nullptr)
        throw invalid_action("** Subject has not been set **");

    if(typeid(subject) == typeid(NPC))
    {
        NPC* npc = dynamic_cast<NPC*>(subject);
        cout << npc->getDialog(dialogKey) << endl;
    }

    if(item != nullptr)
        owner->addItem(*item);

    return true;
}
