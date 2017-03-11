#include "RoomAction.h"

RoomAction::RoomAction(Character* charOwner, Room* actionSubject, string actionContext) : Action(charOwner)
{
    subject = actionSubject;
    context = actionContext;
}

RoomAction::~RoomAction()
{
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

const Room* RoomAction::getSubject() const
{
    return subject;
}

void RoomAction::setSubject(Room* actionSubject)
{
    subject = actionSubject;
}
