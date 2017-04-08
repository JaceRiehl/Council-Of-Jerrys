#include "Talk.h"

#include <iostream>

using std::cout;
using std::endl;

Talk::Talk(Character* actionOwner, string key, NPC* actionSubject, vector<string> actionConditions, vector<Item> actionItems)
                                        : CharacterAction(actionOwner, key, actionSubject, actionConditions, actionItems)
{
    #ifdef DEBUG

    ioInfo = new IOInfo("../data/talkTestOutput", "");

    #endif
}

Talk::~Talk() {}

bool Talk::execute()
{


    return true;
}

bool Talk::execute(vector<string> characterActions)
{
    if(!subject)
        throw invalid_action("** Subject has not been set **");


    Window window;


    if(beenTaken(characterActions))
    {
        window.display(subject->getDialog(talkedKey), ioInfo->getOutputStream());
    }

    else if(!conditionsMet(characterActions))
    {
        window.display(subject->getDialog(conditionsNotMetKey), ioInfo->getOutputStream());
    }

    else if(conditionsMet(characterActions))
    {
        window.display(subject->getDialog(conditionsMetKey), ioInfo->getOutputStream());
        giveItems(characterActions);
        return true;
    }

    else
    {
        window.display(subject->getDialog(defaultKey), ioInfo->getOutputStream());
    }

    return false;
}


