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
    /*
    if (inventory == nullptr)
        delete inventory;
        */
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

    if (c.inventory == false)
    {
        delete inventory;
        inventory = nullptr;
    }
    else
    {
        delete inventory;
        inventory = new Inventory(c.inventory->getInventory());
    }
}





