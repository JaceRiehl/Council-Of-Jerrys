#ifndef TEXTBOXTEST_H
#define TEXTBOXTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "TextBox.h"
#include <string>
#include <fstream>

/**
*Testing functions for the TextBox class
*/
class TextBoxTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TextBoxTest);

    CPPUNIT_TEST(defaultConstructorTest);
    CPPUNIT_TEST(extractionOpTest);
    CPPUNIT_TEST(assignmentOpTest);
    CPPUNIT_TEST(visualTest);
    CPPUNIT_TEST(assignTextTest);

    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

        /**
        *Test the default constructor assigns the empty string
        */
        void defaultConstructorTest();
        /**
        *Test the << operator
        */
        void extractionOpTest();
        /**
        *Test the = operator
        */
        void assignmentOpTest();
        /**
        *assignText() is used everytime the constructor iscalled,
        *this tests it exclusivly
        */
        void assignTextTest();
        /**
        *No an actual test, used to manually see screen output and determine if it
        *is giving the expected output.
        */
        void visualTest();

    private:
        std::string testStr1;
        std:: stringstream str1, str2;
        TextBox *tb1, *tb2, *tb3, *tb4;
        ofstream* testFile;

};
#endif  //TEXTBOXTEST_H
