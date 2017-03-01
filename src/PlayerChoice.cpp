#include "PlayerChoice.h"
#include <string>
#include <vector>
#include <iostream>

PlayerChoice::PlayerChoice(std::vector<std::string> c) : plyrActions(c) {}

PlayerChoice::~PlayerChoice() {}

void PlayerChoice::print()
{
    for(int i = 0; i < plyrActions.size(); i++)
        std::cout<<i+1<<')'<<plyrActions[i]<<std::endl;
}
