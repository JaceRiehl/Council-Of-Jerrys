#ifndef INVENTORY_H
#define INVENTORY_H

#include <Item.h>
#include <string>
#include <vector>

class Inventory
{
    public:
        Inventory(){};
        Inventory(vector<Item> items);
        virtual ~Inventory(){};
        void addItem(Item);
        bool search(string name) const;
        bool search(Item& item) const;
        Item getItem(string name) const;

    private:
        vector<Item> items;
};

#endif // INVENTORY_H
