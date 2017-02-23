#include "CharacterDataParser.h"

CharacterDataParser::CharacterDataParser(string filePath) : CouncilXMLParser(filePath) {}

bool CharacterDataParser::LoadData()
{
    XMLNode* rootNode = doc.FirstChild();

    XMLNode* characterNode = rootNode->FirstChild();

    while(characterNode->NextSibling())
    {
        CharacterData charData;
        if(!LoadName(characterNode, charData))
            return false;

        if(!LoadInventory(characterNode, charData))
            return false;

        if(!LoadActions(characterNode, charData))
            return false;

        if(!LoadState(characterNode, charData))
            return false;


        data.push_back(charData);

        characterNode = characterNode->NextSibling();
    }


    return true;
}

bool CharacterDataParser::LoadName(XMLNode* node, CharacterData& data)
{
    XMLElement *nameElem = node->FirstChildElement(NAME_NODE.c_str());

    if(!nameElem)
        return false;

    data.name = nameElem->GetText();

    return true;
}

bool CharacterDataParser::LoadInventory(XMLNode* node, CharacterData& data)
{
    XMLElement *invElem = node->FirstChildElement(INVENTORY_NODE.c_str());

    if(!invElem)
        return false;

    XMLNode *itemNode = invElem->FirstChild();

    if(!itemNode)
        return false;

    while(itemNode->NextSibling())
    {
        data.inventory.push_back(itemNode->Value());

        itemNode = itemNode->NextSibling();
    }

    return true;
}

bool CharacterDataParser::LoadActions(XMLNode* node, CharacterData& data)
{
    XMLElement *actionNode = node->FirstChildElement(ACTIONS_NODE.c_str());

    if(!actionNode)
        return false;

    XMLNode *nameNode = actionNode->FirstChild();

    if(!nameNode)
        return false;

    while(nameNode->NextSibling())
    {
        data.actions.push_back(nameNode->Value());

        nameNode = nameNode->NextSibling();
    }

    return true;
}

bool CharacterDataParser::LoadState(XMLNode* node, CharacterData& data)
{
    XMLElement *stateNode = node->FirstChildElement(STATE_NODE.c_str());

    if(!stateNode)
        return false;

    data.state = std::stoi(stateNode->GetText());

    return true;
}
