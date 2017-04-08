#include "Search.h"

Search::Search(Character* actionOwner, string key, Room* room, map<string, string> responseText, vector<string> actionConditions, vector<Item> actionItems)
        : RoomAction(actionOwner, key, room, responseText, actionConditions, actionItems)
{
    this->context = responseText;

    #ifdef DEBUG

    ioInfo = new IOInfo("../data/searchTestOutput", "");

    #endif // DEBUG
}

Search::~Search() {}

bool Search::execute(vector<string> playerActions)
{
    Window window;
    if(beenTaken(playerActions))
    {
        window.display(context[searchedKey], ioInfo->getOutputStream());
    }

    else if(!conditionsMet(playerActions))
    {
        window.display(context[conditionsNotMetKey], ioInfo->getOutputStream());
    }

    else if(conditionsMet(playerActions))
    {
        window.display(context[conditionsMetKey], ioInfo->getOutputStream());
        giveItems(playerActions);
        return true;
    }

    else
    {
        window.display(context[defaultKey], cout);
    }

    return false;
}
