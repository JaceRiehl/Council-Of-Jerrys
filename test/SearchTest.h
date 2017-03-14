#ifndef SEARCHTEST_H
#define SEARCHTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Search.h"

class SearchTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(SearchTest);
    CPPUNIT_TEST(testConditionsNotMet);
    CPPUNIT_TEST(testConditionsMet);
    CPPUNIT_TEST(testSearched);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testConditionsNotMet();
        void testConditionsMet();
        void testSearched();
};

#endif // SEARCHTEST_H
