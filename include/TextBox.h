#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>
#include <iostream>
#include <ostream>
using namespace std;

/**
*Formats a string into a text box with borders
*/
class TextBox //: public Window
{
public:
    /**
    *Default constructor
    *@param a string to be in the text box
    */
    TextBox(std::string = "");
    /**
    *Deconstructor for TextBox
    */
    virtual ~TextBox();
    /**
    *Copy constructor for TextBox
    */
    TextBox(TextBox&);
    /**
    *Helper function to make a deep copy
    *@param a TextBox to be copied
    */
    void copy(const TextBox&);
    /**
    *Overloaded assignment operator
    */
    void operator=(const TextBox&);
    /**
    *Prints the formated TextBox
    *@param an ostream to print the TextBox
    */
    void print(ostream&) const;
    /**
    *Reassigns the string of the TextBox
    *@param string
    */
    void assignText(string);
    /**
    *Helper function to deallocate any leftover memory, used in the deconstructor
    *@param None
    */
    void deallocateMem();
    /**
    *Overloaded insertion operator, uses print for format
    */
    friend ostream& operator<<(ostream&, const TextBox&);

private:
    /**
    *Helper function to print consecutive characters a desired amount of times
    *@param int of desired consicutive chars
    *@param the char to be printed
    *@param ostream to print the characters
    */
    void fillChar(int, char, ostream&) const;

    char ** textBody = nullptr;
    int rows;
    const int WIDTH = 60;
};

#endif
