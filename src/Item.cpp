#include "Inventory.h"
#include "Item.h"
#include "Character.h"
#include "Action.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

Item::Item(string name) : name(name){}

string Item::getName() const
{
    return name;
}

bool Item::operator!=(const Item& itm) const
{
    if (this->name != itm.name)
        return true;
    return false;
}

bool Item::operator==(const Item& itm) const
{
    if (this->name == itm.name)
        return true;
    return false;
}
