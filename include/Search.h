#ifndef SEARCH_H
#define SEARCH_H

#include "RoomAction.h"

class Search : public RoomAction
{
    public:
        Search(Character*, string, Room*, map<string, string> = {},  vector<string> = {}, vector<Item> = {});
        virtual ~Search();

        virtual bool execute();

        virtual bool execute(vector<string>);

    private:
        const string conditionsNotMetKey = "conditions_not_met";
        const string conditionsMetKey = "conditions_met";
        const string searchedKey = "searched";
};

#endif // SEARCH_H
