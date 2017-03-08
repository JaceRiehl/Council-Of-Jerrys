#include "Window.h"
#include "TextBox.h"
#include "PrintList.h"
#include <iostream>
#include <ostream>
using namespace std;

Window::Window(TextBox body) : text(body) {}

Window::Window(TextBox body, PrintList pL) : text(body), pList(pL) {}

Window::~Window(){}

void Window::setTextBox(TextBox setText)
{
    text = setText;
}

void Window::setPlayerChoice(PrintList setList)
{
    pList = setList;
}

void Window::print(ostream& os)
{
    system("clear");
    os<<text;
    os<<endl;
    os<<pList;
    if(pList.isEmpty())
        os<<"Press ENTER to continue";
}

ostream& operator<<(ostream& os, Window& win)
{
    win.print(os);
    return os;
}
