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
    os<<text;
    os<<endl;
    os<<pList;
}

const ostream& operator<<(ostream& os, Window& win)
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

void Window::display(vector<string> vec, ostream& os)
{
    text.assignText("");
    pList.setList(vec);
    this->print(os);
}

void Window::display(map<char, string> mList, ostream& os)
{
    text.assignText("");
    pList.setList(mList);
    this->print(os);
}

