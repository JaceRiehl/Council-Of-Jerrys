#include "CharacterTest.h"
#include "Character.h"
#include "Item.h"
#include "Inventory.h"
#include "Exceptions.h"
#include <string>
#include <iostream>

using namespace std;

// Register the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(CharacterTest);

void CharacterTest::setUp()
{
    c = new Character("Mr. Poopy Pants");
    c4 = new Character("Jerry",{Item("shovel"), Item("Used toothbrush")});
    item = new Item("Used toothbrush");
    itemDNE = new Item("portal gun");
    inventory = new Inventory({Item("shovel"), Item("Used toothbrush")});
    inventory2 = new Inventory({Item("Used toothbrush"), Item("shovel")});
    inventory3 = new Inventory({Item("Used toothbrush")});
}

void CharacterTest::tearDown()
{
    delete c;
    delete c4;
    delete item;
    delete itemDNE;
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

    //Test 1-parameter constructor
    CPPUNIT_ASSERT_EQUAL(nameTest, c->getName());
}

void CharacterTest::testSearchInventory()
{
    CPPUNIT_ASSERT_EQUAL(true, c4->searchInventory(*item));
    CPPUNIT_ASSERT_EQUAL(false, c4->searchInventory(*itemDNE));
}

void CharacterTest::testGetItem()
{
    CPPUNIT_ASSERT_EQUAL(true, *item == c4->getItem(item->getName()));
}

void CharacterTest::testGetItemExceptions()
{
    CPPUNIT_ASSERT_THROW(c4->getItem(itemDNE->getName()), itemDoesNotExist);
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


