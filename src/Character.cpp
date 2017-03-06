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
        inventory = nullptr;
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
        inventory = new Inventory(charInv);
    }
}
Character::~Character()
{
    if (inventory == nullptr)
        delete inventory;
}


string Character::getName() const
{
    return charName;
}

Inventory Character::getInventory() const
{
    return *inventory;
}

void Character::operator=(Character& c)
{
    charName = c.charName;
    if (c.inventory == nullptr)
        inventory = nullptr;
    else
    {
        delete inventory;
        inventory = new Inventory(c.inventory->getInventory());
    }

    /*
    if (inventory->getInventory().size() > c.inventory->getInventory().size())
    {
        //for (unsigned int i = 0; i < c.inventory->getInventory().size(); i++)
        //{
            inventory = c.inventory;
        //}


         inventory->getInventory().erase(inventory->getInventory().begin() + c.inventory->getInventory().size(), inventory->getInventory().end());
    }
    else if (inventory->getInventory().size() < c.inventory->getInventory().size())
    {
        //for (unsigned int i = 0; i < inventory->getInventory().size(); i++)
        //{
            inventory = c.inventory;
        //}
        for (unsigned int i = inventory->getInventory().size(); i < c.inventory->getInventory().size(); i++)
        {
            inventory->getInventory().push_back(c.inventory->getInventory()[i]);
        }
    }
    else if (inventory->getInventory().size() == c.inventory->getInventory().size())
    {
        for (unsigned int i = 0; i < inventory->getInventory().size(); i++)
        {
            inventory = c.inventory;
        }
    }
    else if (c.inventory == nullptr)
    {
        inventory = nullptr;
    }
    */
}





