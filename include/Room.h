#ifndef ROOM_H
#define ROOM_H

#include<string>
#include<vector>
#include<map>
#include "CharacterAction.h"
#include "TextBox.h"
#include <typeinfo>
#include "ConsoleInterface.h"
#include "Window.h"
#include "PrintList.h"
#include "PlayableCharacter.h"
#include "NPC.h"

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

    /**merge branches
    *Used to take over until the level is complete
    *@return int that corresponds to the next level to deploy
    */
    int run();

    /**
    *Takes over run until the execution of the menus has reached the end
    *@return string that determines whether or not to continue the
    */
    string inputExecution(char);




private:
    /**
    *The jerry that room will make adjustments to
    */
    PlayableCharacter jerry;
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
    map<string, map<char,string>> submenuChoices;
    /**
    *Map for the menu displayed after the main menus choice
    */
    map<char, string> submenuOutput;
    /**
    *An instance of the ConsoleInterface used to input from the user
    */
    ConsoleInterface Inputting;
    /**
    *The introduction string used for Textbox
    */
    string intro = "Welcome to our game, do stuff and things in here";
    char firstInput;
    Window GameWindow;



    //vector<string> charKeys; //= {"Rick", "Mrmeeseek", "MrSlipperyStair", "BirdPerson"};//birdPerson, schwanch, unity, evil, beth, kingJelly, jessica, mortyJr, summer, personalSpaceDude,
    //realFakeDoorsSalesman, EvilRick};
    //vector<string> actionKeys = {talk, giveItem};

    //vector<string> availItemKeys = {meeseekBox, wrench, key};
    //vector<Action*> actionMap = {};

    //vector<Character*> charMap = {new NPC = Rick("Rick"), new NPC = Mrmeeseek("Mrmeeseek"), new NPC = MrSlipperyStair("MrSlipperStair"),
    //new NPC = BirdPerson("BirdPerson"};
    //vector<Item> itemMap = {MeeseekBox("MeeseekBox"), Wrench("Wrench"), Key("Key")};
    //map<string,string> dialog = ["Rick"]
    //vector<Action*> actionMap;

    //enum State = {garage, bar, house};
    //vector<string> houseChoices = {"Rick", "Evil Rick"};
    //vector<string> barChoices = {"mrmeeseek", "BirdPerson"};
    //string name;



};

#endif
