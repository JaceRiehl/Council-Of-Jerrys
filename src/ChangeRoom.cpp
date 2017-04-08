#include "ChangeRoom.h"

ChangeRoom::ChangeRoom(Character* charOwner, string key, Room* actionSubject, map<string, string> actionContext, vector<string> actionConditions, vector<Item> actionItems)
        : RoomAction(charOwner, key, actionSubject, actionContext, actionConditions, actionItems)
{
    #ifdef DEBUG

    ioInfo = new IOInfo("./data/searchChangeRoomOutput.txt", "");

    #endif // DEBUG
}

bool ChangeRoom::execute(vector<string> playerActions)
{
    if(!subject)
        throw invalid_action("Subject is null!");

    Window window;
    if(!conditionsMet(playerActions))
    {
        if(context.find(conditionsMetKey) != context.end())
            window.display(context[conditionsNotMetKey], ioInfo->getOutputStream());
    }

    else
    {
        if(context.find(conditionsMetKey) != context.end())
            window.display(context[conditionsMetKey], ioInfo->getOutputStream());
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
