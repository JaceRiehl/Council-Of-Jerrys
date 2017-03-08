#include "NPCTest.h"
#include "Exceptions.h"

CPPUNIT_TEST_SUITE_REGISTRATION(NPCTest);

void NPCTest::testGetSetDialog()
{
    map<string, string> newDialog;
    NPC* testNPC = new NPC("Morty", {Item("magic_seed")});

    string talkDialog = "What the hell are we doing, Rick? I mean, come on man.";
    string kickDialog = "Dad! What the hell!";

    newDialog["talk"] = talkDialog;
    newDialog["kick"] = kickDialog;

    testNPC->setDialog(newDialog);

    CPPUNIT_ASSERT(talkDialog == testNPC->getDialog("talk"));
    CPPUNIT_ASSERT(kickDialog == testNPC->getDialog("kick"));

    delete testNPC;
}

void NPCTest::testKeyDoesntExistException()
{
    map<string, string> newDialog;
    NPC* testNPC = new NPC("Morty", {Item("magic_seed")});

    string talkDialog = "What the hell are we doing, Rick? I mean, come on man.";
    string kickDialog = "Dad! What the hell!";

    newDialog["talk"] = talkDialog;
    newDialog["kick"] = kickDialog;

    testNPC->setDialog(newDialog);

    CPPUNIT_ASSERT_THROW(testNPC->getDialog("flash"), keyDoesNotExist);

    delete testNPC;
}
