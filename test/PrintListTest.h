#ifndef PRINTLISTTEST_H
#define PRINTLISTTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "PrintList.h"
#include <string>
/**
*Testing functions for the PrintList class
*/
class PrintListTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(PrintListTest);

    CPPUNIT_TEST(emptyConstructorTest);
    CPPUNIT_TEST(vectorConstructorTest);
    CPPUNIT_TEST(mapConstructorTest);
    CPPUNIT_TEST(isEmptyTest);
    CPPUNIT_TEST(assignmentOpTest);

    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

        /**
        *Test the empty constructor
        */
        void emptyConstructorTest();
        /**
        *Test the constructor using a vector list of strings
        */
        void vectorConstructorTest();
        /**
        *Test the constructor using a map list of strings
        */
        void mapConstructorTest();
        /**
        *Test the isEmpty function
        */
        void isEmptyTest();
        /**
        *Test the = operator
        */
        void assignmentOpTest();

    private:
        stringstream str1, str2;
        vector<string> v;
        map<char, string> ma;
        PrintList *pl1, *pl2, *pl3;
};
#endif //PRINTLISTTEST_H
