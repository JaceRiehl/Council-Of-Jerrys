#include "PlayableCharacter.h"

PlayableCharacter::PlayableCharacter(string name) : Character(name){}

PlayableCharacter::PlayableCharacter(string name, vector<Item> inv) : Character(name, inv) {}

PlayableCharacter::PlayableCharacter(PlayableCharacter& pc) : Character(pc)
{
    this->actions = pc.getActions();
}

void PlayableCharacter::setActions(map<string, Action*> actions)
{
    this->actions = actions;
}

map<string, Action*> PlayableCharacter::getActions() const
{
    return actions;
}

void PlayableCharacter::takeAction(string action)
{
    if(actions.find(action) == actions.end())
    {
        string errorMessage = "Playable Character does not have action with key: " + action;
        throw keyDoesNotExist(errorMessage.c_str());
    }

    actions[action]->execute();
}

void PlayableCharacter::addAction(string key, Action* value)
{
    actions[key] = value;
}

void PlayableCharacter::addAction(map<string, Action*> actionsToAdd)
{
    for(const auto& kv : actionsToAdd)
    {
        actions[kv.first] = kv.second;
    }
}
