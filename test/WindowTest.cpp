#include "WindowTest.h"
#include "Window.h"
#include "ConsoleInterface.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

CPPUNIT_TEST_SUITE_REGISTRATION(WindowTest);

void WindowTest::setUp()
{
    ma['a'] = "three";
    ma['b'] = "four";
    tb1 = new TextBox("TextBox one");
    tb2 = new TextBox("TexBox two");
    pl1 = new PrintList(vector<string>{"one", "two"});
    pl2 = new PrintList(ma);
    win1 = new Window(*tb1);
    win2 = new Window(*tb2);
    win3 = new Window(*tb1, *pl1);
}

void WindowTest::tearDown()
{
    delete tb1;
    delete tb2;
    delete pl1;
    delete pl2;
    delete win1;
    delete win2;
    delete win3;
}

void WindowTest::setTextBoxTest()
{
    win1->setTextBox(*tb2);//comment out "system("clear")" in Window.cpp for testing
    str1 << *win1;
    str2 << *win2;
    CPPUNIT_ASSERT(str1.str() == str2.str());
}

void WindowTest::setPlayerChoiceTest()
{
    win1->setPlayerChoice(*pl1);
    str1 << *win1;
    str2 << *win3;
    CPPUNIT_ASSERT(str1.str() == str2.str());
}

void WindowTest::visualTest()
{
    cout<<endl<<*win3;
}

void WindowTest::concept()
{
    string intro = "Intro", first = "First", sec = "Sec";
    Window window(TextBox(intro));
    ConsoleInterface user;
    cout<<window;

}
