#include "ConsoleInterface.h"
#include <iostream>
#include <string>
using namespace std;

ConsoleInterface::ConsoleInterface() {}

ConsoleInterface::~ConsoleInterface() {}

char ConsoleInterface::getChar(istream& is)
{
    //cout<<"Enter your choice: ";
    is>>userChar;
    return userChar;
}

void ConsoleInterface::getEnterKey(istream & is)
{
    is.get();
}

string ConsoleInterface::getString(istream& is)
{
    //cout<<"Enter your answer: ";
    getline(is,userString);
    return userString;
}
