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
    *@param None
    */
    Window() {}
    /**
    *Default constructor for Window
    *@param TextBox
    */
    Window(TextBox);
    /**
    *Default constructor for Windows
    *@param TextBox to print
    *@param PrintList to print
    */
    Window(TextBox, PrintList);
    /**
    *Deconstructor for Window
    */
    virtual ~Window();
    /**
    *Reassigns the TextBox
    *@param TextBox
    */
    void setTextBox(TextBox);
    /**
    *Reassigns the PrintList
    *@param PrintList
    */
    void setPlayerChoice(PrintList);
    /**
    *Prints the TextBox and PrintList(if any)
    *@param ostream to print
    */
    void print(ostream&);
    /**
    *Overloaded insertion operator, uses the print function
    */
    friend ostream& operator<<(ostream&, Window&);
    /**
    *Displayes the string as a TextBox to the desired ostream
    *@param string to display in TextBox
    *@param desired ostream
    */
    void display(string, ostream&);
    /**
    *Displayes the string as a TextBox and a vector list of string to the desired ostream
    *@param string to display in TextBox
    *@param vector list of strings
    *@param desired ostream
    */
    void display(string, vector<string>, ostream&);
    /**
    *Displayes the string as a TextBox and a map list of string to the desired ostream
    *@param string to display in TextBox
    *@param map list of strings
    *@param desired ostream
    */
    void display(string, map<char,string>, ostream&);


private:
    TextBox text;
    PrintList pList;
    PrintList emptyList;
};

#endif
