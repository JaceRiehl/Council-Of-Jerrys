#ifndef CHANGEROOM_H
#define CHANGEROOM_H

#include "RoomAction.h"

class ChangeRoom : public RoomAction
{
    public:
        ChangeRoom(Character*, string, Room*, string = "", vector<string> = {}, vector<Item> = {});

        bool execute();
        bool execute(vector<string>);
};

#endif // CHANGEROOM_H
