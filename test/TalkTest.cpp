#include "TalkTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TalkTest);

void TalkTest::testConstructor()
{
    Character* owner = new Character("Rick");
    NPC* subject = new NPC("Morty");

    Talk* talk = new Talk(owner, "talk_morty", subject);

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

    vector<string> conditions;
    vector<Item> items = { *item };

    Talk* talk2 = new Talk(owner, "talk_morty", subject, conditions, items);

    vector<string> playerActions;

    talk2->execute(playerActions);

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

    vector<string> conditions;
    vector<Item> items = { *item };

    Talk* talk2 = new Talk(owner, "talk_null", subject, conditions, items);

    CPPUNIT_ASSERT_THROW(talk2->execute(), invalid_action);

    delete talk2;
}

void TalkTest::testPlayerActionConditions()
{
    Character* owner = new Character("Rick");
    NPC* subject = new NPC("Morty");
    Item* item = new Item("meeseek_box");

    vector<string> conditions = { "sex_bot" };
    vector<Item> items = { *item };

    vector<string> playerActions { "sex_bot" };

    map<string, string> dialog;
    dialog["talk"] = "FUCK YOU MORTY!";

    subject->setDialog(dialog);

    Talk* talk2 = new Talk(owner, "talk_morty", subject, conditions, items);

    talk2->execute(playerActions);

    const Inventory* inv = talk2->getOwner()->getInventory();

    CPPUNIT_ASSERT(inv != nullptr);
    CPPUNIT_ASSERT(1 == inv->getSize());
    CPPUNIT_ASSERT(inv->searchName("meeseek_box"));

    delete talk2;
}

void TalkTest::testPlayerItemConditions()
{
    Character* owner = new Character("Rick");
    NPC* subject = new NPC("Morty");
    Item* item = new Item("meeseek_box");
    Item* item2 = new Item("real_fake_door");

    owner->addItem(*item2);

    vector<string> conditions = { "real_fake_door" };
    vector<Item> items = { *item };

    vector<string> playerActions;

    map<string, string> dialog;
    dialog["talk"] = "FUCK YOU MORTY!";

    subject->setDialog(dialog);

    Talk* talk2 = new Talk(owner, "talk_morty", subject, conditions, items);

    talk2->execute(playerActions);

    const Inventory* inv = talk2->getOwner()->getInventory();

    CPPUNIT_ASSERT(inv != nullptr);

    CPPUNIT_ASSERT(inv->searchName("meeseek_box"));

    delete talk2;
}
