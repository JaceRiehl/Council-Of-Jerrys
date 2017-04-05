#ifndef FAKEDATALOADER_H
#define FAKEDATALOADER_H

#include "Level.h"
#include "NPC.h"
#include "Menu.h"
#include "Search.h"
#include "ChangeRoom.h"
#include "Talk.h"
#include "PrintInventory.h"

class FakeDataLoader
{
    public:
        static FakeDataLoader* Instance();
        void LoadLevels(PlayableCharacter*, map<string, Level*>&);
    protected:
        FakeDataLoader();
    private:
        static FakeDataLoader* _instance;
};

#endif // FAKEDATALOADER_H
