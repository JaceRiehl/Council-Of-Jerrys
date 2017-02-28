#include "CharacterDataParser.h"

CharacterDataParser::CharacterDataParser(string filePath) : CouncilXMLParser(filePath) {}

bool CharacterDataParser::loadData()
{
    XMLNode* rootNode = doc.FirstChild();

    XMLNode* characterNode = rootNode->FirstChild();

    if(characterNode == nullptr)
        return false;

    do
    {
        CharacterData charData;
        if(!loadName(characterNode, charData))
            return false;

        if(!loadInventory(characterNode, charData))
            return false;

        if(!loadActions(characterNode, charData))
            return false;

        if(!loadState(characterNode, charData))
            return false;


        this->data.push_back(charData);

    } while(characterNode = characterNode->NextSiblingElement());


    return true;
}

vector<CharacterData> CharacterDataParser::getData() const
{
    return data;
}

bool CharacterDataParser::loadName(XMLNode* node, CharacterData& data)
{
    XMLElement *nameElem = node->FirstChildElement(NAME_NODE.c_str());

    if(!nameElem)
        return false;

    data.name = nameElem->GetText();

    return true;
}

bool CharacterDataParser::loadInventory(XMLNode* node, CharacterData& data)
{
    XMLElement *invElem = node->FirstChildElement(INVENTORY_NODE.c_str());

    if(!invElem)
        return false;

    XMLElement *keyNode = invElem->FirstChildElement();

    if(!keyNode)
        return false;

    do
    {
        data.inventory.push_back(keyNode->GetText());
    } while(keyNode = keyNode->NextSiblingElement());

    return true;
}

bool CharacterDataParser::loadActions(XMLNode* node, CharacterData& data)
{
    XMLElement *actionNode = node->FirstChildElement(ACTIONS_NODE.c_str());

    if(!actionNode)
        return false;

    XMLElement *keyNode = actionNode->FirstChildElement();

    if(!keyNode)
        return false;

    do
    {
        data.actions.push_back(keyNode->GetText());

    } while(keyNode = keyNode->NextSiblingElement());

    return true;
}

bool CharacterDataParser::loadState(XMLNode* node, CharacterData& data)
{
    XMLElement *stateNode = node->FirstChildElement(STATE_NODE.c_str());

    if(!stateNode)
        return false;

    data.state = stoi(stateNode->GetText());

    return true;
}
