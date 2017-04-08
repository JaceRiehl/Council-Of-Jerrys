#include "Menu.h"

Menu::Menu(string menuText, map<char,string> out, map<char,string> in)
{
    text = menuText;
    output = out;
    input = in;

    #ifdef RELEASE
    ioInfo = new IOInfo();

    #else

    ioInfo = new IOInfo("../data/menuTestOutput", "");

    #endif // RELEASE
}

void Menu::print()
{
    GameWindow.display(text, output, ioInfo->getOutputStream());
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
