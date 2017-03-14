#ifndef TALKTEST_H
#define TALKTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Talk.h"
#include "Exceptions.h"

class TalkTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TalkTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testExecute);
    CPPUNIT_TEST(testExecuteException);
    CPPUNIT_TEST(testPlayerActionConditions);
    CPPUNIT_TEST(testPlayerItemConditions);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testConstructor();
        void testExecute();
        void testExecuteException();
        void testPlayerActionConditions();
        void testPlayerItemConditions();
};

#endif // TALKTEST_H
