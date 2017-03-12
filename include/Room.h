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
    *Takes over run until the execution of the menus has reached the end
    *@return string that determines whether or not to continue the
    */
    string inputExecution(char);
    /**
    *The jerry that room will make adjustments to
    */
    PlayableCharacter& jerry;
    /**
    *The map of NPC characters, maps the string with the characters name to the instance of the object for that character
    */
    map<string, NPC*> characters;
    /**
    *The map of the inital choices the user can make, maps from the char chosen to string displayed
    */
    map<char,string> output;
    /**
    *The map of the inital choices the user can make, maps from the char chosen to string displayed
    */
    map<char,string> choices;
    /**
    *Map for the submenus, maps from the choices string to the map of the submenu
    */
    map<string, map<char,string>> substring;
    /**
    *Map for the menu displayed after the main menus choice
    */
    map<char, string> submenuTalkOutput;
    /**
    *Map for the talk inputs
    */
    map<char, string> submenuTalkInput;
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
    *Tests that user input is within the parameters
    *@param the characters input
    *@return true if the input is correct, false if the input is wrong
    */
    bool checkStatus(char input);
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
    string choice;
    map<string,Menu*> menus;


};

#endif
