#include "RoomAction.h"

RoomAction::RoomAction(Character* charOwner, string key, Room* actionSubject, map<string, string> actionContext, vector<string> actionConditions, vector<Item> actionItems)
        : Action(charOwner, key, actionConditions, actionItems)
{
    subject = actionSubject;
    context = actionContext;
}

RoomAction::~RoomAction()
{
    if(subject)
        delete subject;
}

const map<string, string> RoomAction::getContext() const
{
    return context;
}

