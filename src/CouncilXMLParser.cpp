#include "CouncilXMLParser.h"
#include <exception>
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;
using std::ios_base;
using std::runtime_error;

CouncilXMLParser::CouncilXMLParser(string filePath)
{
    if(doc.LoadFile(filePath.c_str()))
        throw runtime_error("Error: File not found.");
}

void CouncilXMLParser::setDoc(string filePath)
{
    doc.LoadFile(filePath.c_str());
}
