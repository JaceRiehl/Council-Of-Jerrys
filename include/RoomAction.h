#ifndef ROOMACTION_H
#define ROOMACTION_H

#include "Action.h"
#include "Room.h"

class RoomAction : public Action
{
    public:
        RoomAction(Character*, string, Room*, string = "", vector<string> = {}, vector<Item> = {});
        virtual ~RoomAction();

        string getContext() const;
        void setContext(string);

    protected:
        string context;
        Room* subject;

};

#endif // ROOMACTION_H
