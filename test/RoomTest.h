#ifndef _ROOMTEST_H
#define _ROOMTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "FakeDataLoader.h"


class RoomTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(RoomTest);
    CPPUNIT_TEST(testRun);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();
        void testRun();

    private:
        PlayableCharacter *mainChar;
        Room* roomTest;
};


#endif // _ACTIONTEST_H

