#ifndef WINDOWTEST_H
#define WINDOWTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Window.h"
#include <string>
#include <map>
/**
*Testing functions for the Window class
*/
class WindowTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(WindowTest);

    CPPUNIT_TEST(setTextBoxTest);
    CPPUNIT_TEST(setPlayerChoiceTest);
    CPPUNIT_TEST(displayStringTest);
    CPPUNIT_TEST(displayWithVectorTest);
    CPPUNIT_TEST(displayWithMapTest);
    //CPPUNIT_TEST(visualTest);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    /**
    *Testing the setTextBox function
    */
    void setTextBoxTest();
    /**
    *Testing the setPlayerChoice function
    */
    void setPlayerChoiceTest();
    /**
    *Testing the display(string, ostream) function
    */
    void displayStringTest();
    /**
    *Testing the display(string, vector, ostream) function
    */
    void displayWithVectorTest();
    /**
    *Testing the display(string, map, ostream) function
    */
    void displayWithMapTest();
    /**
    *Not an actual test, used to manualy inspect the output to console
    */
    void visualTest();

private:
    Window *win1, *win2, *win3;
    TextBox *tb1, *tb2;
    PrintList *pl1, *pl2;
    stringstream str1, str2;
    map<char, string> ma;


};

#endif //WINDOWTEST_H
