#include "XMLLoadData.h"
#include <iostream>
bool XMLLoadData::loadData(SaveData data)
{
    XMLDocument loadFile;
    loadFile.LoadFile("savedFile.xml");
    XMLNode * pRoot = loadFile.FirstChild();
    XMLElement * levelElem = pRoot->FirstChildElement("LEVEL");
    data.level = levelElem->GetText();



    /*
    XMLNode * pRoot = loadFile.FirstChild();
    XMLElement * pElement = pRoot->FirstChildElement("LEVEL");
    const char* outStr = nullptr;
    outStr = pElement->Attribute("LEVEL");
    if(pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
    std::string outLevel = outStr;
*/


}

