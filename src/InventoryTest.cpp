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
    inventory5 = new Inventory({Item("used toothbrush"),Item("shovel"), Item("portal gun"),
    Item("shovel"),Item("shovel"),Item("portal gun"),Item("shovel"),Item("used toothbrush"),
    Item("mittens")});
}

void InventoryTest::tearDown()
{
    delete item;
    delete itemDNE;
    delete inventory;
    delete inventory3;
    delete inventory4;
    delete inventory5;
}

void InventoryTest::testConstructor()
{
    CPPUNIT_ASSERT_NO_THROW(inventory2 = new Inventory({Item("shovel"), Item("Used toothbrush")}));
    delete inventory2;
}

void InventoryTest::testConstructorExceptions()
{
    vector<Item> items;
    CPPUNIT_ASSERT_THROW(inventory2 = new Inventory(items), inventoryEmpty);
    delete inventory2;
}

void InventoryTest::testAddItem()
{
    //test vector push_back
    inventory->addItem(Item ("Ultra Sonic Range Finder"));
    CPPUNIT_ASSERT_EQUAL(true, inventory->searchName("Ultra Sonic Range Finder"));

    //test vector insert
    inventory->addItem(Item ("shovel"));
    CPPUNIT_ASSERT_EQUAL(true, inventory->getInventory()[0] == Item ("shovel"));
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
}

void InventoryTest::testPrint()
{
    //test for sorting and itemization of item vector
    cout << endl;
    inventory5->printItems();
}
