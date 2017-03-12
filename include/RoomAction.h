#ifndef ROOMACTION_H
#define ROOMACTION_H

#include "Action.h"
#include "Room.h"

class RoomAction : public Action
{
    public:
        RoomAction(Character*, Room*, string = 0);
        virtual ~RoomAction();

        virtual bool execute() = 0;

        string getContext() const;
        void setContext(string);

        const Room* getSubject() const;
        void setSubject(Room*);

    protected:
        string context;
        Room* subject;

};

#endif // ROOMACTION_H
