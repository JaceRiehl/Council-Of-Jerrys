#ifndef _ACTION_H
#define _ACTION_H

#include <string>

using std::string;

class Action
{
    public:
        Action(string);
        virtual ~Action() {};
        virtual bool executeAction(string) = 0;

    private:
        string name;

};

#endif // _ACTION_H
