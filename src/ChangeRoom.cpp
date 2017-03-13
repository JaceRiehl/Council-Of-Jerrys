#include "ChangeRoom.h"

ChangeRoom::ChangeRoom(Character* charOwner, string key, Room* actionSubject, map<string, string> actionContext, vector<string> actionConditions, vector<Item> actionItems)
        : RoomAction(charOwner, key, actionSubject, actionContext, actionConditions, actionItems) {}

bool ChangeRoom::execute()
{
    if(!subject)
        throw invalid_action("Subject is null!");

    subject->exit(context[changeRoomKey]);
}

bool ChangeRoom::execute(vector<string> playerActions)
{
    if(!subject)
        throw invalid_action("Subject is null!");

    subject->exit(context[changeRoomKey]);
    return true;
}
