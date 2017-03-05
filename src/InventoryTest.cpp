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
}

void InventoryTest::tearDown()
{
    delete item;
    delete itemDNE;
    delete inventory;
}

void InventoryTest::testConstructor()
{

}

void InventoryTest::testAddItem()
{

}

void InventoryTest::testSearchName()
{

}

void InventoryTest::testSearchItem()
{
    CPPUNIT_ASSERT_EQUAL(true, inventory->searchItem(*item));
    CPPUNIT_ASSERT_EQUAL(false, inventory->searchItem(*itemDNE));
}

void InventoryTest::testGetItem()
{
    CPPUNIT_ASSERT_EQUAL(true, *item == inventory->getItem(item->getName()));
}

void InventoryTest::testGetItemExceptions()
{
    CPPUNIT_ASSERT_THROW(inventory->getItem(itemDNE->getName()), itemDoesNotExist);
}
void InventoryTest::testOperatorEquals()
{

}
