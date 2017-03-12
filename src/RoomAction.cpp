#include "RoomAction.h"

RoomAction::RoomAction(Character* charOwner, Room* actionSubject, string actionContext) : Action(charOwner)
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

