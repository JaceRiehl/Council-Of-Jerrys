#include "Search.h"

Search::Search() : CharacterAction() {}

Search::Search(string name) : CharacterAction(name) {}

Search::Search(string name, string owner) : CharacterAction(name, owner) {}

Search::Search(string name, string owner, string subject) : CharacterAction(name, owner, subject) {}

Search::Search(string name, string owner, string subject, string responseText) : CharacterAction(name, owner, subject)
{
    this->responseText = responseText;
}

Search::~Search() {}

bool Search::execute()
{
    // If PlayableCharacter

    // Give the PlayableCharacter an Item if item is not empty.
    // Print off response text.
}
