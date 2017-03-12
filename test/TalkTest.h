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
    CPPUNIT_TEST_SUITE_END();

    public:
        void testConstructor();
        void testExecute();
        void testExecuteException();

};

#endif // TALKTEST_H
