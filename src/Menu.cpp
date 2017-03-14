#include "Menu.h"

Menu::Menu(string menuText, map<char,string> out, map<char,string> in)
{
    text = menuText;
    output = out;
    input = in;
}

void Menu::print()
{
    GameWindow.display(text, output, cout);
}

bool Menu::validInput(char inputted)
{
    if(output.find(inputted) == output.end())
        return false;
    return true;

}

string Menu::getText() const
{
    return text;
}
