#include "RoomAction.h"

RoomAction::RoomAction(Character* charOwner, string key, Room* actionSubject, string actionContext, vector<string> actionConditions, vector<Item> actionItems)
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

string RoomAction::getContext() const
{
    return context;
}

void RoomAction::setContext(string actionContext)
{
    context = actionContext;
}

