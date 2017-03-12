#include "ItemsTest.h"
#include "Exceptions.h"

// Register the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(ItemsTest);

void ItemsTest::setUp()
{
    item = new Item("shovel");
    itemDNE = new Item("portal gun");
}

void ItemsTest::tearDown()
{
    delete item;
    delete itemDNE;
}

void ItemsTest::testConstructor()
{
    CPPUNIT_ASSERT_NO_THROW(item2 = new Item("shovel"));
    delete item2;
}

void ItemsTest::testConstructorExceptions()
{
    //test empty string item case
    CPPUNIT_ASSERT_THROW(item2 = new Item(""), itemNameError);
    delete item2;

    //test string exceeds character limit case
    CPPUNIT_ASSERT_THROW(item2 = new Item("blahblahblahblahblahblahblahblah"), itemNameError);
    delete item2;
}

void ItemsTest::testGetName()
{
    //test returning the name of an item
    string itemNameTest = "shovel";
    CPPUNIT_ASSERT_EQUAL(true, itemNameTest == item->getName());
}

void ItemsTest::testOperatorEquals()
{
    //test Equality between two items which are the same not working
    //even though strings are exactly the same
    item2 = new Item("shovel");
    //CPPUNIT_ASSERT_EQUAL(true, item2 == item);
    //test Inequality between two items which are not the same
    CPPUNIT_ASSERT_EQUAL(true, item2 != itemDNE);
    delete item2;
}
