#include "PrintListTest.h"
#include "PrintList.h"
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

CPPUNIT_TEST_SUITE_REGISTRATION(PrintListTest);

void PrintListTest::setUp()
{
    v.push_back("one");
    v.push_back("two");
    ma['a'] = "three";
    ma['b'] = "four";
    pl1 = new PrintList();
    pl2 = new PrintList(v);
    pl3 = new PrintList(ma);
}

void PrintListTest::tearDown()
{
    delete pl1;
    delete pl2;
    delete pl3;
}

void PrintListTest::emptyConstructorTest()
{
    str1 << *pl1;
    CPPUNIT_ASSERT(str1.str() == "");
}

void PrintListTest::vectorConstructorTest()
{
    str1 << *pl2;
    str2 << "1) one" << endl << "2) two" << endl;
    CPPUNIT_ASSERT(str1.str() == str2.str());
}

void PrintListTest::mapConstructorTest()
{
    str1 << *pl3;
    str2 << "a)three" << endl << "b)four" << endl;
    CPPUNIT_ASSERT(str1.str() == str2.str());
}

void PrintListTest::isEmptyTest()
{
    CPPUNIT_ASSERT_EQUAL(true, pl1->isEmpty());
    CPPUNIT_ASSERT_EQUAL(false, pl2->isEmpty());
    CPPUNIT_ASSERT_EQUAL(false, pl3->isEmpty());
}

void PrintListTest::assignmentOpTest()
{
    *pl1 = *pl3;
    str1 << *pl1;
    str2 << "a)three" << endl << "b)four" << endl;
    CPPUNIT_ASSERT(str1.str() == str2.str());
}




