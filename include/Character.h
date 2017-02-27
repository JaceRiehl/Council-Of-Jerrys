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
        Character(string name, Inventory* inventory, map<string, Action*> actions);
        string getName() const;
        bool searchInventory(Item&)const;
        Item getItem(string&) const;
        void printItems() const;
        bool executeAction(string&, Character&);
        virtual ~Character(){};
        enum state {dead, alive, running, hiding, frozen};

    protected:

    private:
        string name;
        Inventory* inventory;
        map<string, Action*> actions;
        state status;
};

#endif // CHARACTER_H
