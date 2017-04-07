#include "ChangeRoomTest.h"

#include <iostream>

using std::cout;

CPPUNIT_TEST_SUITE_REGISTRATION(ChangeRoomTest);

void ChangeRoomTest::testExecute()
{
    Window window;
    PlayableCharacter* playChar = new PlayableCharacter("Jerry");
    Room* testRoom = new Room(playChar);
    Action* changeRoom = new ChangeRoom(playChar, "change_room_exit_level", testRoom, { {"change_room", "exit"} });
    playChar->addAction("change_room_exit_level", changeRoom);

    string roomOutput = testRoom->run(playChar);

    CPPUNIT_ASSERT(roomOutput == "exit");
}
