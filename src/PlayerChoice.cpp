#include "PlayerChoice.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>

PlayerChoice::PlayerChoice() {}

//PlayerChoice::PlayerChoice(std::map<char, string> c) {}

PlayerChoice::PlayerChoice(std::vector<std::string> c) : plyrActions(c) {}

PlayerChoice::~PlayerChoice() {}

void PlayerChoice::operator=(PlayerChoice& p)
{
    this->plyrActions = p.plyrActions;
}

bool PlayerChoice::isEmpty()
{
    if(plyrActions.size() > 0)
        return false;
    return true;
}

void PlayerChoice::print()
{
    if(!isEmpty())
        for(int i = 0; i < plyrActions.size(); i++)
            std::cout<<i+1<<')'<<plyrActions[i]<<std::endl;
}
//void PlayerChoice::print(std::map<char, string>)


