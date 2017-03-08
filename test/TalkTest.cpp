#include "TalkTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TalkTest);

void TalkTest::testConstructor()
{
    Character* owner = new Character("Rick"), *subject = new NPC("Morty");

    Talk* talk = new Talk(owner, subject);

    CPPUNIT_ASSERT(owner == talk->getOwner());

    delete talk;
}

void TalkTest::testExecute()
{
    Character* owner = new Character("Rick"), *subject = new NPC("Morty");
    Item* item = new Item("meeseek_box");

    Talk* talk2 = new Talk(owner, subject, item);

    talk2->execute();

    CPPUNIT_ASSERT(1 == talk2->getOwner()->getInventory()->getSize());

    delete talk2;
}
