#include "PlayableCharacter.h"
#include "Character.h"

PlayableCharacter::PlayableCharacter(string name) : Character(name){}

PlayableCharacter::PlayableCharacter(string name, vector<Item> inv) : Character(name, inv) {}
/*
void PlayableCharacter::setActions(map<string, Action> actions)
{
    this->actions = actions;
}
void PlayableCharacter::takeAction(string action, Character* character)
{

}
*/
