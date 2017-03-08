#ifndef PRINTLIST_H
#define PRINTLIST_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
using namespace std;
/**
*Formats and prints a list of objects
*/
class PrintList
{
public:
    /**
    *Default constructor with no list initialized
    */
    PrintList();
    /**
    *Default constructor for a map of strings
    *@param a map of strings accessed through characters
    */
    PrintList(map<char, string>);
    /**
    *Default constructore for a vector of strings
    *@param a vector of strings
    */
    PrintList(vector<string>);
    /**
    *Deconstructor for PrintList
    */
    virtual ~PrintList();
    /**
    *Copy constructor for PrintList
    */
    PrintList(PrintList&);
    /**
    *Prints the formated list
    *@param an ostream to print out the list
    */
    void print(ostream&);
    /**
    *Checks weather the object has a list or not
    *@param None
    */
    bool isEmpty();
    /**
    *Overloaded assignment operator
    */
    void operator=(PrintList&);
    /**
    *Overloaded insertion operator, uses the print function
    */
    friend ostream& operator<<(ostream&, PrintList&);

private:
    string stringToPrint;
    string convert(vector<string>);
    string convert(map<char, string>);
};

#endif // PRINTLIST_H
