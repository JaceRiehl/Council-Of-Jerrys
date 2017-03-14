#include "Search.h"

Search::Search(Character* actionOwner, string key, Room* room, map<string, string> responseText, vector<string> actionConditions, vector<Item> actionItems)
        : RoomAction(actionOwner, key, room, responseText, actionConditions, actionItems)
{
    this->context = responseText;
}

Search::~Search() {}

bool Search::execute()
{

}

bool Search::execute(vector<string> playerActions)
{
    Window window;
    if(beenTaken(playerActions))
    {
        window.display(context[searchedKey], cout);
    }

    else if(!conditionsMet(playerActions))
    {
        window.display(context[conditionsNotMetKey], cout);
        return false;
    }

    else
    {
        window.display(context[conditionsMetKey], cout);
    }

    giveItems(playerActions);
    return true;
}
