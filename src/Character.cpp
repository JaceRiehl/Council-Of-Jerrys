#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

Character::Character(string name) : name(name){}

Character::Character(string name, vector<Item> charInv) : name(name)
{
    for (unsigned i = 0; i < charInv.size(); i++)
    {
        inventory.push_back(charInv[i]);
    }
}

string Character::getName() const
{
    return name;
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

Item Character::getItem(string& n)
{

    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].getName() == Item(n).getName())
            return inventory[i];
    }
    throw runtime_error("This item does not exist");
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
    name = c.name;
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
            inventory[i] = c.inventory[i];
    }
}





