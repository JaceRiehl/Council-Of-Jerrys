#include "CharacterDataParserTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CharacterDataParserTest);

void CharacterDataParserTest::testConstructor()
{
    CouncilXMLParser *parser;

    CPPUNIT_ASSERT_NO_THROW(parser = new CharacterDataParser(testFilePath));
    CPPUNIT_ASSERT_THROW(parser = new CharacterDataParser("Gibberish.txt"), std::runtime_error);

    delete parser;
}

void CharacterDataParserTest::testLoadData()
{
    CharacterDataParser *parser = new CharacterDataParser(testFilePath);

    CPPUNIT_ASSERT(parser->loadData());

    vector<CharacterData> data = parser->getData();

    CPPUNIT_ASSERT("Jerry" == data[0].name);

    vector<string> actions = data[0].actions;

    CPPUNIT_ASSERT("talk" == actions[0]);
    CPPUNIT_ASSERT("give_item" == actions[1]);
    CPPUNIT_ASSERT("battle" == actions[2]);

    vector<string> inventory = data[0].inventory;

    CPPUNIT_ASSERT("portal_gun" == inventory[0]);
    CPPUNIT_ASSERT("meeseek_box" == inventory[1]);
    CPPUNIT_ASSERT("inception_earpiece" == inventory[2]);

    CPPUNIT_ASSERT_EQUAL(0, data[0].state);

    CPPUNIT_ASSERT("Jerry" == data[1].name);

    delete parser;
}
