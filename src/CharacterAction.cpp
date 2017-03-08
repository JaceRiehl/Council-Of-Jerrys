#include "CharacterAction.h"

CharacterAction::CharacterAction() : Action()
{
    subject = "";
}

CharacterAction::CharacterAction(string name) : Action(name) {}

CharacterAction::CharacterAction(string name, string owner) : Action(name, owner) {}

CharacterAction::CharacterAction(string name, string owner, string subject) : Action(name, owner)
{
    this->subject = subject;
}

CharacterAction::~CharacterAction() {}

void CharacterAction::setSubject(string name)
{
    subject = name;
}
