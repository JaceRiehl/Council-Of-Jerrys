#include "InventoryTest.h"
#include "Inventory.h"
#include "Item.h"
#include "Exceptions.h"
#include <string>
#include <iostream>

using namespace std;

// Register the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(InventoryTest);

void InventoryTest::setUp()
{
    item = new Item("Used toothbrush");
    itemDNE = new Item("portal gun");
    inventory = new Inventory({Item("shovel"), Item("Used toothbrush")});
    inventory3 = new Inventory({Item("shovel"),Item("shovel"),Item("shovel"),Item("shovel")});
    inventory4 = new Inventory({Item("shovel"),Item("shovel"),Item("shovel"),Item("shovel")});
}

void InventoryTest::tearDown()
{
    delete item;
    delete itemDNE;
}

void InventoryTest::testConstructor()
{
    CPPUNIT_ASSERT_NO_THROW(inventory2 = new Inventory({Item("shovel"), Item("Used toothbrush")}));
    delete inventory2;
}

void InventoryTest::testConstructorExceptions()
{
    CPPUNIT_ASSERT_THROW(inventory2 = new Inventory({}), inventoryEmpty);
    delete inventory2;
}

void InventoryTest::testAddItem()
{
    //test push_back
    inventory->addItem(Item ("Ultra Sonic Range Finder"));
    CPPUNIT_ASSERT_EQUAL(true, inventory->getInventory()[2] == Item ("Ultra Sonic Range Finder"));

    //test insert
    inventory->addItem(Item ("shovel"));
    CPPUNIT_ASSERT_EQUAL(true, inventory->getInventory()[1] == Item ("shovel"));
}

void InventoryTest::testSearchName()
{
    //test if name exists in inventory
    CPPUNIT_ASSERT_EQUAL(true, inventory->searchName("Used toothbrush"));
    //test if name doesn't exist in inventory
    CPPUNIT_ASSERT_EQUAL(false, inventory->searchName("m&m's"));
}

void InventoryTest::testSearchItem()
{
    //test if item exists in inventory
    CPPUNIT_ASSERT_EQUAL(true, inventory->searchItem(*item));
    //test if item does not exist in inventory
    CPPUNIT_ASSERT_EQUAL(false, inventory->searchItem(*itemDNE));
}

void InventoryTest::testGetItem()
{
    //test returning a specific item by name from the items vector
    CPPUNIT_ASSERT_EQUAL(true, *item == inventory->getItem(item->getName()));
}

void InventoryTest::testGetItemExceptions()
{
    //trying to return an item from the items vector which does not exist
    CPPUNIT_ASSERT_THROW(inventory->getItem(itemDNE->getName()), itemDoesNotExist);
}
void InventoryTest::testOperatorEquals()
{
    //testing equallity with identical objects
    inventory2 = new Inventory({Item("shovel"), Item("Used toothbrush")});
    CPPUNIT_ASSERT_EQUAL(true, *inventory == *inventory2);
    //testing inequallity with different objects
    inventory2->addItem(Item("headphones"));
    CPPUNIT_ASSERT_EQUAL(true, *inventory != *inventory2);
    //testing same size vector with identical repeat objects
    CPPUNIT_ASSERT_EQUAL(true, *inventory3 == *inventory4);
    delete inventory2;
    delete inventory3;
    delete inventory4;
}
