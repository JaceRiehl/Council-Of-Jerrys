#include "ConsoleInterface.h"
#include <iostream>
#include <string>
using namespace std;

ConsoleInterface::ConsoleInterface() {}

ConsoleInterface::~ConsoleInterface() {}

char ConsoleInterface::getChar()
{
    cout<<"Enter your choice: ";
    cin>>userChar;
    return userChar;
}

void ConsoleInterface::getEnterKey()
{
    cin.get();
}

string ConsoleInterface::getString()
{
    cout<<"Enter your answer: ";
    getline(cin,userString);
    return userString;
}
