#ifndef CHARACTERDATA_H
#define CHARACTERDATA_H

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

/**
    @file CharacterData.h
    @author Nathan Tipper
    @date February 23, 2017
    @brief A struct to contain all the data that make up a Character
*/

struct CharacterData
{
    string name;
    vector<string> inventory;
    vector<string> actions;
    vector<string> conditions;
    int state;
};

#endif // CHARACTERDATA_H
