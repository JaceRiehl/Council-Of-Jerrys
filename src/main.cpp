#include <iostream>
#include <vector>
#include <map>
#include "FakeDataLoader.h"
#include "Window.h"
#include "PlayableCharacter.h"

using namespace std;

int main()
{
    PlayableCharacter* mainCharacter = new PlayableCharacter("jerry");
    string gameOverKey;
    map<string, Level*> levels;
    FakeDataLoader levelData;
    string nextLevel = "intro";
    int choice;
    bool validInput = false;
    string title = "                    Jerry's Adventures!";
    vector<string> startMenu = {"New Game", "Continue", "Exit"};
    Window splashScreen;
    splashScreen.display(title, startMenu, cout);
    cout<<endl<<"Enter your choice: ";
    while(!validInput)
    {
        cin>>choice;
        if(choice == 1 || choice == 2 || choice ==3)
            validInput = true;
        else
            validInput = false;
        if(!validInput)
            cout<<"Invalid input, try again: ";
    }
    switch (choice)
    {
        case 1 : /*new game*/;break;
        case 2 : /*load data*/;break;
        case 3 : system("clear");exit(0);
    }

    if(choice == 1)
    {
        levelData.LoadLevels(mainCharacter, levels);
    }

    while(true)
    {
        if(levels.find(nextLevel) == levels.end())
        {
            gameOverKey = nextLevel;
            break;
        }
        Level * currentLevel = levels[nextLevel];
        nextLevel = currentLevel->run(mainCharacter);
    }

    if(gameOverKey == "sneak_death")
    {
        string endOfGameMessage = "You decide to wait till nighttime and scale the castle walls to sneak-in without the guard noticing. You "
                                    "start climbing. Everything is going great, you’ve almost cleared the wall when you suddenly lose your "
                                    "grip and fall to the ground. You break both your legs. The guards come rushing to investigate the "
                                    "commotion  - “Castle scalars will not be tolerated in King Jelly Bean’s land. Off with your head! ”. - "
                                    "GAME OVER!";

        Window window;
        window.display(endOfGameMessage, cout);
    }
}
