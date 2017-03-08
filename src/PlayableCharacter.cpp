#include "PlayableCharacter.h"

PlayableCharacter::PlayableCharacter(string name) : Character(name){}

PlayableCharacter::PlayableCharacter(string name, vector<Item> inv) : Character(name, inv) {}

void PlayableCharacter::setActions(map<string, Action*> actions)
{
    this->actions = actions;
}

void PlayableCharacter::takeAction(string action)
{
    if(actions.find(action) == actions.end())
        throw keyDoesNotExist(strcat("Playable Character does not have action with key: ", action.c_str()));

    actions[action]->execute();
}
