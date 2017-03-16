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

    Window window;
    if(!conditionsMet(playerActions))
    {
        if(context.find(conditionsMetKey) != context.end())
            window.display(context[conditionsNotMetKey], cout);
    }

    else
    {
        if(context.find(conditionsMetKey) != context.end())
            window.display(context[conditionsMetKey], cout);
        if(context.find(changeRoomKey) != context.end())
            subject->exit(context[changeRoomKey]);
        else
        {
            string errorMessage = "change_room context not set in room: " + key;
            throw invalid_action(errorMessage.c_str());
        }
    }

    return false;
}
