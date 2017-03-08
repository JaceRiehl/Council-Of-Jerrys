#ifndef INVENTORY_H
#define INVENTORY_H

#include <Item.h>
#include <string>
#include <vector>

/**
    @file Inventory.h
    @author Michel Martel
    @date March 3, 2017
    @brief Inventory stores a vector of items on a per character basis.
*/

class Inventory
{
    public:
        /**
            @brief Constructor for the Inventory class which creates a sorted vector of items.
            @pre a non-empty list of Item objects is given.
            @post a sorted inventory of items is created.
            @param a vector of Item object(s).
            @return None.
        */
        Inventory(vector<Item> invItems);

        virtual ~Inventory(){};

        /**
            @brief addItem adds an item at the end of the item vector and sorts the vector.
            @pre An non-empty Item object is given.
            @post The given item is added to the vector of items and sorted.
            @param An item.
            @return None.
        */
        void addItem(Item);

        /**
            @brief searchName takes a string and searches the item vector for the given string.
            @pre The string of an object's name.
            @post Returns true if item name is present in vector; false otherwise.
            @param string of name of the object.
            @return bool.
        */
        bool searchName(string name) const;

        /**
            @brief searchItem takes an item and searches the item vector for the given item.
            @pre An item object is given.
            @post Returns true if item is present in vector; false otherwise.
            @param Item object.
            @return bool.
        */
        bool searchItem(Item& item) const;

        /**
            @brief getItem takes the string of an item's name and return the item object.
            @pre A string of an object's name is given.
            @post Returns the item corresponding to the given name string.
            @param string name of the object.
            @return An Item object.
        */
        Item getItem(string name) const;

        /**
            @brief getInventory takes returns the vector of item.
            @pre nothing is given.
            @post Returns the item vector.
            @return An Item vector.
        */
        vector <Item> getInventory() const;

        /**
            @brief printItems displays a itemized and sorted list of the item vector.
            @pre Nothing is given.
            @post The vector of item is displayed on the user's monitor
            @return None.
        */
        void printItems() const;

        /**
            @brief operator== checks to see if two given inventories are the same.
            @pre An Inventory is given.
            @post a bool statement is determined depending on whether the inventories are equivalent.
            @param An inventory object.
            @return bool.
        */
        bool operator==(Inventory inv);

        /**
            @brief operator!= checks to see if two given inventories are different.
            @pre An Inventory is given.
            @post a bool statement is determined depending on whether the inventories are different.
            @param An inventory object.
            @return bool.
        */
        bool operator!=(Inventory inv);

    private:
        vector<Item> items;
};

#endif // INVENTORY_H
