#include "RoomXMLParser.h"

RoomXMLParser::RoomXMLParser(string filePath) : CouncilXMLParser(filePath) {}

vector<RoomData> RoomXMLParser::getData() const
{
    return data;
}

bool RoomXMLParser::loadData()
{
    XMLNode* rootNode = doc.FirstChild();

    XMLNode* roomNode = rootNode->FirstChild();

    if(!roomNode)
        return false;

    do
    {
        RoomData roomData;
        if(!loadName(roomNode, roomData))
            return false;

        if(!loadCharacters(roomNode, roomData))
            return false;

        if(!loadActions(roomNode, roomData))
            return false;

        this->data.push_back(roomData);
    } while(roomNode = roomNode->NextSibling());

    return true;
}

bool RoomXMLParser::loadName(XMLNode* node, RoomData& data)
{
    XMLElement* nameElem = node->FirstChildElement(NAME_NODE.c_str());

    if(!nameElem)
        return false;

    data.name = nameElem->GetText();

    return true;
}

bool RoomXMLParser::loadCharacters(XMLNode* node, RoomData& data)
{
    XMLElement* charactersElem = node->FirstChildElement(CHARACTERS_NODE.c_str());

    if(!charactersElem)
        return false;

    XMLElement* keyNode = charactersElem->FirstChildElement();

    if(!keyNode)
        return false;

    do
    {
        data.characters.push_back(keyNode->GetText());
    } while(keyNode = keyNode->NextSiblingElement());

    return true;
}

bool RoomXMLParser::loadActions(XMLNode* node, RoomData& data)
{
    XMLElement* actionsElem = node->FirstChildElement(ACTIONS_NODE.c_str());

    if(!actionsElem)
        return false;

    XMLElement* keyNode = actionsElem->FirstChildElement();

    if(!keyNode)
        return false;

    do
    {
        data.actions.push_back(keyNode->GetText());
    } while(keyNode = keyNode->NextSiblingElement());

    return true;
}
