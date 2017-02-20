#ifndef _ACTIONTEST_H
#define _ACTIONTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Action.h"

class ActionTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ActionTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST_SUITE_END();

    public:

        void testConstructor();
};


#endif // _ACTIONTEST_H
