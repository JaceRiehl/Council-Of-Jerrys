#include "CharacterAction.h"

CharacterAction::CharacterAction(Character* actionOwner, string key, NPC* actionSubject, vector<string> actionConditions, vector<Item> actionItems)
                                        : Action(actionOwner, key, actionConditions, actionItems), subject(actionSubject){}
CharacterAction::~CharacterAction()
{}

void CharacterAction::setSubject(NPC* actionSubject)
{
    subject = actionSubject;
}
