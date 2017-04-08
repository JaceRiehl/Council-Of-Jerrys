#include "SaveAndExit.h"

SaveAndExit::SaveAndExit(Character* owner, string key, Room* room, map<string, string> actionContext, vector<string> conditions, vector<Item> items)
                        : RoomAction(owner, key, room, actionContext, conditions, items) {}

bool SaveAndExit::execute(vector<string> playerActions)
{
    if(!XMLSaveData::saveData())
        cerr << "ERROR: Could not save data!" << endl;

    subject->exit(EXIT_STRING);
    return false;
}
