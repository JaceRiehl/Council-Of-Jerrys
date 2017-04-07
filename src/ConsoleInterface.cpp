#include "ConsoleInterface.h"
#include <iostream>
#include <string>
using namespace std;

ConsoleInterface::ConsoleInterface() {}

ConsoleInterface::~ConsoleInterface() {}

char ConsoleInterface::getChar(istream& is)
{
    string choice;
    cout << endl << "Please enter your choice: ";
    is.sync();
    getline(is, choice);
    return choice[0];
}

void ConsoleInterface::getEnterKey(istream & is)
{
    cout<<"Hit the ENTER key to continue."<<endl;
    is.ignore();
}

string ConsoleInterface::getString(istream& is)
{
    string choice;
    cout << endl << "Please enter your choice: ";
    is.sync();
    getline(is, choice);
    return choice;
}
