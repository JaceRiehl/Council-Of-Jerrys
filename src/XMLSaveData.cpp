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
   // pRoot->InsertEndChild(pElement);
    pElement = saveFile.NewElement("PLAYERACTIONS");
    for(const auto& str : data.playerActions)
    {
        XMLElement * pListElement = saveFile.NewElement("KEY");
        pListElement->SetText(str.c_str());
        pElement->InsertEndChild(pListElement);
    }
    pElement = saveFile.NewElement("LEVEL");
    pElement->SetText(data.level);
    pRoot->InsertEndChild(pElement);
    pElement = saveFile.NewElement("ROOM");
    pElement->SetText(data.room);
    pRoot->InsertEndChild(pElement);
    pRoot->InsertEndChild(pElement);

    saveFile.SaveFile("saveFile.xml");

}
