#include "Inventory.h"
#include "Item.h"
#include <Exceptions.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Inventory::Inventory()
{
    numberOfItems = 0;

    #ifdef RELEASE

    ioInfo = new IOInfo();

    #else

    ioInfo = new IOInfo("../data/inventoryTestOutput", "");

    #endif // RELEASE
}

Inventory::Inventory(vector<Item> invItems)
{
    if (invItems.size() > 0)
    {
        for (unsigned i = 0; i < invItems.size(); i++)
        {
            items.push_back(invItems[i]);
            numberOfItems++;
        }
        sort(items.begin(), items.end());
    }
    else
        throw inventoryEmpty("Your inventory is lonely without any items. Add some items.");

    #ifdef RELEASE

    ioInfo = new IOInfo();

    #else

    ioInfo = new IOInfo("../data/inventoryTestOutput", "");

    #endif // RELEAS
}

void Inventory::addItem(Item item)
{
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (items[i].getName() == item.getName())
       {
            items.insert(items.begin() + i, item);
            saveItems();
            numberOfItems++;
            return;
       }
    }
    saveItems();
    items.push_back(item);
    sort(items.begin(), items.end());
    numberOfItems++;
}

void Inventory::removeItem(Item item)
{
    for(unsigned int i = 0; i < items.size(); i++)
    {
        if (items[i].getName() == item.getName())
        {
              items.erase(items.begin()+i);
              saveItems();
              numberOfItems--;
              return;
        }
    }
    throw itemDoesNotExist("This item does not exist");
}

bool Inventory::searchName(string name) const
{

    transform(name.begin(), name.end(), name.begin(), ::tolower);
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
    unsigned int k = 0;
    unsigned int m = 1;
    unsigned int counter = 1;

    stringstream sstream;
    string clearString = "";
    Window window;
    vector<string> formattedItems;

    do
    {
        for(unsigned int j = m; j < items.size(); j++)
        {
            if (items[k] == items[j])
                counter += 1;
        }

        sstream.str(clearString);
        sstream << counter << " X " << items[k].getName() << "  ";
        formattedItems.push_back(sstream.str());
        k = k + counter;
        m = m + counter;
        if(m > items.size() && k < items.size())
        {
            counter = 1;
            sstream.str(clearString);
            sstream << counter << "X " << items[k].getName() << "  ";
            formattedItems.push_back(sstream.str());
            break;
        }
        counter = 1;
    }while(k < items.size());

    window.display(formattedItems, ioInfo->getOutputStream());
}

bool Inventory::operator==(const Inventory inv) const
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

unsigned int Inventory::getSize() const
{
    return numberOfItems;
}

void Inventory::saveItems()
{
    vector<string> itemNames;
    for(const auto& itm : items)
    {
        itemNames.push_back(itm.getName());
    }

    XMLSaveData::Data.inventoryItems = itemNames;
}
