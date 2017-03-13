#ifndef ROOM_H
#define ROOM_H

#include<string>
#include<vector>
#include<map>
#include "Exceptions.h"
#include <typeinfo>
#include "ConsoleInterface.h"
#include "Window.h"
#include "PlayableCharacter.h"
#include "NPC.h"
#include "Menu.h"
#include "Talk.h"

/**
*Used to run the different rooms that the user will encounter
*/
class Room
{
public:
    /**
    *Constructor for Room
    *@param PlayableCharacter jerry
    */
    Room(PlayableCharacter&);

    /**
    *Used to take over until the level is complete
    *@return string nextRoom that corresponds to the next level to deploy
    */
    string run();
    /**
    *Called by RoomAction when the character wants to change rooms
    *@param string - the string used to set nextRoom
    */
    void exit(string);


private:
    /**
    *The jerry that room will make adjustments to
    */
    PlayableCharacter& jerry;
    /**
    *The map of NPC characters, maps the string with the characters name to the instance of the object for that character
    */
    map<string, NPC*> characters;
    /**
    *An instance of the ConsoleInterface used to input from the user
    */
    ConsoleInterface Inputting;
    /**
    *The introduction string used for Textbox
    */
    string intro = "Welcome to our game, do stuff and things in here";
    /**
    *Records the input for the main menu
    */
    char firstInput;
    /**
    *Window object instance used to display on the terminal
    */
    Window GameWindow;
    /**
    *Getter for PlayableCharacters name
    *@return string of their name
    */
    string getCharacterName();
    /**
    *Getter for Jerry's inventory
    *@return the Inventory of the playable character in the level
    */
    const Inventory* getCharacterInv();
    /**
    *Variable returned by run
    */
    string nextRoom;
    /**
    *Declaring the possible states of the room
    */
    enum State {done, running};
    /**
    *The state object
    */
    State state;
    /**
    *Adds the inputted values from the user to determine that action to take
    */
    string choice;
    /**
    *Map of menus
    */
    map<string,Menu*> menus;


};

#endif
