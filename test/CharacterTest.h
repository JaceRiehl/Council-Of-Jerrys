#ifndef CHARACTERTEST_H
#define CHARACTERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Character.h"

class CharacterTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(CharacterTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testConstructorExceptions);
    CPPUNIT_TEST(testgetName);
    CPPUNIT_TEST(testSearchInventory);
    CPPUNIT_TEST(testGetItem);
    CPPUNIT_TEST(testGetItemExceptions);
    CPPUNIT_TEST(testGetInventory);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

        ///Test for valid names
        void testConstructor();
        void testConstructorExceptions();
        void testgetName();
        void testSearchInventory();
        void testGetItem();
        void testGetItemExceptions();
        void testGetInventory();

    private:
        Character *c, *c2, *c3, *c4, *cEmpty, *cTooLong;
        Inventory *inventory, *inventory2, *inventory3;
        Item *item, *itemDNE;
};

#endif // CHARACTERTEST_H
