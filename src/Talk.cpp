#include "Talk.h"

#include <iostream>

using std::cout;
using std::endl;

Talk::Talk(Character* actionOwner, string key, NPC* actionSubject, vector<string> actionConditions, vector<Item> actionItems)
                                        : CharacterAction(actionOwner, key, actionSubject, actionConditions, actionItems) {}

Talk::~Talk()
{
}

bool Talk::execute()
{
    if(subject == nullptr)
        throw invalid_action("** Subject has not been set **");

    Window window;
    window.display(subject->getDialog(conditionsMetKey), cout);

    return true;
}

bool Talk::execute(vector<string> characterActions)
{
    if(!subject)
        throw invalid_action("** Subject has not been set **");


    Window window;
    if(beenTaken(characterActions))
    {
        window.display(subject->getDialog(talkedKey), cout);
    }

    else if(!conditionsMet(characterActions))
    {
        window.display(subject->getDialog(conditionsNotMetKey), cout);
    }

    else if(conditionsMet(characterActions))
    {
        window.display(subject->getDialog(conditionsMetKey), cout);
    }

    giveItems(characterActions);

    return true;
}


