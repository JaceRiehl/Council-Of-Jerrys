#ifndef WINDOW_H
#define WINDOW_H
#include "TextBox.h"
#include "playerChoice.h"

class Window
{
public:
    Window(TextBox, playerChoice);
    ~Window();
private:
    TextBox text;
    playerChoice choice;
};

#endif
