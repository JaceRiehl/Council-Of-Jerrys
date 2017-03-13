#ifndef ROOMACTION_H
#define ROOMACTION_H

#include "Action.h"
#include "Room.h"

class RoomAction : public Action
{
    public:
        RoomAction(Character*, string, Room*, map<string, string> = {}, vector<string> = {}, vector<Item> = {});
        virtual ~RoomAction();

        const map<string,string> getContext() const;

    protected:
        map<string, string> context;
        Room* subject;

};

#endif // ROOMACTION_H
