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
    window.display(subject->getDialog(defaultKey), cout);

    return true;
}

bool Talk::execute(vector<string> characterActions)
{
    if(!subject)
        throw invalid_action("** Subject has not been set **");

    string conditionsNotMetErrorMessage = subject->getName() + " will not talk to you.";

    if(!conditionsMet(characterActions))
        throw invalid_action(conditionsNotMetErrorMessage.c_str());

    Window window;
    window.display(subject->getDialog(defaultKey), cout);

    giveItems(characterActions);

    return true;
}


