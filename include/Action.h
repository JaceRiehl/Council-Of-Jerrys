#ifndef ACTION_H
#define ACTION_H

#include <string>

using std::string;

class Action
{
    public:
        Action();
        Action(string);
        Action(string, string);
        virtual ~Action() {};
        virtual bool execute() = 0;

    protected:
        string owner;
        //Character* owner;

    private:
        string name;

};

#endif // ACTION_H
