#include "PrintInventoryTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(PrintInventoryTest);

void PrintInventoryTest::testExecute()
{
    vector<Item> characterInventory = { Item("meeseek_box"), Item("hammer"), Item("screwdriver") };
    Character* mainChar = new Character("Jerry", characterInventory);

    string printKey = "print_inventory";
    vector<string> printConditions;
    vector<Item> printItems;

    Action* printInventory = new PrintInventory(mainChar, printKey, printConditions, printItems);

    printInventory->execute({});
}
