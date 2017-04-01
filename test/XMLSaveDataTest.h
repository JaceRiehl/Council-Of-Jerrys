#ifndef XMLSAVEDATATEST_H
#define XMLSAVEDATATEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "XMLSaveData.h"
#include "SaveData.h"
#include <string>
#include <map>
/**
*Testing functions for the Window class
*/
class XMLSaveDataTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(XMLSaveDataTest);

    CPPUNIT_TEST(saveDataTest);

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void saveDataTest();
};
#endif // XMLSAVEDATATEST_H
