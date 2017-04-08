#include "ChangeRoomTest.h"

#include <iostream>

using std::cout;

CPPUNIT_TEST_SUITE_REGISTRATION(ChangeRoomTest);

void ChangeRoomTest::testExecute()
{
    PlayableCharacter* character = new PlayableCharacter("Jerry");
    string actionKey = "change_room_test";
    map<string, Menu*> menus;
    map<string, NPC*> npcs;

    map<char, string> testMenuOutput;
    map<char, string> testMenuInput;

    testMenuInput['1'] = actionKey;
    testMenuOutput['1'] = "Change Room";

    Menu* testMenu = new Menu("CHANGE_ROOM_TEST", testMenuOutput, testMenuInput);

    menus["top"] = testMenu;

    Room* testRoom = new Room("change_room_test", "This is a test room", npcs, menus);

    map<string, string> testChangeRoomContext;
    testChangeRoomContext["change_room"] = actionKey;

    Action* testChangeRoomAction = new ChangeRoom(character, actionKey, testRoom, testChangeRoomContext);

    map<string, Action*> roomActions;

    roomActions[actionKey] = testChangeRoomAction;

    testRoom->setActions(roomActions);

    string output;
    output = testRoom->run(character);

    CPPUNIT_ASSERT(output == actionKey);
}

void ChangeRoomTest::testConditionsNotMet()
{
    PlayableCharacter* character = new PlayableCharacter("Jerry");
    string actionKey = "change_room_test";
    string actionKey1 = "change_room_test1";
    map<string, Menu*> menus;
    map<string, NPC*> npcs;

    map<char, string> testMenuOutput;
    map<char, string> testMenuInput;

    testMenuInput['1'] = actionKey;
    testMenuOutput['1'] = "Change Room";
    testMenuInput['2'] = actionKey1;
    testMenuOutput['2'] = "Change Room1";

    Menu* testMenu = new Menu("CHANGE_ROOM_TEST", testMenuOutput, testMenuInput);

    menus["top"] = testMenu;

    Room* testRoom = new Room("change_room_test", "This is a test room", npcs, menus);

    map<string, string> testChangeRoomContext;
    testChangeRoomContext["change_room"] = actionKey;
    testChangeRoomContext["conditions_not_met"] = "CAN'T CHANGE ROOM!";

    vector<string> conditions;
    conditions.push_back("some_condition");

    map<string, string> testChangeRoomContext1;
    testChangeRoomContext1["change_room"] = actionKey1;

    Action* testChangeRoomAction = new ChangeRoom(character, actionKey, testRoom, testChangeRoomContext, conditions);
    Action* testChangeRoomAction1 = new ChangeRoom(character, actionKey1, testRoom, testChangeRoomContext1);

    map<string, Action*> roomActions;

    roomActions[actionKey] = testChangeRoomAction;
    roomActions[actionKey1]= testChangeRoomAction1;

    testRoom->setActions(roomActions);

    string output;
    output = testRoom->run(character);

    CPPUNIT_ASSERT(output == actionKey1);
}
