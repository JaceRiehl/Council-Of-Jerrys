#ifndef _ROOMTEST_H
#define _ROOMTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Room.h"
#include "Inventory.h"
#include "PlayableCharacter.h"
#include "Talk.h"
#include "Window.h"

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
        PlayableCharacter *J;
        Inventory* inventory;
        Room* roomTest;
};


#endif // _ACTIONTEST_H

