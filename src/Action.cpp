#include "Action.h"
// ACTION CLASS
Action::Action(Character* actionOwner, string actionKey, vector<string> actionConditions, vector<Item> actionItems)
{
    if(actionOwner == nullptr)
        throw invalid_action("Owner is null.");

    owner = actionOwner;
    key = actionKey;
    conditions = actionConditions;
    items = actionItems;
}

Action::~Action()
{}

const Character* Action::getOwner() const
{
    return owner;
}

bool Action::conditionsMet(vector<string> playerActions)
{
    if(conditionsEmpty())
        return true;

    bool found;
    for(const auto& str1 : conditions)
    {
        found = false;
        for(const auto& str2 : playerActions)
        {
            if(str1 == str2)
            {
                found = true;
                break;
            }
        }

        if(!found)
            {
                const Inventory* inv = owner->getInventory();

                vector<Item> items = inv->getInventory();

                for(const auto& it : items)
                {
                    if(str1 == it.getName())
                    {
                        found = true;
                        break;
                    }
                }
            }

        if(!found)
            return false;


    }

    return true;
}

bool Action::conditionsEmpty() const
{
    if(conditions.size() == 0)
        return true;

    return false;
}

bool Action::itemsEmpty() const
{
    if(items.size() == 0)
        return true;

    return false;
}

void Action::giveItems(vector<string> playerActions)
{
    // RETURN IF ITEMS IS EMPTY
    if(itemsEmpty())
        return;

    // DO I EXIST IN THE PLAYERS LIST OF ACTIONS
    for(const auto& str : playerActions)
    {
        // IF SO, DONT GIVE ITEMS AGAIN!
        if(str == key)
            return;
    }

    for(const auto& item : items)
    {
        owner->addItem(item);
    }
}
