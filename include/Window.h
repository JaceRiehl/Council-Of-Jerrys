#ifndef WINDOW_H
#define WINDOW_H
#include "TextBox.h"

class Window
{
public:
    Window(TextBox);
    ~Window();
private:
    TextBox text;
   // PlayerChoice choice;
};

#endif
