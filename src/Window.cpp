#include "Window.h"
#include "PlayerChoice.h"
#include "TextBox.h"
#include <iostream>

Window::Window(TextBox body) : text(body) {}
Window::Window(TextBox body, PlayerChoice c) : text(body), choice(c) {}
Window::~Window(){}

void Window::setTextBox(TextBox setText)
{
    text = setText;
}

void Window::setPlayerChoice(PlayerChoice setChoice)
{
    choice = setChoice;
}

void Window::print()
{
    text.print();
    std::cout<<std::endl;
    choice.print();
    if(choice.isEmpty())
        std::cout<<"Press ENTER to continue";
}

