#ifndef NPCTEST_H
#define NPCTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "NPC.h"

class NPCTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(NPCTest);
    CPPUNIT_TEST(testGetSetDialog);
    CPPUNIT_TEST(testKeyDoesntExistException);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testGetSetDialog();
        void testKeyDoesntExistException();
};

#endif // NPCTEST_H
