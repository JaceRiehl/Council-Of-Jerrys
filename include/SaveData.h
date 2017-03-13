#ifndef SAVEDATA_H
#define SAVEDATA_H
#include <vector>
#include <string>
using namespace std;

struct SaveData
{
    vector<string> inventoryItems;
    vector<string> playerActions;
    const char* level;
    const char* room;
};

#endif // SAVEDATA_H
