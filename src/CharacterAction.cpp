#include "CharacterAction.h"

CharacterAction::CharacterAction(Character* actionOwner) : Action(actionOwner), subject(nullptr) {}

CharacterAction::CharacterAction(Character* actionOwner, NPC* actionSubject) : Action(actionOwner), subject(actionSubject){}
CharacterAction::~CharacterAction()
{
    if(subject != nullptr)
        delete subject;
}

void CharacterAction::setSubject(NPC* actionSubject)
{
    subject = actionSubject;
}
