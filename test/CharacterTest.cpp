#include "CharacterTest.h"
#include "Character.h"
#include "Action.h"
#include <string>
#include <iostream>

using namespace std;

// Register the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(CharacterTest);

void CharacterTest::setUp()
{
    c = new Character("Mr. Poopy Pants");
    c4 = new Character("Jerry",{Item("shovel"), Item("Used condom")});
    item = new Item("shovel");
}

void CharacterTest::tearDown()
{
    delete c;
    delete c4;
    delete item;
}

void CharacterTest::testConstructor()
{
    // Set up
    string nameTest = "Mr. Poopy Pants";
    string nameTest2 = "Jerry";

    //Test 1-parameter constructor
    CPPUNIT_ASSERT_EQUAL(nameTest, c->getName());
    CPPUNIT_ASSERT_EQUAL(nameTest2, c4->getName());
}

void CharacterTest::testgetName()
{
    // Set up
    string nameTest = "Mr. Poopy Pants";

    //Test 1-parameter constructor
    CPPUNIT_ASSERT_EQUAL(nameTest, c->getName());
}


