#include "RoomXMLParserTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(RoomXMLParserTest);

void RoomXMLParserTest::testConstructor()
{
    CouncilXMLParser *parser;

    CPPUNIT_ASSERT_NO_THROW(parser = new RoomXMLParser(testFilePath));
    CPPUNIT_ASSERT_THROW(parser = new RoomXMLParser("Gibberish.txt"), std::runtime_error);

    delete parser;
}

void RoomXMLParserTest::testLoadData()
{
    RoomXMLParser *parser = new RoomXMLParser(testFilePath);

    CPPUNIT_ASSERT(parser->loadData());

    vector<RoomData> data = parser->getData();

    CPPUNIT_ASSERT("Jerry's Garage" == data[0].name);

    vector<string> characters = data[0].characters;

    CPPUNIT_ASSERT("rick" == characters[0]);
    CPPUNIT_ASSERT("summer" == characters[1]);
    CPPUNIT_ASSERT("morty" == characters[2]);

    vector<string> actions = data[0].actions;

    CPPUNIT_ASSERT("search_fridge" == actions[0]);
    CPPUNIT_ASSERT("pickup_tool" == actions[1]);
    CPPUNIT_ASSERT("search_hole" == actions[2]);

    CPPUNIT_ASSERT("Jerry's Garage" == data[1].name);

    delete parser;
}

