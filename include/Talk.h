#ifndef TALK_H
#define TALK_H

#include "Action.h"

class Talk : public Action
{
    public:
        Talk(string);
        virtual ~Talk() {}

        bool executeAction(string);
};

#endif // TALK_H
