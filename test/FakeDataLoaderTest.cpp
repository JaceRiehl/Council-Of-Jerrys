#include "FakeDataLoaderTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(FakeDataLoaderTest);

void FakeDataLoaderTest::testLoadLevels()
{
    PlayableCharacter* character = new PlayableCharacter("Jerry");
    map<string, Level*> levels;

    FakeDataLoader* fdl = FakeDataLoader::Instance();

    fdl->LoadLevels(character, levels);

    map<string, string> endOfGameText;

    fdl->LoadEndOfGameText(endOfGameText);

    CPPUNIT_ASSERT(levels.find("intro") != levels.end());

    delete character;
}
