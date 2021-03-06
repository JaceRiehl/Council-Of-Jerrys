#ifndef CHARACTER_H
#define CHARACTER_H

#include "Inventory.h"
#include "Item.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Inventory;
class Item;

/**
    @file Character.h
    @author Michel Martel
    @date March 3, 2017
    @brief Character is the Base class from which NPC and playable character derives.
*/

class Character
{
    public:
        /**
            @brief Constructor for the Character class which sets the name of the Character.
            @pre A string with length between 1 and 30 is given.
            @post The Character's name is set to the given string.
            @param Name of the Character.
            @return None.
        */
        Character(string name);

        /**
            @brief Constructor for the Character class which sets the name and inventory of the Character.
            @pre A string with length between 1 and 30 is given along with a non-empty vector of Item objects.
            @post The Character's name is set to the given string and a new Iventory object is created with the given Item vector.
            @param Name of the Character.
            @param Starting Inventory of the Character.
            @return None.
        */
        Character(string name, vector<Item> charInv);

        /**
            @brief Copy constructor for the Character class.
            @pre None.
            @post Character is a copy of the parameter given.
            @param The Character to copy.
            @return None.
        */
        Character(const Character&);

        virtual ~Character();

        /**
            @brief getName() gets the name of the character.
            @pre None.
            @post The Character's name is returned.
            @return The string assigned to the Character's name.
        */
        string getName() const;

        /**
            @brief getInventory() gets the pointer to the character's inventory
            @pre None.
            @post The Character's pointer to its inventory is returned.
            @return The pointer to the inventory.
        */
        const Inventory* getInventory() const;

        /**
            @brief addItem() adds an Item to the character's inventory or creates an inventory if it doesn't exists and then adds the item.
            @pre An item to be added.
            @post An item is added to the character's inventory.
            @return None.
        */
        void addItem(Item);

        /**
            @brief removeItem() removes an item from the character's inventory and deletes the inventory if inventory is empty.
            @pre an existing item to be removed.
            @post An item is removed from the character's inventory.
            @return None.
        */
        void removeItem(Item);

        /**
            @brief operator= assigns a character's attributes to another (NPC or Playable).
            @pre a referece to a Character object.
            @post The LHS Character's is assigned the attributes of the RHS Character.
            @return None.
        */
        void operator=(Character& c);

    private:
        string charName;
        Inventory *inventory;
};

#endif // CHARACTER_H
