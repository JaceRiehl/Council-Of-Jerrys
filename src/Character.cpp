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

bool Character::searchInventory(Item& itemSearch)
{
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i] == itemSearch)
            return true;
    }
    return false;
}

Item Character::getItem(string n)
{

    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].getName() == Item(n).getName())
            return inventory[i];
    }
    throw itemDoesNotExist("This item does not exist");
}

vector<Item> Character::getInventory() const
{
    return inventory;
}

void Character::printItems() const
{
    for(unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i].getName() << endl;
    }
}

void Character::operator=(Character& c)
{
    charName = c.charName;
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
            inventory[i] = c.inventory[i];
    }
}





