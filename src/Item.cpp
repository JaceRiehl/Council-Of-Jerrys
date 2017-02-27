#include "Inventory.h"
#include "Item.h"
#include "Character.h"
#include "Action.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

Item::Item(string name, map<string, int> mods, Action* action) : name(name), modifiers(mods){}

string Item::getName() const
{
    return name;
}
bool Item::executeAction(Character &c)
{
    return true;
}
