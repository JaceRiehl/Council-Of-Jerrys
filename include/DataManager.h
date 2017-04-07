#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "XMLSaveData.h"
#include "XMLLoadData.h"
#include "Level.h"
#include "FakeDataLoader.h"

class DataManager
{
    public:
        static DataManager* Instance();
        bool saveGameData();
        bool loadNewData(PlayableCharacter*);
        bool loadSaveData(PlayableCharacter*);

        map<string, Level*> loadGameData(PlayableCharacter*);
        map<string, string> loadEndGameText();

    protected:
        DataManager();
    private:
        static DataManager* _instance;
        FakeDataLoader* dataLoader;
        static void loadCharacter(PlayableCharacter*);
};

#endif // DATAMANAGER_H
