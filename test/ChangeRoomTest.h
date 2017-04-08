#ifndef CHANGEROOMTEST_H
#define CHANGEROOMTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "ChangeRoom.h"
#include "Exceptions.h"
#include "PlayableCharacter.h"
#include "Window.h"

class ChangeRoomTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ChangeRoomTest);
    CPPUNIT_TEST(testExecute);
    CPPUNIT_TEST(testConditionsNotMet);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testExecute();
        void testConditionsNotMet();
};

#endif // CHANGEROOMTEST_H
