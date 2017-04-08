#include "PrintInventory.h"

#include <iostream>

PrintInventory::PrintInventory(Character* actionOwner, string key, vector<string> actionConditions, vector<Item> actionItems) :
    Action(actionOwner, key, actionConditions, actionItems)
{
    #ifdef DEBUG

    ioInfo = new IOInfo("../data/printInventoryTestOutput", "");

    #endif // DEBUG
}

bool PrintInventory::execute() {}

bool PrintInventory::execute(vector<string> playerActions)
{
    const Inventory* inventory = owner->getInventory();
    if(inventory)
    {
        // TODO: Make printItems use window!
        std::cout << std::endl;
        inventory->printItems();
        std::cout << std::endl;
    }
    else
    {
        Window window;
        window.display("Empty",ioInfo->getOutputStream());
    }


}
