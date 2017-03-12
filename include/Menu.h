#ifndef _MENU_H
#define _MENU_H
#include<map>
#include<string>
#include "ConsoleInterface.h"
#include "Window.h"

using std::string;
using std::map;
using std::cout;

class Menu
{
public:
    Menu(string, map<char,string>, map<char,string>);

    map<char,string> input;
    map<char,string> output;

    void print();
    bool validInput(char);
    string getText() const;
private:
    /**
    *An instance of the ConsoleInterface used to input from the user
    */
    ConsoleInterface Inputting;
    /**
    *Window object instance used to display on the terminal
    */
    Window GameWindow;
    string text;

};
#endif // _MENU_H
