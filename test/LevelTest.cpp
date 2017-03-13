#include "LevelTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(LevelTest);

void LevelTest::testRun()
{
    PlayableCharacter* jerry = new PlayableCharacter("Jerry");
    map<string, Action*> actions;

    string levelName = "cob_earth";
    string openingLevelMessage = "EVERYTHING IS ON A COB!";

    map<string, Room*> rooms;

    Room* room1 = new Room(jerry);
    Room* room2 = new Room(jerry);

    map<string, string> changeToBarContext;
    changeToBarContext["change_room"] = "bar";

    map<string, string> changeToTownContext;
    changeToTownContext["change_room"] = "town";

    map<string, string> exitLevelContext;
    exitLevelContext["change_room"] = "exit_level";

    Action* changeToBar = new ChangeRoom(jerry, "change_room_bar", room1, changeToBarContext);
    Action* changeToTown = new ChangeRoom(jerry, "change_room_town", room2, changeToTownContext);
    Action* exitLevel1 = new ChangeRoom(jerry, "change_room_exit_level", room1, exitLevelContext);

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
