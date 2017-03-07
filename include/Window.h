#ifndef WINDOW_H
#define WINDOW_H
#include "TextBox.h"
#include "PrintList.h"
#include <ostream>

class Window
{
public:
    Window(TextBox);
    Window(TextBox, PrintList);
    virtual ~Window();
    void setTextBox(TextBox);
    void setPlayerChoice(PrintList);
    void print(ostream&);
    friend ostream& operator<<(ostream&, Window&);


private:
    TextBox text;
    PrintList pList;
};

#endif
