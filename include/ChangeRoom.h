#ifndef CHANGEROOM_H
#define CHANGEROOM_H

#include "RoomAction.h"

class ChangeRoom : public RoomAction
{
    public:
        ChangeRoom(Character*, Room*, string = "");

        bool execute();

};

#endif // CHANGEROOM_H
