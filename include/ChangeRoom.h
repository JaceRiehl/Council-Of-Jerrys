#ifndef CHANGEROOM_H
#define CHANGEROOM_H

#include "RoomAction.h"

class ChangeRoom : public RoomAction
{
    public:
        ChangeRoom(Character*, string, Room*, map<string, string> = {}, vector<string> = {}, vector<Item> = {});

        bool execute();
        bool execute(vector<string>);

    private:
        const string changeRoomKey = "change_room";
};

#endif // CHANGEROOM_H
