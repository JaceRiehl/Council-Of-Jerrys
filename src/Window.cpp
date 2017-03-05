#include "Window.h"
#include "TextBox.h"
#include "PrintList.h"
#include <iostream>

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

void Window::print()
{
    text.print();
    std::cout<<std::endl;
    pList.print();
    if(pList.isEmpty())
        std::cout<<"Press ENTER to continue";
}

