#ifndef SAVEDATA_H
#define SAVEDATA_H
#include <vector>
#include <string>
using namespace std;

struct SaveData
{
    vector<string> inventoryItems;
    vector<string> playerActions;
    string level;
    string room;
};

#endif // SAVEDATA_H
