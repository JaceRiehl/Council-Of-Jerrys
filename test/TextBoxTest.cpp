#include "TextBoxTest.h"
#include "TextBox.h"
#include <string>
#include <sstream>
#include <iomanip>

CPPUNIT_TEST_SUITE_REGISTRATION(TextBoxTest);

void TextBoxTest::setUp()
{
    testStr1 = "This is test string one";
    tb1 = new TextBox(testStr1);
    tb2 = new TextBox(testStr1);
    tb3 = new TextBox("Hello");
    tb4 = new TextBox;
    testFile = new ofstream("../data/textboxTestOutput");
}

void TextBoxTest::tearDown()
{
    delete tb1;
    delete tb2;
    delete tb3;
    delete tb4;
}

void TextBoxTest::defaultConstructorTest()
{
    CPPUNIT_ASSERT(tb4->isEmpty());
}

void TextBoxTest::extractionOpTest()
{
    str1 << *tb1;
    str2 << *tb2;
    CPPUNIT_ASSERT(str1.str() == str2.str());
}

void TextBoxTest::assignmentOpTest()
{
    *tb1 = *tb3;
    str1 << *tb1;
    str2 << *tb3;
    CPPUNIT_ASSERT(str1.str() == str2.str());
}

void TextBoxTest::assignTextTest()
{
    tb2->assignText("Hello");
    str1 << *tb2;
    str2 << *tb3;
    CPPUNIT_ASSERT(str1.str() == str2.str());
}
void TextBoxTest::visualTest()
{
    *testFile<<endl<<*tb1;
}
