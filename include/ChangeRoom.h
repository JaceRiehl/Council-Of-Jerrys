#ifndef CHANGEROOM_H
#define CHANGEROOM_H

#include "RoomAction.h"

class ChangeRoom : public RoomAction
{
    public:
        /**
        @brief Constructor for the change room class
        @pre Information about the character and the room is given
        @post None
        @return None
        */
        ChangeRoom(Character*, string, Room*, map<string, string> = {}, vector<string> = {}, vector<Item> = {});

        bool execute(vector<string>);

    private:
        const string changeRoomKey = "change_room";
        const string conditionsNotMetKey = "conditions_not_met";
        const string conditionsMetKey = "conditions_met";
};

#endif // CHANGEROOM_H
