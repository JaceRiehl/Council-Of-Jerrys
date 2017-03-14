#include <vector>
#include <string>
#include "SaveData.h"
#include "XMLSaveDataTest.h"
#include "XMLLoadData.h"

int main()
{

    SaveData data;
    vector<string> inv = {"axe", "sword", "book"};
    vector<string> act = {"talked to...", "Searched..."};
    char* room = "garage";
    char* level = "01";

    data.inventoryItems = inv;
    data.playerActions = act;
    data.room = room;
    data.level = level;
    XMLSaveData saveFile;
    saveFile.saveData(data);

    SaveData inData;
    XMLLoadData loadTest;
    loadTest.loadData(inData);
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
