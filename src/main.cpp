#include <iostream>
#include <vector>
#include <map>
#include "FakeDataLoader.h"
#include "Window.h"
#include "PlayableCharacter.h"

using namespace std;

int main()
{
    PlayableCharacter* mainCharacter;
    map<string, Level*> levels;
    FakeDataLoader levelData;
    int choice;
    bool validInput = false;
    string title = "                    Jerry's Adventures!";
    vector<string> startMenu = {"New Game", "Continue", "Exit"};
    Window splashScreen;
    splashScreen.display(title, startMenu, cout);
    cout<<endl<<"Enter your choice: ";
    while(!validInput)
    {
        cin>>choice;
        if(choice == 1 || choice == 2 || choice ==3)
            validInput = true;
        else
            validInput = false;
        if(!validInput)
            cout<<"Invalid input, try again: ";
    }
    switch (choice)
    {
        case 1 : /*new game*/;break;
        case 2 : /*load data*/;break;
        case 3 : system("clear");exit(0);
    }

    if(choice == 1)
    {
        levelData.LoadLevels(mainCharacter, levels);
    }



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
