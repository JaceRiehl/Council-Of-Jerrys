#ifndef TALK_H
#define TALK_H

#include "CharacterAction.h"

class Talk : public CharacterAction
{
    public:
        Talk();
        Talk(string);
        Talk(string, string);
        Talk(string, string, string);
        virtual ~Talk();

        bool execute();

    private:
        //Item* item;
};

#endif // TALK_H
