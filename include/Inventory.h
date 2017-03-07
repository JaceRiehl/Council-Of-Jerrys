#ifndef INVENTORY_H
#define INVENTORY_H

#include <Item.h>
#include <string>
#include <vector>

class Inventory
{
    public:
        Inventory(vector<Item> invItems);
        virtual ~Inventory(){};
        void addItem(Item);
        bool searchName(string name) const;
        bool searchItem(Item& item) const;
        Item getItem(string name) const;
        vector <Item> getInventory() const;
        void printItems() const;
        bool operator==(Inventory inv);
        bool operator!=(Inventory inv);

    private:
        vector<Item> items;
};

#endif // INVENTORY_H
