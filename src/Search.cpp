#include "Search.h"

Search::Search(Character* actionOwner, string key, Room* room, string responseText, vector<string> actionConditions, vector<Item> actionItems)
        : RoomAction(actionOwner, key, room, responseText, actionConditions, actionItems)
{
    this->responseText = responseText;
}

Search::~Search() {}

bool Search::execute()
{

}

bool Search::execute(vector<string> playerActions)
{

}
