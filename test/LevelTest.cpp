#include "LevelTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(LevelTest);

void LevelTest::testRun()
{
    PlayableCharacter* jerry = new PlayableCharacter("Jerry");
    map<string, Action*> actions;

    string levelName = "cob_earth";
    string openingLevelMessage = "EVERYTHING IS ON A COB!";

    map<string, Room*> rooms;

    Room* room1 = new Room(*jerry);
    Room* room2 = new Room(*jerry);

    Action* changeToBar = new ChangeRoom(jerry, room1, "bar");
    Action* changeToTown = new ChangeRoom(jerry, room2, "town");
    Action* exitLevel1 = new ChangeRoom(jerry, room1, "exit_level");

    actions["change_room_bar"] = changeToBar;
    actions["change_room_town"] = changeToTown;
    actions["change_room_exit_level"] = exitLevel1;

    jerry->addAction(actions);

    rooms["town"] = room1;
    rooms["bar"] = room2;

    Window window;

    window.display("*** THIS IS THE LEVEL TEST!! *** ", cout);

    Level* level = new Level(levelName, *jerry, rooms, openingLevelMessage);

    string output = level->run();

    CPPUNIT_ASSERT(output == "mini_earth");
}
