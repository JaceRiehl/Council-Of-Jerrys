#include "RoomTest.h"

#include <iostream>

using std::cout;

CPPUNIT_TEST_SUITE_REGISTRATION(RoomTest);

void RoomTest::setUp()
{
    Window window;
    window.display("*** THIS IS THE ROOMTEST ***", cout);
    inventory = new Inventory({Item("Used toothbrush"), Item("shovel")});
    J = new PlayableCharacter("Jerry", {Item("shovel"), Item("Used toothbrush")});
    roomTest = new Room(*J);
}
void RoomTest::tearDown()
{
    delete roomTest;
    delete J;
}
/*void RoomTest::testConstructor()
{
    CPPUNIT_ASSERT_EQUAL(J->getName(), roomTest->getCharacterName());
    CPPUNIT_ASSERT_EQUAL(*(J->getInventory()), *inventory);

}
*/

void RoomTest::testRun()
{

    string output;
    output = roomTest->run();
    //assert that the string is equal to the desired room
    //CPPUNIT_ASSERT_EQUAL();

}

