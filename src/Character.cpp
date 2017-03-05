#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <Exceptions.h>

using namespace std;

Character::Character(string name)
{
    if (name.length() > 30)
        throw characterNameError("This is an English game. No one has a name that long!");

    else if (name.length() == 0)
        throw characterNameError("You gotta have a name; all the cool kids have one!");
    else
        charName = name;
}

Character::Character(string name, vector<Item> charInv)
{
    if (name.length() > 30)
        throw characterNameError("This is an English game. No one has a name that long!");

    else if (name.length() == 0)
        throw characterNameError("You gotta have a name; all the cool kids have one!");

    else
    {
        charName = name;
        for (unsigned i = 0; i < charInv.size(); i++)
        {
            inventory.push_back(charInv[i]);
        }
    }
}

string Character::getName() const
{
    return charName;
}

vector<Item> Character::getInventory() const
{
    return inventory;
}

void Character::operator=(Character& c)
{
    charName = c.charName;
    if (inventory.size() > c.inventory.size())
    {
        for (unsigned int i = 0; i < c.inventory.size(); i++)
        {
                inventory[i] = c.inventory[i];
        }
        inventory.erase(inventory.begin() + c.inventory.size(), inventory.end());
    }
    else if (inventory.size() < c.inventory.size())
    {
        for (unsigned int i = 0; i < inventory.size(); i++)
        {
            inventory[i] = c.inventory[i];
        }
        for (unsigned int i = inventory.size(); i < c.inventory.size(); i++)
        {
            inventory.push_back(c.inventory[i]);
        }
    }
    else if (inventory.size() == c.inventory.size())
    {
        for (unsigned int i = 0; i < inventory.size(); i++)
        {
            inventory[i] = c.inventory[i];
        }
    }
}





