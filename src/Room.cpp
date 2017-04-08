#include "Room.h"

Room::Room(string roomKey, string roomIntro, map<string, NPC*> roomCharacters, map<string, Menu*> roomMenus)
    : key(roomKey), intro(roomIntro), characters(roomCharacters), menus(roomMenus)
{
    #ifdef RELEASE

    ioInfo = new IOInfo();

    #else

    ioInfo = new IOInfo("../data/roomTestOutput", "../data/roomTestInput.txt");

    #endif // DEBUG


}

Room::~Room(){}

string Room::run(PlayableCharacter* player)
{
    setPlayerActions(player);

    GameWindow.display(intro,ioInfo->getOutputStream());

    #ifdef RELEASE

    ioInfo->getOutputStream() << "Press Enter to continue... ";
    Inputting.getEnterKey(cin);

    #endif // RELEASE
    state = running;

    currentMenuKey = "top";
    lastMenuKey = "none";
    do
    {
        choice = "";
        Menu* currentMenu = menus[currentMenuKey];

        while(true)
        {
            if(lastMenuKey != currentMenuKey || currentMenuKey == "top")
            {
                currentMenu->print();
                lastMenuKey = currentMenuKey;
            }


            char input;

            ioInfo->getOutputStream() << "Please enter your choice: ";
            input = Inputting.getChar(ioInfo->getInputStream());


            if(!currentMenu->validInput(input))
                {
                    if(input == 'q')
                    {
                        state = done;
                        break;
                    }
                    GameWindow.display("Invalid Input! Please try again!", ioInfo->getOutputStream());
                    continue;
                }


            choice = currentMenu->input[input];

            if(menus.find(currentMenu->input[input]) == menus.end())
                break;

            choice += "_";
            currentMenuKey = currentMenu->input[input];
            currentMenu = menus[currentMenuKey];
        }

        try
        {
            player->takeAction(choice);
        }

        catch(keyDoesNotExist e)
        {
            GameWindow.display(e.what(), cout);
        }

        catch(invalid_action inv)
        {
            GameWindow.display(inv.what(), cout);
        }
    }while(state == running);
    return nextRoom;
}


void Room::setPlayerActions(PlayableCharacter* player)
{
    player->setActions(actions);
}

string Room::getCharacterName()
{
    return jerry->getName();
}

void Room::exit(string destination)
{
    #ifdef RELEASE
    if(destination == key)
    {
        currentMenuKey = "top";
        return;
    }
    #endif // RELEASE

    nextRoom = destination;
    state = done;
}

