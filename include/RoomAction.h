#ifndef ROOMACTION_H
#define ROOMACTION_H

#include "Action.h"
#include "Room.h"

class RoomAction : public Action
{
    public:
        RoomAction(Character*, string, Room*, string = "", vector<string> = {}, vector<Item> = {});
        virtual ~RoomAction();

        virtual bool execute() = 0;

        virtual bool execute(vector<string>) = 0;

        string getContext() const;
        void setContext(string);

    protected:
        string context;
        Room* subject;

};

#endif // ROOMACTION_H
