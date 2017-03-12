#ifndef ITEMSTEST_H
#define ITEMSTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Inventory.h"
#include "Item.h"

class ItemsTest: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ItemsTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testConstructorExceptions);
    CPPUNIT_TEST(testGetName);
    CPPUNIT_TEST(testOperatorEquals);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

        void testConstructor();
        void testConstructorExceptions();
        void testGetName();
        void testOperatorEquals();

    private:

    Item *item, *item2, *item3, *itemDNE;
};

#endif // ITEMSTEST_H

