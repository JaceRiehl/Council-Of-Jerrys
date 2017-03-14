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
            break;
        Level * currentLevel = levels[nextLevel];
        nextLevel = currentLevel->run(mainCharacter);
    }
}
