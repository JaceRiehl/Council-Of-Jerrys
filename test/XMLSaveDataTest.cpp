#include "XMLSaveDataTest.h"
#include <string>
#include <vector>

void XMLSaveDataTest::setUp()
{
    data;
    vector<string> inv = {"axe", "sword", "book"};
    vector<string> act = {"talked to...", "Searched..."};
    char* room = "garage";
    char* level = "01";

    data.inventoryItems = inv;
    data.playerActions = act;
    data.room = room;
    data.level = level;
}

void XMLSaveDataTest::tearDown()
{

}

void XMLSaveDataTest::saveDataTest()
{
    XMLSaveData saveFile;
    saveFile.saveData(data);
}
