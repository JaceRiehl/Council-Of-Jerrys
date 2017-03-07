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
        Item(string itemName);
        bool operator==(const Item& itm) const;
        bool operator!=(const Item& itm) const;
        bool operator<(const Item& rhs) const;
        string getName() const;
        virtual ~Item(){};

    private:
        string name;
};

#endif // ITEM_H
