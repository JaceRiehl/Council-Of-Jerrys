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

    #ifdef RELEASE

    ioInfo = new IOInfo();

    #endif
}

Action::~Action()
{}

const Character* Action::getOwner() const
{
    return owner;
}


bool Action::conditionsMet(vector<string> playerActions) const
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

                if(inv)
                {
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

bool Action::beenTaken(vector<string> playerActions) const
{
    for(const auto& str : playerActions)
    {
        if(str == key)
            return true;
    }

    return false;
}

void Action::giveItems(vector<string> playerActions)
{
    // RETURN IF ITEMS IS EMPTY
    if(itemsEmpty())
        return;

    // DO I EXIST IN THE PLAYERS LIST OF ACTIONS

    if(!beenTaken(playerActions))
    {
        for(const auto& item : items)
        {
            owner->addItem(item);
        }
    }
}
