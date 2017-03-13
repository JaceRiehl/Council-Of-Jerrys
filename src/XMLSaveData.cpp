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

    saveFile.SaveFile("saveFile.xml");

}
