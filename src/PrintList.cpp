#include "PrintList.h"
#include <string>
#include <sstream>

using namespace std;

PrintList::PrintList()
{
    stringToPrint = "";
}

PrintList::PrintList(map<char, string> m)
{
    stringToPrint = convert(m);
}

PrintList::PrintList(vector<string> v)
{
    stringToPrint = convert(v);
}

PrintList::~PrintList() {}

PrintList::PrintList(PrintList& pL)
{
    this->stringToPrint = pL.stringToPrint;
}

void PrintList::print(ostream& os)
{
    if(isEmpty())
        stringToPrint = "";
    os<<stringToPrint;
}

bool PrintList::isEmpty()
{
    if(stringToPrint == "")
        return true;

    return false;
}

void PrintList::operator=(PrintList& pL)
{
    if(this != &pL)
        this->stringToPrint = pL.stringToPrint;
}

ostream& operator<<(ostream& os, PrintList& pl)
{
    pl.print(os);
    return os;
}

string PrintList::convert(vector<string> vec)
{
    stringstream str;
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        str<<i+1 <<')'<< " " << vec[i]<<endl;
    }
    stringToPrint = str.str();
    return stringToPrint;
}
string PrintList::convert(map<char, string> m)
{
    stringstream str;
    for (std::map<char,string>::iterator it=m.begin(); it!=m.end(); ++it)
        str << it->first << ')' << it->second << '\n';
    stringToPrint = str.str();
    return stringToPrint;
}

void PrintList::setList(vector<string> vec)
{
    stringToPrint = convert(vec);
}

void PrintList::setList(map<char, string> ma)
{
    stringToPrint = convert(ma);
}
