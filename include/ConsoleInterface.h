#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H
#include <string>
#include <istream>
using namespace std;
/**
*Promps user for inputs
*/
class ConsoleInterface
{
public:
    /**
    *An interface to promp user for inputs
    *@param None
    */
    ConsoleInterface();
    /**
    *Deconstructor for ConsoleInterface
    */
    virtual ~ConsoleInterface();
    /**
    *Promps the user to enter a character
    *@param None
    *@return the character provided from the user
    */
    char getChar(istream&);
    /**
    *Waits for user to input the enter key
    *@param None
    *@return Nothing
    */
    void getEnterKey(istream&);
    /**
    *Promps user to enter a string
    *@param None
    *@return the string provided by the user
    */
    string getString(istream&);

private:
    /**
    *Is assigned the provided character variable
    */
    char userChar;
    /**
    *Is assigned the provided string variable
    */
    string userString;
};

#endif // CONSOLEINTERFACE_H
