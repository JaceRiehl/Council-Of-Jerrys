#ifndef FAKEDATALOADER_H
#define FAKEDATALOADER_H

#include "Level.h"
#include "NPC.h"
#include "Menu.h"
#include "Search.h"
#include "ChangeRoom.h"
#include "Talk.h"
#include "PrintInventory.h"
#include "SaveAndExit.h"

class FakeDataLoader
{
    public:
        static FakeDataLoader* Instance();
        static Room* buildFakeRoom(PlayableCharacter*);
        void LoadLevels(PlayableCharacter*, map<string, Level*>&);
        void LoadEndOfGameText(map<string, string>&);
    protected:
        FakeDataLoader();
    private:
        static FakeDataLoader* _instance;
        static Room* fakeRoom;
};

#endif // FAKEDATALOADER_H
