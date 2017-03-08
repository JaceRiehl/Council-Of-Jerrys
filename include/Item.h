#ifndef ITEM_H
#define ITEM_H

#include "Character.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Character;

/**
    @file Item.h
    @author Michel Martel
    @date March 3, 2017
    @brief Item class creates items for a character's inventory.
*/

class Item
{
    public:
        /**
            @brief Constructor for the Item class which creates an item.
            @pre a string with a name length between 1 and 30 is given
            @post an item object is created.
            @param string name for object.
            @return None.
        */
        Item(string itemName);

        virtual ~Item(){};

        /**
            @brief operator== checks to see if two given items are the same.
            @pre An Item is given.
            @post a bool statement is determined depending on whether the itemss are equivalent.
            @param An item object.
            @return bool.
        */
        bool operator==(const Item& itm) const;

        /**
            @brief operator!= checks to see if two given item are different.
            @pre An item is given.
            @post a bool statement is determined depending on whether the item are different.
            @param An item object.
            @return bool.
        */
        bool operator!=(const Item& itm) const;

        /**
            @brief operator< implements the rules for item comparison.
            @pre An item is given.
            @post a bool statement is determined depending on whether the string of item name is greater than the other.
            @return bool.
        */
        bool operator<(const Item& rhs) const;

        /**
            @brief returns the string of an object's name.
            @pre Nothing is given.
            @post The string name of the referenced object is returned.
            @param None
            @return The name of the item as a string.
        */
        string getName() const;

    private:
        string name;
};

#endif // ITEM_H
