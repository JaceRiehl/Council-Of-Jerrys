#include "RoomAction.h"

#include <iostream>
using std::cout;
using std::endl;

RoomAction::RoomAction(Character* charOwner, string key, Room* actionSubject, map<string, string> actionContext, vector<string> actionConditions, vector<Item> actionItems)
        : Action(charOwner, key, actionConditions, actionItems)
{
    subject = actionSubject;
    context = actionContext;

    for(const auto& ss_pair : context)
    {
        cout << ss_pair.first << ": " << ss_pair.second << endl;
    }
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

