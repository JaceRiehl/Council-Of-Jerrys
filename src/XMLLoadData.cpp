#include "XMLLoadData.h"
#include <iostream>

const string XMLLoadData::SAVED_DATA_PATH= "../data/saveFile.xml";
const string XMLLoadData::NEW_DATA_PATH = "../data/newGame.xml";

bool XMLLoadData::loadData(string filePath)
{
    XMLDocument loadFile;
    SaveData data;

    if(loadFile.LoadFile(filePath.c_str()))
        return false;

    XMLNode * pRoot = loadFile.FirstChild();
    XMLElement * invElement = pRoot->FirstChildElement("INVENTORY");

    if(!invElement)
        return XML_ERROR_PARSING_ELEMENT;

    const XMLNode * keyNode = invElement->FirstChild();

    vector<string> inv;

    if(keyNode)
    {
        do
        {
            const XMLElement* keyElement = keyNode->ToElement();
            if(!keyElement)
                return XML_ERROR_MISMATCHED_ELEMENT;

            inv.push_back(keyElement->GetText());
        } while((keyNode = keyNode->NextSibling()));
    }
    data.inventoryItems = inv;

    XMLElement* levelElement = pRoot->FirstChildElement("LEVEL");

    data.level = levelElement->GetText();

    XMLElement* roomElement = pRoot->FirstChildElement("ROOM");

    data.room = roomElement->GetText();

    XMLElement* pActions = pRoot->FirstChildElement("ACTIONS");

    const XMLNode * actionsNode = pActions->FirstChild();

    vector<string> actions;

    if(actionsNode)
    {
        do
        {
            const XMLElement* keyElement = actionsNode->ToElement();
            if(!keyElement)
                return XML_ERROR_MISMATCHED_ELEMENT;

            inv.push_back(keyElement->GetText());
        } while((actionsNode = actionsNode->NextSibling()));
    }

    data.playerActions = actions;
    XMLSaveData::Data = data;

    return true;
}

