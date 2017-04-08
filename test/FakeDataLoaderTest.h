#ifndef FAKEDATALOADERTEST_H
#define FAKEDATALOADERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "FakeDataLoader.h"

class FakeDataLoaderTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(FakeDataLoaderTest);
    CPPUNIT_TEST(testLoadLevels);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testLoadLevels();
};

#endif // FAKEDATALOADERTEST_H
