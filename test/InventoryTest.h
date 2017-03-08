#ifndef INVENTORYTEST_H
#define INVENTORYTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Inventory.h"

class InventoryTest: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(InventoryTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testConstructorExceptions);
    CPPUNIT_TEST(testAddItem);
    CPPUNIT_TEST(testRemoveItem);
    CPPUNIT_TEST(testSearchName);
    CPPUNIT_TEST(testSearchItem);
    CPPUNIT_TEST(testGetItem);
    CPPUNIT_TEST(testGetItemExceptions);
    CPPUNIT_TEST(testOperatorEquals);
    CPPUNIT_TEST(testPrint);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

        void testConstructor();
        void testConstructorExceptions();
        void testAddItem();
        void testRemoveItem();
        void testSearchName();
        void testSearchItem();
        void testGetItem();
        void testGetItemExceptions();
        void testOperatorEquals();
        void testPrint();

    private:
        Inventory *inventory, *inventory2, *inventory3, *inventory4, *inventory5;
        Item *item, *itemDNE;
};

#endif // INVENTORYTEST_H
