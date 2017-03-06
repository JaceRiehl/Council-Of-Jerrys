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

/*

#include "Window.h"
#include "PrintList.h"
#include "ConsoleInterface.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using std::cout;
using std::endl;

int main()
{
    ConsoleInterface user;
    string text, a, b, c, d, aa, bb, st;
    char z;
    text = "Hello this is some text to try out how this thing will work i have no Idea what I am doing. this is getting weird Jerry!!!!!! oh well we will keep writing text to see what happends blah blah blassda. What if i keep adding text and more text and keep on writing text, IM FREAKING OUT!!!! holy crap what is going on??";
    a = "talk";
    b = "Search";
    c = "Leave";
    aa = "Talk to Rick";
    bb = "talk to Summer";
    vector<string> actn;
    actn.push_back(a);
    actn.push_back(b);
    actn.push_back(c);
    map<char, string> ma;
    ma['1'] = "Hello";
    ma['b'] = "Bye";
    PrintList listActions(actn);
    vector<string> subAction;
    subAction.push_back(aa);
    subAction.push_back(bb);
    TextBox testing(text);
    TextBox tt(a);
    Window window(testing, listActions);
    //window.setPlayerChoice(listActions);
    window.print();
    user.getEnterKey();
    window.setTextBox(tt);
    window.print();
     user.getEnterKey();
    //st = user.getString();
    return 0;

}
*/
