#include "Talk.h"

#include <iostream>

using std::cout;
using std::endl;

Talk::Talk() : CharacterAction() {}

Talk::Talk(string name) : CharacterAction(name) {}

Talk::Talk(string name, string subject) : CharacterAction(name, subject) {}

Talk::Talk(string name, string subject, string agent) : CharacterAction(name, subject, agent) {}

Talk::~Talk() {}

bool Talk::execute()
{

}
