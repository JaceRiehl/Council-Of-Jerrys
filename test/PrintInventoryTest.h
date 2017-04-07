#ifndef PRINTINVENTORYTEST_H
#define PRINTINVENTORYTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "PrintInventory.h"

class PrintInventoryTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(PrintInventoryTest);
    CPPUNIT_TEST(testExecute);
    CPPUNIT_TEST_SUITE_END();

    public:
        void testExecute();

};

#endif // PRINTINVENTORYTEST_H
