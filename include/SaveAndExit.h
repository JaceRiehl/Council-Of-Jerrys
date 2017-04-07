#ifndef SAVEANDEXIT_H
#define SAVEANDEXIT_H

#include "RoomAction.h"

class SaveAndExit : public RoomAction
{
    public:
        SaveAndExit(Character*, string, Room*, map<string, string> = {}, vector<string> = {}, vector<Item> = {});

        bool execute();
        bool execute(vector<string>);
    private:
        const string EXIT_STRING = "save_and_exit";
};

#endif // SAVEANDEXIT_H
