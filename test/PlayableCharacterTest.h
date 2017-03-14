#ifndef PLAYABLECHARACTERTEST_H
#define PLAYABLECHARACTERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "PlayableCharacter.h"
#include "Exceptions.h"
#include "Talk.h"

class PlayableCharacterTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(PlayableCharacterTest);
    CPPUNIT_TEST(testTakeAction);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testTakeAction();
};

#endif // PLAYABLECHARACTERTEST_H
