#include "RoomTest.h"

#include <iostream>

using std::cout;

CPPUNIT_TEST_SUITE_REGISTRATION(RoomTest);

void RoomTest::setUp()
{
    mainChar = new PlayableCharacter("Jerry");

    roomTest = FakeDataLoader::buildFakeRoom(mainChar);
}
void RoomTest::tearDown()
{
    delete roomTest;
    delete mainChar;
}

void RoomTest::testRun()
{
    string output;
    output = roomTest->run(mainChar);
}

