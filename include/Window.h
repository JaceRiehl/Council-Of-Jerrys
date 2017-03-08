#ifndef WINDOW_H
#define WINDOW_H
#include "TextBox.h"
#include "PrintList.h"
#include <ostream>
/**
*Prints a TextBox object with the option of printing a list below
*/
class Window
{
public:
    /**
    *Default constructor for Window
    *@param a TextBox to print
    */
    Window(TextBox);
    /**
    *Default constructor for Windows
    *@param a TextBox to print
    *@param a PrintList to print
    */
    Window(TextBox, PrintList);
    /**
    *Deconstructor for Window
    */
    virtual ~Window();
    /**
    *Reassigns the TextBox
    *@param a TextBox
    */
    void setTextBox(TextBox);
    /**
    *Reassigns the PrintList
    *@param a PrintList
    */
    void setPlayerChoice(PrintList);
    /**
    *Prints the TextBox and PrintList(if any)
    *@param an ostream to print
    */
    void print(ostream&);
    /**
    *Overloaded insertion operator, uses the print function
    */
    friend ostream& operator<<(ostream&, Window&);


private:
    TextBox text;
    PrintList pList;
};

#endif
