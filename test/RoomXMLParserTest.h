#ifndef ROOMXMLPARSERTEST_H
#define ROOMXMLPARSERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "RoomXMLParser.h"

/**
*   @file RoomXMLParserTest.h
*   @author Nathan Tipper
*   @date February 27, 2017
*   @brief Test suite for the RoomXMLParser.
*/

class RoomXMLParserTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(RoomXMLParserTest);
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
        const string testFilePath = "../data/roomTestData.xml";
};

#endif // ROOMXMLPARSERTEST_H
