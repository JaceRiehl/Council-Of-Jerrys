#include "NPC.h"
#include "Character.h"
#include "Exceptions.h"

NPC::NPC(string name) : Character(name){}

NPC::NPC(string name, vector<Item> inv) : Character(name, inv) {}

string NPC::getDialog(string key)
{
    if(dialog.find(key) == dialog.end())
    {
        string errorMessage = "Dialog does not exist with key: " + key;
        throw keyDoesNotExist(errorMessage.c_str());
    }

    return dialog[key];
}

void NPC::setDialog(map<string, string> dialog)
{
    this->dialog = dialog;
}

