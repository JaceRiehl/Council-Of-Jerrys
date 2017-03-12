#ifndef NPC_H
#define NPC_H

#include <Character.h>
#include <string>



/**
    @file Character.h
    @author Nathan Tipper
    @date March 3, 2017
    @brief NPC derives from Character and represents all characters the players does not control
*/

class NPC : public Character
{
    public:
        /**
            @brief Constructor for the NPC class which sets the name of the NPC.
            @pre A string with length between 1 and 30 is given.
            @post The NPC's name is set to the given string.
            @param Name of the NPC.
            @return None.
        */
        NPC(string);

        /**
            @brief Constructor for the NPC class which sets the name and the inventory of the NPC.
            @pre A string with length between 1 and 30 is given.
            @post The NPC's name and inventory are set to the given parameters.
            @param Name of the NPC.
            @param Starting Inventory of the NPC.
            @return None.
        */
        NPC(string, vector<Item>);

        virtual ~NPC(){};

        /**
            @brief getDialog gets the dialog which maps to the given key.
            @pre A string which is a key within the map of dialog is given.
            @post No change.
            @param Name of the key.
            @throw keyDoesNotExist if the key doesn't exist in the map.
            @return The string that the given key was mapped to.
        */
        string getDialog(string);

        /**
            @brief setDialog sets the NPC's dialog.
            @pre A map is given.
            @post The current state of the dialog is set to the map.
            @param The map for which the dialog will be set to.
            @return None.
        */
        void setDialog(map<string, string>);

    private:
        map<string, string> dialog;
};

#endif // NPC_H
