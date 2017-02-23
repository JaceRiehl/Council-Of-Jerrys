#include "CouncilXMLParser.h"
#include <iostream>

using std::cout;
using std::endl;

CouncilXMLParser::CouncilXMLParser(string filePath)
{
    if(doc.LoadFile(filePath.c_str()))
        cout << "FAILURE" << endl;
    else
        cout << "SUCCESS" << endl;
}

void CouncilXMLParser::setDoc(string filePath)
{
    doc.LoadFile(filePath.c_str());
}
