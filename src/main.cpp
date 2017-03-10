#include <iostream>
#include <string>
#include "ConsoleInterface.h"
#include "Window.h"
using namespace std;

int main()
{
    string a = "hello", b = "Bye";
    vector<string> v;
    v.push_back(a);
    v.push_back(b);
    map<char, string> ma;
    ma['1'] = "this choice";
    ma['2'] = "that choice";
    ma['3'] = "or that";
    TextBox in("Intro2");
    Window window(in);
    window.display(a,ma, cout);
    /*
    PrintList noActions;
    PrintList actionOne({"talk", "attack", "leave"});
    PrintList talkTo({"Talk to Rick", "Talk to Summer", "Leave"});
    ConsoleInterface user;
    TextBox in("Intro2");
    TextBox two("first action in the game");
    TextBox three("Rick tells you to get lost");
    Window win(in);
    cout<<win;
    user.getEnterKey(cin);
    win.setTextBox(two);
    win.setPlayerChoice(actionOne);
    cout<<win;
    user.getChar(cin);
    win.setPlayerChoice(talkTo);
    cout<<win;
    user.getChar(cin);
    win.setTextBox(three);
    win.setPlayerChoice(noActions);
    cout<<win;
    user.getEnterKey(cin);
*/

    return 0;
}

/*
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

int main()
{
   // Get the top level suite from the registry
  CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( suite );

  // Change the default outputter to a compiler error format outputter
  runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
                                                       std::cerr ) );
  // Run the tests.
  bool wasSucessful = runner.run();

  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;
}
*/
