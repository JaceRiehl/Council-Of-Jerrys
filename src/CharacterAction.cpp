#include "CharacterAction.h"

CharacterAction::CharacterAction(Character* actionOwner) : Action(actionOwner), subject(nullptr) {}

CharacterAction::CharacterAction(Character* actionOwner, Character* actionSubject) : Action(actionOwner), subject(actionSubject) {}
CharacterAction::~CharacterAction()
{
    if(subject != nullptr)
        delete subject;
}

void CharacterAction::setSubject(Character* actionSubject)
{
    subject = actionSubject;
}
