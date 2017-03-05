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
        vector<Item> getInventory() const;
        void operator=(Character& c);
        virtual ~Character(){};

    private:
        string charName;
        vector<Item> inventory;
};

#endif // CHARACTER_H
