#include "ConsoleInterfaceTest.h"
#include "ConsoleInterface.h"
#include <iostream>
#include <sstream>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(ConsoleInterfaceTest);

void ConsoleInterfaceTest::setUp()
{
    ci = new ConsoleInterface();
}

void ConsoleInterfaceTest::tearDown()
{
    delete ci;
}

void ConsoleInterfaceTest::getCharTest()
{
    istringstream inString("a");
    CPPUNIT_ASSERT_EQUAL(ci->getChar(inString), 'a');
}

void ConsoleInterfaceTest::getStringTest()
{
    istringstream inString("Hello");
    CPPUNIT_ASSERT(ci->getString(inString) == "Hello");
}
