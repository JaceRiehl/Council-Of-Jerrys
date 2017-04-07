#ifndef PRINTINVENTORY_H
#define PRINTINVENTORY_H

#include "Action.h"
#include "Window.h"

class PrintInventory : public Action
{
    public:
        PrintInventory(Character*, string key, vector<string> = {}, vector<Item> = {});

        bool execute();
        bool execute(vector<string>);
};

#endif // PRINTINVENTORY_H
