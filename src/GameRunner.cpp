#include "GameRunner.h"

GameRunner::GameRunner()
{
    init();
}

void GameRunner::init()
{
    dManager = DataManager::Instance();
    mainChar = new PlayableCharacter("Jerry");

    gameData = dManager->loadGameData(mainChar);
    endOfGameText = dManager->loadEndGameText();
}

void GameRunner::printMainMenu()
{
    string title = "                    Jerry's Adventures!";
    vector<string> startMenu = {"New Game", "Continue", "Exit"};
    Window splashScreen;
    splashScreen.display(title, startMenu, cout);
}

char GameRunner::getInput()
{
    string choice;

    cout << endl << "Please enter your choice: ";
    cin.sync();
    getline(cin, choice);
    //std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

    return choice[0];
}

void GameRunner::run()
{
    while(true)
    {
        printMainMenu();

        bool validInput = false;
        do
        {
            char choice = getInput();

            switch (choice)
                {
                    case NEW_GAME:
                        if(dManager->loadNewData(mainChar))
                            validInput = true;
                        else
                            cerr << "ERROR: Could not load data." << endl;
                        break;

                    case LOAD_GAME:
                        if(dManager->loadSaveData(mainChar))
                            validInput = true;
                        else
                            cerr << "ERROR: Could not load data." << endl;
                        break;

                    case EXIT_GAME:
                        validInput = true;
                        system("clear");
                        exit(0);
                        break;

                    default:
                        cout << choice << " is not a valid input. Please try again." << endl << endl;
                        break;
                }
        } while(!validInput);

        nextLevel = XMLSaveData::Data.level;
        gameData[nextLevel]->setStartingRoom(XMLSaveData::Data.room);

        runGame();

        Window gameWindow;
        gameWindow.display(endOfGameText[nextLevel], cout);
    }
}

void GameRunner::runGame()
{
    while(true)
    {
        if(gameData.find(nextLevel) == gameData.end())
            break;

        XMLSaveData::Data.level = nextLevel.c_str();
        Level * currentLevel = gameData[nextLevel];
        currentLevel->setStartingRoom(XMLSaveData::Data.room);
        nextLevel = currentLevel->run(mainChar);
    }
}
