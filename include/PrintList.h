#ifndef PRINTLIST_H
#define PRINTLIST_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
using namespace std;

class PrintList
{
    public:
        PrintList();
        PrintList(map<char, string>);
        PrintList(vector<string>);
        virtual ~PrintList();
        PrintList(PrintList&);
        void print(ostream&);
        bool isEmpty();
        void operator=(PrintList&);
        friend ostream& operator<<(ostream&, PrintList&);

    private:
        string stringToPrint;
        string convert(vector<string>);
        string convert(map<char, string>);
};

#endif // PRINTLIST_H
