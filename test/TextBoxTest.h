#ifndef TEXTBOXTEST_H
#define TEXTBOXTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "TextBox.h"
#include <string>
/**
*Testing functions for the TextBox class
*/
class TextBoxTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TextBoxTest);

    CPPUNIT_TEST(extractionOpTest);
    CPPUNIT_TEST(assignmentOpTest);
    CPPUNIT_TEST(visualTest);

    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

        void extractionOpTest();
        void assignmentOpTest();
        /**
        *No an actual test, used to manually see screen output and determine if it
        *is giving the expected output.
        */
        void visualTest();

    private:
        std::string testStr1;
        TextBox *tb1, *tb2, *tb3;

};
#endif  //TEXTBOXTEST_H
