#include "Inventory.h"
#include "Item.h"
#include "Character.h"
#include "Action.h"
#include "Exceptions.h"
#include <string>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

Item::Item(string itemName)
{
    if (itemName.length() > 30)
        throw itemNameError("Item name too long to read; Ain't nobody got time for that!");

    else if (itemName.length() == 0)
        throw itemNameError("Do you really want your item to be the only one without a name?");
    else
    {
        transform(itemName.begin(), itemName.end(), itemName.begin(), ::tolower);
        name = itemName;
    }

}

string Item::getName() const
{
    return name;
}

bool Item::operator!=(const Item& itm) const
{
    if (name != itm.name)
        return true;
    return false;
}

bool Item::operator==(const Item& itm) const
{
    if (name == itm.name)
        return true;
    return false;
}

bool Item::operator<(const Item& rhs) const
{
    return this->name < rhs.name;
}
