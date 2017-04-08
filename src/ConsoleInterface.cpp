#include "ConsoleInterface.h"
#include <iostream>
#include <string>
using namespace std;

ConsoleInterface::ConsoleInterface() {}

ConsoleInterface::~ConsoleInterface() {}

char ConsoleInterface::getChar(istream& is)
{
    string choice;
    is.sync();
    getline(is, choice);
    return choice[0];
}

void ConsoleInterface::getEnterKey(istream & is)
{
    is.ignore();
}

string ConsoleInterface::getString(istream& is)
{
    string choice;
    is.sync();
    getline(is, choice);
    return choice;
}
