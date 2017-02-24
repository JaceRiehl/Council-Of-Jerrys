#ifndef CHARACTERDATAPARSERTEST_H
#define CHARACTERDATAPARSERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "CharacterDataParser.h"

/**
*   @file CharacterDataParserTest.h
*   @author Nathan Tipper
*   @date February 23, 2017
*   @brief Test suite for the CharacterDataParser.
*/

class CharacterDataParserTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(CharacterDataParserTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testLoadData);
    CPPUNIT_TEST_SUITE_END();

    public:
        /**
        *   @brief Tests to see if an runtime_error is thrown if given a invalid file path
        *   and it is not thrown if given a valid file path.
        */
        void testConstructor();

        /**
        *   @brief Tests to see if all data loaded from testFilePath is the values that
        *   are expected.
        */
        void testLoadData();

    private:
        const string testFilePath = "../data/characterTestData.xml";
};

#endif // CHARACTERDATAPARSERTEST_H
