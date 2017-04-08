#ifndef CHANGEROOM_H
#define CHANGEROOM_H

#include "RoomAction.h"

class ChangeRoom : public RoomAction
{
    public:
        ChangeRoom(Character*, string, Room*, map<string, string> = {}, vector<string> = {}, vector<Item> = {});

        bool execute(vector<string>);

    private:
        const string changeRoomKey = "change_room";
        const string conditionsNotMetKey = "conditions_not_met";
        const string conditionsMetKey = "conditions_met";
};

#endif // CHANGEROOM_H
