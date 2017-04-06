#ifndef GAMERUNNER_H
#define GAMERUNNER_H

#include "PlayableCharacter.h"
#include "DataManager.h"

class GameRunner
{
    public:
        GameRunner();

    private:
        PlayableCharacter* mainChar;
        DataManager* dManager;
        string nextLevel;
        void init();


};

#endif // GAMERUNNER_H
