#include "CouncilXMLParser.h"
#include "RoomData.h"

class RoomXMLParser : public CouncilXMLParser
{
    public:
        RoomXMLParser(string);
        bool loadData();
        vector<RoomData> getData() const;

    private:
        bool loadName(XMLNode*, RoomData&);
        bool loadCharacters(XMLNode*, RoomData&);
        bool loadActions(XMLNode*, RoomData&);

        const string NAME_NODE = "NAME";
        const string CHARACTERS_NODE = "CHARACTERS";
        const string ACTIONS_NODE = "ACTIONS";

        vector<RoomData> data;
};
