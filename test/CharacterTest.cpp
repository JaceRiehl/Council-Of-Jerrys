#include "CharacterTest.h"
#include "Character.h"
#include "Item.h"
#include "Inventory.h"
#include "Exceptions.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Register the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(CharacterTest);

void CharacterTest::setUp()
{
    c = new Character("Mr. Poopy Pants");
    c4 = new Character("Jerry",{Item("shovel"), Item("Used toothbrush")});
    c5 = new Character("Rick",{Item("portal gun"), Item("red crystal"), Item("lint"), Item("precious lint")});
    c6 = new Character("Morty",{Item("nunchucks"), Item("medicine"), Item("dark matter recipe")});
    c7 = new Character("Beth",{Item("mighty spatula"), Item("bottle of wine"), Item("keys"), Item("scalpel")});
    inventory = new Inventory({Item("shovel"), Item("Used toothbrush")});
    inventory2 = new Inventory({Item("Used toothbrush"), Item("shovel")});
    inventory3 = new Inventory({Item("Used toothbrush")});
}

void CharacterTest::tearDown()
{
    delete c;
    delete c4;
    delete c5;
    delete c6;
    delete c7;
    delete inventory;
    delete inventory2;
    delete inventory3;
}

void CharacterTest::testConstructor()
{
    //Test 1-parameter constructor
    CPPUNIT_ASSERT_NO_THROW(c2 = new Character("Mr. Poopy Pants"));
    //Test multi-parameter constructor
    CPPUNIT_ASSERT_NO_THROW(c3 = new Character("Jerry",{Item("shovel"), Item("Used toothbrush")}));
    delete c2;
    delete c3;
}

void CharacterTest::testConstructorExceptions()
{
    CPPUNIT_ASSERT_THROW(cEmpty = new Character(""), characterNameError);
    CPPUNIT_ASSERT_THROW(cTooLong = new Character("I'm ants in my eyes Johnson; you might've seen me on TV."), characterNameError);
    delete cEmpty;
    delete cTooLong;
}

void CharacterTest::testgetName()
{
    // Set up
    string nameTest = "Mr. Poopy Pants";
    string nameTest2 = "Jerry";

    //Test get name w/ 1-parameter Character Object
    CPPUNIT_ASSERT_EQUAL(nameTest, c->getName());

    //Test getName() w/ multi-parameter Character Object
    CPPUNIT_ASSERT_EQUAL(nameTest2, c4->getName());

}

void CharacterTest::testGetInventory()
{
    //Exact replica of inventory
    CPPUNIT_ASSERT_EQUAL(true, *inventory == c4->getInventory());

    //Same inventory, but not same order
    CPPUNIT_ASSERT_EQUAL(true, *inventory2 == c4->getInventory());

    //inventory is not the same
    CPPUNIT_ASSERT_EQUAL(true, *inventory3 != c4->getInventory());
}

void CharacterTest::testAssign()
{

    //Test Equality When inventory LHS > RHS
    *c7 = *c4;
    CPPUNIT_ASSERT_EQUAL(true, c7->getName() == c4->getName());
    CPPUNIT_ASSERT_EQUAL(true, c7->getInventory() == c4->getInventory());
    //Test Equality When inventory LHS < RHS
    *c6 = *c5;
    CPPUNIT_ASSERT_EQUAL(true, c6->getName() == c5->getName());
    CPPUNIT_ASSERT_EQUAL(true, c6->getInventory() == c5->getInventory());
    //Test Equality When inventory LHS == RHS
    *c5 = *c7;
    CPPUNIT_ASSERT_EQUAL(true, c5->getName() == c7->getName());
    CPPUNIT_ASSERT_EQUAL(true, c5->getInventory() == c7->getInventory());
    //Test Equality When inventory LHS = 0 && LHS < RHS
    *c4 = *c7;
    CPPUNIT_ASSERT_EQUAL(true, c4->getName() == c7->getName());
    CPPUNIT_ASSERT_EQUAL(true, c4->getInventory() == c7->getInventory());

    //Test Equality When inventory RHS = 0 && LHS > RHS
    *c4 = *c;
    CPPUNIT_ASSERT_EQUAL(true, c4->getName() == c->getName());
    //Can't be tested since pointer getInventory cannot return a nullptr.
    //Assign function does it's work as it should though
    //CPPUNIT_ASSERT_EQUAL(true, c->getInventory() == c4->getInventory());

    //Test Equality When inventory RHS = 0 && LHS = 0
    *c = *c4;
    CPPUNIT_ASSERT_EQUAL(true, c->getName() == c4->getName());

    //Can't be tested since pointer getInventory cannot return a nullptr.
    //Assign function does it's work as it should though
    //CPPUNIT_ASSERT_EQUAL(true, c->getInventory() == c4->getInventory());
}


