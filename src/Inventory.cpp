#include "Inventory.h"
#include "Item.h"
#include  <vector>
#include <string>
#include <Exceptions.h>
#include <iostream>

using namespace std;

Inventory::Inventory(vector<Item> items) : items(items){}

void Inventory::addItem(Item item)
{
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (items[i].getName() == item.getName())
       {
            throw runtime_error("This item already exists");
       }
    }
    items.push_back(item);
}

bool Inventory::searchName(string name) const
{
   return true;
}
bool Inventory::searchItem(Item& item) const
{
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (items[i] == item)
            return true;
    }
    return false;
}

Item Inventory::getItem(string n) const
{
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (items[i].getName() == Item(n).getName())
            return items[i];
    }
    throw itemDoesNotExist("This item does not exist");
}

void Inventory::printItems() const
{
    for(unsigned int i = 0; i < items.size(); i++)
    {
        cout << items[i].getName() << endl;
    }
}

bool Inventory::operator==(Inventory inv)
{
    unsigned int invSize = 0;
    for (unsigned int i = 0; i < items.size(); i++)
    {
        for (unsigned int j = 0; j < items.size(); j++)
        {
            if (this->items[i] == inv.items[j])
                invSize += 1;
        }
    }
    if (invSize == items.size())
        return true;
    else
        return false;
}

bool Inventory::operator!=(Inventory inv)
{
    unsigned int invSize = 0;
    for (unsigned int i = 0; i < items.size(); i++)
    {
        for (unsigned int j = 0; j < items.size(); j++)
        {
            if (this->items[i] == inv.items[j])
                invSize += 1;
        }
    }
    if (invSize == items.size())
        return false;
    else
        return true;
}
