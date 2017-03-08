#include "Talk.h"

#include <iostream>

using std::cout;
using std::endl;

Talk::Talk() : CharacterAction() {}

Talk::Talk(string name) : CharacterAction(name) {}

Talk::Talk(string name, string subject) : CharacterAction(name, subject) {}

Talk::Talk(string name, string owner, string subject) : CharacterAction(name, owner, subject) {}

Talk::~Talk() {}

bool Talk::execute()
{

}
