#ifndef CHARACTER_H
#define CHARACTER_H

#include "Inventory.h"
#include "Item.h"
#include "Action.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Inventory;
class Item;

class Character
{
    public:
        Character(string name);
        Character(string name, vector<Item> charInv);
        string getName() const;
        bool searchInventory(Item&);
        Item getItem(string&);
        vector<Item> getInventory() const;
        void printItems() const;
        void operator=(Character& c);
        virtual ~Character(){};

    private:
        string name;
        vector<Item> inventory;
};

#endif // CHARACTER_H
