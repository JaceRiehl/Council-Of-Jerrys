#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

Character::Character(string name) : name(name){}

Character::Character(string name, Inventory* inventory, map<string, Action*> actions): name(name), inventory(inventory), actions(actions){}


