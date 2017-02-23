#ifndef COUNCILXMLPARSER_H
#define COUNCILXMLPARSER_H

#include "tinyxml2.h"
#include <string>
#include <map>

using std::map;
using std::string;

using tinyxml2::XMLDocument;
using tinyxml2::XMLElement;
using tinyxml2::XMLNode;

/**
*   @file CouncilXMLParser.h
*   @author Nathan Tipper
*   @date February 2, 2017
*   @brief CouncilXMLParser is responsible for loading data into the game via XML.
*/

class CouncilXMLParser
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
        CouncilXMLParser(string);

        /**
        *   @brief Deconstructor of CouncilXMLParser.
        *   @pre None.
        *   @post None.
        *   @param None.
        *   @return None.
        */
        virtual ~CouncilXMLParser() {}

        /**
        *   @brief Loads data from the xml document provided.
        *   @pre The loading path has been initialized and is valid.
        *   @post All data from the Xml Document is stored and ready to be accessible.
        *   @param None.
        *   @return If successful, or not.
        */
        virtual bool LoadData() = 0;

        /**
        *   @brief Loads the XMLDocument from the given file path.
        *   @pre The string given is a valid file path.
        *   @post The xml document is now set to the file at the given path.
        *   @param The file path of the xml document to load from.
        *   @return None.
        */
        void setDoc(string);

    protected:
        XMLDocument doc;
};

#endif // XMLPARSER_H
