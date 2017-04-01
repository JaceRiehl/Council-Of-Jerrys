#include "XMLSaveData.h"

SaveData XMLSaveData::Data;

bool XMLSaveData::saveData()
{
    FILE* fileToWriteTo;

    fileToWriteTo = fopen("../data/saveFile.xml", "w+");

    if(fileToWriteTo)
    {
        XMLDocument saveFile;
        XMLNode * pRoot = saveFile.NewElement("SAVEDATA");
        saveFile.InsertFirstChild(pRoot);

        XMLElement * pElement = saveFile.NewElement("INVENTORY");
        for(const auto& str : Data.inventoryItems)
        {
            XMLElement * pListElement = saveFile.NewElement("KEY");
            pListElement->SetText(str.c_str());
            pElement->InsertEndChild(pListElement);
        }
        pRoot->InsertEndChild(pElement);
        XMLElement * lElement = saveFile.NewElement("LEVEL");
        lElement->SetText((Data.level));
        pRoot->InsertEndChild(lElement);
        XMLElement * rElement = saveFile.NewElement("ROOM");
        rElement->SetText(Data.room);
        pRoot->InsertEndChild(rElement);
        XMLElement * aElement = saveFile.NewElement("PLAYER_ACTIONS");
        for(const auto& str : Data.playerActions)
        {
            XMLElement * p2ListElement = saveFile.NewElement("KEY");
            p2ListElement->SetText(str.c_str());
            aElement->InsertEndChild(p2ListElement);
        }
        pRoot->InsertEndChild(aElement);

        if(saveFile.SaveFile(fileToWriteTo))
            throw runtime_error("COULD NOT SAVE FILE");

        fclose(fileToWriteTo);

        return true;
    }

    return false;
}
