#ifndef CHARACTERDATAPARSERTEST_H
#define CHARACTERDATAPARSERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "CharacterDataParser.h"

class CharacterDataParserTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(CharacterDataParserTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST_SUITE_END();

    public:
        /**
        *
        */
        void testConstructor();
};

#endif // CHARACTERDATAPARSERTEST_H
