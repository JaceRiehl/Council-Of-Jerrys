#ifndef SEARCH_H
#define SEARCH_H

#include "CharacterAction.h"

class Search : public CharacterAction
{
    public:
        Search();
        Search(string);
        Search(string, string);
        Search(string, string, string);
        Search(string, string, string, string);
        virtual ~Search();

        virtual bool execute();

    private:
        string responseText;
        //Item* item;

};

#endif // SEARCH_H
