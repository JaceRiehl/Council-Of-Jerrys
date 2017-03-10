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
    CPPUNIT_TEST(testGetInventory);
    CPPUNIT_TEST(testAssign);
    CPPUNIT_TEST(testCopy);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

        ///Test for valid names
        void testConstructor();
        void testConstructorExceptions();
        void testgetName();
        void testGetInventory();
        void testAssign();
        void testCopy();

    private:
        Character *c, *c2, *c3, *c4, *c5, *c6, *c7, *cEmpty, *cTooLong;
        Inventory *inventory, *inventory2, *inventory3;
};

#endif // CHARACTERTEST_H
