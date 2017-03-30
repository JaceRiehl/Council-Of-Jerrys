#ifndef ROOMDATA_H
#define ROOMDATA_H

#include <vector>

using std::vector;

struct RoomData
{
    string name;
    vector<string> characters;
    vector<string> actions;
};

#endif // ROOMDATA_H
