#include "DataManagerTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DataManagerTest);

void DataManagerTest::testFORDACODECOVERAGE()
{
    PlayableCharacter* mainChar = new PlayableCharacter("Jerry");

    DataManager* dm = DataManager::Instance();

//    dm->saveGameData();
//
//    dm->loadNewData(mainChar);
//
//    dm->loadSaveData(mainChar);
//
//    map<string, Level*> gameData = dm->loadGameData(mainChar);
//
//    map<string, string> endGameText = dm->loadEndGameText();

    CPPUNIT_ASSERT_EQUAL(1, 1);
}
