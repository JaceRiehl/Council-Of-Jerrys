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
    CPPUNIT_TEST(testSearchName);
    CPPUNIT_TEST(testSearchItem);
    CPPUNIT_TEST(testGetItem);
    CPPUNIT_TEST(testGetItemExceptions);
    CPPUNIT_TEST(testOperatorEquals);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

        void testConstructor();
        void testConstructorExceptions();
        void testAddItem();
        void testSearchName();
        void testSearchItem();
        void testGetItem();
        void testGetItemExceptions();
        void testOperatorEquals();

    private:
        Inventory *inventory, *inventory2, *inventory3, *inventory4;
        Item *item, *itemDNE;
};

#endif // INVENTORYTEST_H
