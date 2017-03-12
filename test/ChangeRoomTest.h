#ifndef CHANGEROOMTEST_H
#define CHANGEROOMTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "ChangeRoom.h"
#include "Exceptions.h"
#include "PlayableCharacter.h"

class ChangeRoomTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ChangeRoomTest);
    CPPUNIT_TEST(testExecute);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testExecute();
};

#endif // CHANGEROOMTEST_H
