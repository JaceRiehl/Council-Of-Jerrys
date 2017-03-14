#include "Window.h"
#include "TextBox.h"
#include "PrintList.h"
#include <iostream>
#include <ostream>
#include <string>
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
    //system("clear");
    os<<text;
    os<<endl;
    os<<pList;
    //if(pList.isEmpty())
      //  os<<"Press ENTER to continue";
}

ostream& operator<<(ostream& os, Window& win)
{
    win.print(os);
    return os;
}

void Window::display(string str, ostream& os)
{
    text.assignText(str);
    pList = emptyList;
    this->print(os);
}

void Window::display(string str, vector<string> vec, ostream& os)
{
    text.assignText(str);
    pList.setList(vec);
    this->print(os);
}

void Window::display(string str, map<char,string> ma, ostream& os)
{
    text.assignText(str);
    pList.setList(ma);
    this->print(os);
}
