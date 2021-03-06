#include "PlayableCharacterTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(PlayableCharacterTest);

void PlayableCharacterTest::testTakeAction()
{
    PlayableCharacter* playChar = new PlayableCharacter("Morty");
    NPC* subject = new NPC("Rick");
    Item* item = new Item("meeseek_box");

    map<string, string> dialog;
    dialog["talk"] = "FUCK YOU RICK!";
    subject->setDialog(dialog);

    vector<string> conditions;
    vector<Item> items = { *item };

    Talk* talkAction = new Talk(playChar, "talk", subject, conditions, items);

    map<string, Action*> actions;

    actions["talk"] = talkAction;

    playChar->setActions(actions);

    playChar->takeAction("talk");

    const Inventory* inv = playChar->getInventory();

    CPPUNIT_ASSERT(inv->searchName("meeseek_box"));
}
