#ifndef CONSOLEINTERFACETEST_H
#define CONSOLEINTERFACETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "ConsoleInterface.h"
#include <string>
#include <sstream>
/**
*Testing functions for the Window class
*/
class ConsoleInterfaceTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ConsoleInterfaceTest);

    CPPUNIT_TEST(getCharTest);
    CPPUNIT_TEST(getStringTest);

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void getCharTest();
    void getStringTest();

private:
    ConsoleInterface *ci;
    stringstream str1;

};

#endif //CONSOLEINTERFACETEST_H
