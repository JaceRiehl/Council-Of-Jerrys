#ifndef WINDOW_H
#define WINDOW_H
#include "TextBox.h"
#include "PrintList.h"

class Window
{
public:
    Window(TextBox);
    Window(TextBox, PrintList);
    virtual ~Window();
    void setTextBox(TextBox);
    void setPlayerChoice(PrintList);
    void print();

private:
    TextBox text;
    PrintList pList;
};

#endif
