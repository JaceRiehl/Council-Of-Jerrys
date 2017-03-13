#include "XMLSaveData.h"

bool XMLSaveData::saveData(SaveData data)
{
    XMLDocument saveFile;
    XMLNode * pRoot = saveFile.NewElement("SAVEDATA");
    saveFile.InsertFirstChild(pRoot);

    XMLElement * pElement = saveFile.NewElement("INVENTORY");
    for(const auto& str : data.inventoryItems)
    {
        XMLElement * pListElement = saveFile.NewElement("KEY");
        pListElement->SetText(str.c_str());
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    XMLElement * lElement = saveFile.NewElement("LEVEL");
    lElement->SetText((data.level).c_str());
    pRoot->InsertEndChild(lElement);
    XMLElement * rElement = saveFile.NewElement("ROOM");
    rElement->SetText((data.room).c_str());
    pRoot->InsertEndChild(rElement);
    XMLElement * aElement = saveFile.NewElement("PLAYER_ACTIONS");
    for(const auto& str : data.playerActions)
    {
        XMLElement * p2ListElement = saveFile.NewElement("KEY");
        p2ListElement->SetText(str.c_str());
        aElement->InsertEndChild(p2ListElement);
    }
    pRoot->InsertEndChild(aElement);
    saveFile.SaveFile("saveFile.xml");

}
