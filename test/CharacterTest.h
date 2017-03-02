#ifndef CHARACTERTEST_H
#define CHARACTERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Character.h"

class CharacterTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(CharacterTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testgetName);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

        ///Test for valid names
        void testConstructor();
        void testgetName();

    private:
        Character *c;
        Character *c4;
        Item *item;
};

#endif // CHARACTERTEST_H
