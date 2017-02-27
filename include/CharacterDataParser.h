#ifndef CHARACTERDATAPARSER_H
#define CHARACTERDATAPARSER_H

#include "CouncilXMLParser.h"
#include "CharacterData.h"
#include <string>

using std::string;

/**
*   @file CharacterDataParser.h
*   @author Nathan Tipper
*   @date February 22, 2017
*   @brief CharacterDataParser loads Character data from an XML file.
*/

class CharacterDataParser : public CouncilXMLParser
{
    public:
        /**
        *   @brief Constructor which takes a string argument which refers to the file path
        *   it will load data from.
        *   @pre It is given a valid filepath.
        *   @post The XMLParser can now load data from the given file path.
        *   @param The file path of the xml document to load from.
        *   @return None.
        */
        CharacterDataParser(string);

        virtual ~CharacterDataParser() {}

        /**
        *   @brief Loads data from the xml document provided.
        *   @pre The loading path has been initialized and is valid.
        *   @post All data from the Xml Document is stored and ready to be accessible.
        *   @param None.
        *   @return If successful, or not.
        */
        bool LoadData();

        /**
        *   @brief Accessor method for the data that has been parsed.
        *   @pre The data has been extracted by using LoadData.
        *   @post The data is returned.
        *   @param None.
        *   @return Extracted Data.
        */
        vector<CharacterData> getData() const;
    private:
        /**
        *   @brief Finds the name field and extracts it from the XML document.
        *   @pre XMLDocument has been loaded from a valid file path.
        *   @post The name of the character is stored in the CharacterData.
        *   @param The CharacterData to which the name data is stored.
        *   @return If successful, or not.
        */
        bool LoadName(XMLNode*, CharacterData&);

        /**
        *   @brief Finds the Inventory field and extracts the names of the items
        *   from the XML document.
        *   @pre XMLDocument has been loaded from a valid file path.
        *   @post The inventory of the character is stored in the CharacterData.
        *   @param The CharacterData to which the inventory data is stored.
        *   @return If successful, or not.
        */
        bool LoadInventory(XMLNode*, CharacterData&);

        /**
        *   @brief Finds the Action field and extracts the names of the actions
        *   from the XML document.
        *   @pre XMLDocument has been loaded from a valid file path.
        *   @post The actions of the character are stored in the CharacterData.
        *   @param The CharacterData to which the actions data is stored.
        *   @return If successful, or not.
        */
        bool LoadActions(XMLNode*, CharacterData&);

        /**
        *   @brief Finds the State field and extracts the value of the state
        *   from the XML document.
        *   @pre XMLDocument has been loaded from a valid file path.
        *   @post The state of the character is stored in the CharacterData.
        *   @param The CharacterData to which the state data is stored.
        *   @return If successful, or not.
        */
        bool LoadState(XMLNode*, CharacterData&);


        const string ROOT_NODE = "CHARACTERS"; /// The root element of the document.
        const string NAME_NODE = "NAME";
        const string INVENTORY_NODE = "INVENTORY";
        const string ACTIONS_NODE = "ACTIONS";
        const string STATE_NODE = "STATE";
        vector<CharacterData> data; /// The container which stores the CharacterData.
};

#endif // CHARACTERDATAPARSER_H
