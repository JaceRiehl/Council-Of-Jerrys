#ifndef FAKEDATALOADER_H
#define FAKEDATALOADER_H

#include "Level.h"
#include "NPC.h"
#include "Menu.h"
#include "Search.h"
#include "ChangeRoom.h"
#include "Talk.h"

class FakeDataLoader
{
    public:
        void LoadLevels(PlayableCharacter*, map<string, Level*>&);
};

#endif // FAKEDATALOADER_H
