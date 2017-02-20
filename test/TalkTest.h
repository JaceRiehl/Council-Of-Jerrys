#ifndef TALKTEST_H
#define TALKTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Action.h"

class TalkTest : CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TalkTest);

    CPPUNIT_TEST_SUITE_END();

    public:
        TalkTest(string);
        bool executeAction(string);

};

#endif // TALKTEST_H
