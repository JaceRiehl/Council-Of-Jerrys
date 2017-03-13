#ifndef SEARCH_H
#define SEARCH_H

#include "RoomAction.h"

class Search : public RoomAction
{
    public:
        Search(Character*, string, Room*, string = "",  vector<string> = {}, vector<Item> = {});
        virtual ~Search();

        virtual bool execute();

        virtual bool execute(vector<string>);

    private:
        string responseText;
};

#endif // SEARCH_H
