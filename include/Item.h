#ifndef ITEM_H
#define ITEM_H

#include "Character.h"
#include "Action.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Character;

class Item
{
    public:
        Item() {}
        Item(string name, map<string, int> mods, Action* action);
        string getName() const;
        bool executeAction(Character &c);
        virtual ~Item(){};

    private:
        string name;
        map<string, int> modifiers;
        Action* action;
};

#endif // ITEM_H
