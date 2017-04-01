#include <iostream>
#include <vector>
#include <map>
#include "FakeDataLoader.h"
#include "Window.h"
#include "PlayableCharacter.h"
#include "XMLSaveData.h"

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

int main()
{
    #ifdef RELEASE
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

            XMLSaveData::Data.level = nextLevel.c_str();
            Level * currentLevel = levels[nextLevel];
            nextLevel = currentLevel->run(mainCharacter);
        }

        string endOfGameMessage;

        if(gameOverKey == "sneak_death")
        {
            endOfGameMessage = "You decide to wait till nighttime and scale the castle walls to sneak-in without the guard noticing. You "
                                        "start climbing. Everything is going great, you’ve almost cleared the wall when you suddenly lose your "
                                        "grip and fall to the ground. You break both your legs. The guards come rushing to investigate the "
                                        "commotion  - “Castle scalars will not be tolerated in King Jelly Bean’s land. Off with your head! \". - "
                                        "GAME OVER!";
        }

        else if(gameOverKey == "death_by_snowball")
        {
            endOfGameMessage ="\"You saved my life 'Jerry'. Your actions will not be forgotten. However, no humans can be allowe d"
                                "to live, and your species must be extinct. Good bye Jerry.\" - GAME OVER";
        }

        else if(gameOverKey == "assertive_death")
        {
            endOfGameMessage = "\"Rudeness will not be tolerated in king Jelly Bean’s land. Off with your head!\" - GAME OVER";
        }

        else if(gameOverKey == "failed_assassination")
        {
            endOfGameMessage = "\"Your reign is over King Jelly Bean – hand the crown over or die fighting for it! I will not let these "
                                "villagers I’ve just met die for nothing at your hand.”. The king snaps his fingers and ten guards rush to "
                                "the throne room. \"Bravery will not be tolerated in King Jelly Bean’s land. Off with your head!\" - GAME OVER";
        }

        else if(gameOverKey == "king_jerry")
        {
            endOfGameMessage = "\"Your reign is over King Jelly Bean – hand the crown over or I will expose you for tax evasion! I will "
                                "not let these villagers I’ve just met die for nothing at your hand.\" You spoke with a new found confidence."
                                "\"Who are you?! How have you heard of this information I’ve loudly spoken about five minutes ago?!\""
                                "\"What will you do of me? The Legion of Kings cannot find of this treason – I will be eaten alive! Have "
                                "mercy for an old Jellybean.\""
                                "\"The name’s Jerry. King Jerry. Now leave this land and never return.\""
                                "\"As you wish... my King.” the jellybean grudgingly spoke.\""
                                "And so begins the reign of... KING... JERRY!";
        }
        splashScreen.display(endOfGameMessage, cout);
    }

    #else
    {
        // Get the top level suite from the registry
        CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

        // Adds the test to the list of test to run
        CppUnit::TextUi::TestRunner runner;
        runner.addTest( suite );

        // Change the default outputter to a compiler error format outputter
        runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
                                                           std::cerr ) );
        // Run the tests.
        bool wasSucessful = runner.run();

        // Return error code 1 if the one of test failed.
        return wasSucessful ? 0 : 1;
    }
    #endif // RELEASE
    return 0;
}
