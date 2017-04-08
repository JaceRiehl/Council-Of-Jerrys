#ifndef ACTION_H
#define ACTION_H
#include "Character.h"
#include "Exceptions.h"
#include <vector>

using std::vector;

class Action
{
    public:
        /**
            @brief A constructor for the Action class that takes a Character*.
            @pre A valid character is given.
            @post The owner of the Action is set to the Character.
            @param The Character who will be the owner of the Action.
            @return None.
        */
        Action(Character*, string, vector<string> = {}, vector<Item> = {});
        virtual ~Action();

        /**
            @brief execute to allow for a list of player conditions to be passed
        */
        virtual bool execute(vector<string>) = 0;

        /**
            @brief Accessor method for the owner of the Action.
            @pre None.
            @post The owner of the Action is returned.
            @param None.
            @return The owner of the Action.
        */
        const Character* getOwner() const;

        const string getKey() const { return key; }

    protected:
        bool conditionsMet(vector<string>) const;
        void giveItems(vector<string>);
        bool beenTaken(vector<string>) const;

        string defaultKey = "default";

        Character* owner;
        vector<string> conditions;
        vector<Item> items;
        string key;

        IOInfo* ioInfo;

    private:
        bool conditionsEmpty() const;
        bool itemsEmpty() const;

};

#endif // ACTION_H
