#include "XMLSaveDataTest.h"
#include <string>
#include <vector>

CPPUNIT_TEST_SUITE_REGISTRATION(XMLSaveDataTest);

void XMLSaveDataTest::setUp()
{
    vector<string> inv = {"axe", "sword", "book"};
    vector<string> act = {"talked to...", "Searched..."};
    char* room = "garage";
    char* level = "1";

    XMLSaveData::Data.inventoryItems = inv;
    XMLSaveData::Data.playerActions = act;
    XMLSaveData::Data.room = room;
    XMLSaveData::Data.level = level;
}

void XMLSaveDataTest::tearDown()
{

}

void XMLSaveDataTest::saveDataTest()
{
    XMLSaveData::saveData();
}
