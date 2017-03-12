#include "ChangeRoomTest.h"

#include <iostream>

using std::cout;

CPPUNIT_TEST_SUITE_REGISTRATION(ChangeRoomTest);

void ChangeRoomTest::testExecute()
{
    Window window;
    window.display("*** THIS IS THE CHANGE ROOM TEST ***", cout);
    PlayableCharacter* playChar = new PlayableCharacter("Jerry");
    Room* testRoom = new Room(*playChar);
    Action* changeRoom = new ChangeRoom(playChar, testRoom, "exit");

    playChar->addAction("exit_room", changeRoom);

    string roomOutput = testRoom->run();

    CPPUNIT_ASSERT(roomOutput == "exit");
}