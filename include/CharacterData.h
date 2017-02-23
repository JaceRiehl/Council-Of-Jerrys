#ifndef CHARACTERDATA_H
#define CHARACTERDATA_H

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

struct CharacterData
{
    public:
        string name;
        vector<string> inventory;
        vector<string> actions;
        vector<string> conditions;
        int state;
};

#endif // CHARACTERDATA_H
