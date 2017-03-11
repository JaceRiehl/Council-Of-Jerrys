#include "ChangeRoom.h"

ChangeRoom::ChangeRoom(Character* charOwner, Room* actionSubject, string actionContext) : RoomAction(charOwner, actionSubject, actionContext) {}

bool ChangeRoom::execute()
{
    if(!subject)
        throw invalid_action("Subject of the action is not valid!");
}
