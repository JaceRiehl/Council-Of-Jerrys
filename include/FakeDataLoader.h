#ifndef FAKEDATALOADER_H
#define FAKEDATALOADER_H

#include "Level.h"
#include "NPC.h"
#include "Menu.h"
#include "Search.h"

class FakeDataLoader
{
    public:
        map<string, Level> LoadLevels();
        PlayableCharacter* mainChar;
};

#endif // FAKEDATALOADER_H
