#ifndef GAMERUNNER_H
#define GAMERUNNER_H

#include <iostream>
#include <limits>
#include "PlayableCharacter.h"
#include "DataManager.h"

using std::numeric_limits;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

class GameRunner
{
    public:
        GameRunner();
        void run();
    private:
        PlayableCharacter* mainChar;
        DataManager* dManager;
        string nextLevel;
        void init();
        void printMainMenu();
        char getInput();
        void runGame();
        map<string, Level*> gameData;
        map<string, string> endOfGameText;

        static constexpr char NEW_GAME = '1';
        static constexpr char LOAD_GAME = '2';
        static constexpr char EXIT_GAME = '3';
};

#endif // GAMERUNNER_H
