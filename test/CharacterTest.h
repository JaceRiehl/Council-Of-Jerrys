#ifndef CHARACTERTEST_H
#define CHARACTERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Character.h"

class CharacterTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ActionTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST_SUITE_END();

    public:

        void testConstructor();

};

#endif // CHARACTERTEST_H
