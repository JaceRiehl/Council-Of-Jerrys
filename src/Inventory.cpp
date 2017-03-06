#include "Inventory.h"
#include "Item.h"
#include  <vector>
#include <string>
#include <Exceptions.h>
#include <iostream>

using namespace std;

Inventory::Inventory(vector<Item> invItems)
{
    if (invItems.size() > 0)
    {
         for (unsigned i = 0; i < invItems.size(); i++)
            {
                items.push_back(invItems[i]);
            }
    }
    else
        throw inventoryEmpty("Your inventory is lonely without any items. Add some items.");
}

void Inventory::addItem(Item item)
{
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (items[i].getName() == item.getName())
       {
            items.insert(items.begin() + i, item);
            return;
       }
    }
    items.push_back(item);
}

bool Inventory::searchName(string name) const
{
   for (unsigned int i = 0; i < items.size(); i++)
    {
        if (items[i].getName() == name)
            return true;
    }
    return false;
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

vector <Item> Inventory::getInventory() const
{
    return items;
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
    unsigned int k = 0;
    if (inv.items.size() == items.size())
    {
        for (unsigned int i = 0; i < items.size(); i++)
        {
            for (unsigned int j = k; j < items.size(); j++)
            {
                if (this->items[i] == inv.items[j])
                {
                        invSize += 1;
                        k = 0;
                        break;
                }
                else
                    k += 1;
            }
        }
        if (invSize == items.size())
            return true;
    }
    else
        return false;
}

bool Inventory::operator!=(Inventory inv)
{
    unsigned int invSize = 0;
    if (inv.items.size() == items.size())
    {
        for (unsigned int i = 0; i < items.size(); i++)
        {
            for (unsigned int j = invSize; j < items.size(); j++)
            {
                if (this->items[i] == inv.items[j])
                {
                        invSize += 1;
                        break;
                }
            }
        }
        if (invSize == items.size())
            return false;
    }
    else
        return true;
}
