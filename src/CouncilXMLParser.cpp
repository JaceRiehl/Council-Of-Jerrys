#include "CouncilXMLParser.h"
#include "Exceptions.h"
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;
using std::ios_base;

CouncilXMLParser::CouncilXMLParser(string filePath)
{
    if(doc.LoadFile(filePath.c_str()))
        throw runtime_error("Error: File not found.");
}

void CouncilXMLParser::setDoc(string filePath)
{
    doc.LoadFile(filePath.c_str());
}
