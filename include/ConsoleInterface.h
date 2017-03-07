#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H
#include <string>
using namespace std;

class ConsoleInterface
{
    public:
        ConsoleInterface();
        virtual ~ConsoleInterface();
        char getChar();
        void getEnterKey();
        string getString();

    private:
        char userChar;
        string userString;
};

#endif // CONSOLEINTERFACE_H
