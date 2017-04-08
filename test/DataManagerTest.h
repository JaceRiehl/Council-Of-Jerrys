#ifndef DATAMANAGERTEST_H
#define DATAMANAGERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "DataManager.h"

class DataManagerTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(DataManagerTest);
    CPPUNIT_TEST(testFORDACODECOVERAGE);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testFORDACODECOVERAGE();
};

#endif
