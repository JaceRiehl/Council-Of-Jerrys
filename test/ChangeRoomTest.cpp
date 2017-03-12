#include "ChangeRoomTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ChangeRoomTest);

void ChangeRoomTest::testExecute()
{
    PlayableCharacter* playChar = new PlayableCharacter("Jerry");
    Room* testRoom = new Room(*playChar);
    Action* changeRoom = new ChangeRoom(playChar, testRoom, "exit");

    playChar->addAction("exit_room", changeRoom);

    string roomOutput = testRoom->run();

    CPPUNIT_ASSERT(roomOutput == "exit");
}
