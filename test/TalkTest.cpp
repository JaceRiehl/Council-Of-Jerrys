#include "TalkTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TalkTest);

void TalkTest::testConstructor()
{
    Character* owner = new Character("Rick");
    NPC* subject = new NPC("Morty");

    Talk* talk = new Talk(owner, subject);

    CPPUNIT_ASSERT(owner == talk->getOwner());

    delete talk;
}

void TalkTest::testExecute()
{
    Character* owner = new Character("Rick");
    NPC* subject = new NPC("Morty");
    Item* item = new Item("meeseek_box");

    map<string, string> dialog;
    dialog["talk"] = "FUCK YOU MORTY!";

    subject->setDialog(dialog);

    Talk* talk2 = new Talk(owner, subject, item);

    talk2->execute();

    const Inventory* inv = talk2->getOwner()->getInventory();

    CPPUNIT_ASSERT(1 == inv->getSize());
    CPPUNIT_ASSERT(inv->searchName("meeseek_box"));

    delete talk2;
}

void TalkTest::testExecuteException()
{
    Character* owner = new Character("Rick");
    NPC* subject = nullptr;
    Item* item = new Item("meeseek_box");

    Talk* talk2 = new Talk(owner, subject, item);

    CPPUNIT_ASSERT_THROW(talk2->execute(), invalid_action);
}
