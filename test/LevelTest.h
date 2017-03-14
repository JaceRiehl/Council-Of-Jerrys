#ifndef LEVELTEST_H
#define LEVELTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include "Level.h"
#include "ChangeRoom.h"
#include "Talk.h"

using std::cout;

class LevelTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(LevelTest);
    //CPPUNIT_TEST(testRun);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testRun();
};

#endif // LEVELTEST_H
