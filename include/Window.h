#ifndef WINDOW_H
#define WINDOW_H
#include "TextBox.h"
#include "PlayerChoice.h"

class Window
{
public:
    Window(TextBox);
    Window(TextBox, PlayerChoice);
    virtual ~Window();
    void setTextBox(TextBox);
    void setPlayerChoice(PlayerChoice);
    void print();

private:
    TextBox text;
    PlayerChoice choice;
};

#endif
