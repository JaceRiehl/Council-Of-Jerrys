#include "Room.h"


    Room::Room(PlayableCharacter& j) : jerry(j)
    {
        GameWindow.display(intro, cout);
        state = running;

        output['1'] = "Talk: ";
        output['2'] = "Search: ";
        output['3'] = "Exit Room: ";
        output['4'] = "Print inventory: ";

        choices['1'] = "talk";
        choices['2'] = "search";
        choices['3'] = "exit_room";
        choices['4'] = "print";
        Menu* topMenu = new Menu(intro, output, choices);

        submenuTalkOutput['1'] = "Rick";
        submenuTalkOutput['2'] = "Summer";

        string talkMenuText = "Who would you like to talk to?: ";
        submenuTalkInput['1'] = "rick";
        submenuTalkInput['2'] = "summer";
        Menu* talkSubMenu = new Menu(talkMenuText, submenuTalkOutput, submenuTalkInput);
        menus["top"] = topMenu;
        menus["talk"] = talkSubMenu;

        map<string, string> rickDialog;
        rickDialog["talk"] = "FUCK YOU JERRY!";

        map<string, string> summerDialog;
        summerDialog["talk"] = "Get a job!";

        characters["Rick"] = new NPC("Rick");
        characters["Rick"]->setDialog(rickDialog);
        characters["Summer"] =  new NPC("Summer");
        characters["Summer"]->setDialog(summerDialog);

        map<string,Action*> actions;
        Action* rickTalkAction = new Talk(&jerry, characters["Rick"]);
        actions["talk_rick"] = rickTalkAction;
        Action* summerTalkAction = new Talk(&jerry, characters["Summer"]);
        actions["talk_summer"] = summerTalkAction;

        jerry.setActions(actions);
    }

    string Room::run()
    {
        string finishedScenario = "continue";

        do
        {
            choice = "";
            Menu* currentMenu = menus["top"];

            while(true)
            {
                currentMenu->print();
                char input = Inputting.getChar(cin);

                if(!currentMenu->validInput(input))
                    {
                        GameWindow.display("Invalid Input! Please try again!", cout);
                        continue;
                    }


                choice += currentMenu->input[input];

                if(menus.find(currentMenu->input[input]) == menus.end())
                    break;

                choice += "_";
                currentMenu = menus[currentMenu->input[input]];
            }

            try
            {
                jerry.takeAction(choice);
            }

            catch(keyDoesNotExist e)
            {
                GameWindow.display(e.what(), cout);
            }
        }while(state == running);
        return nextRoom;
    }

    string Room::inputExecution(char input)
    {
        firstInput = input;

    }

    bool Room::checkStatus(char input)
    {
        if(choices.find(input) == choices.end())
            {
                if(input == 'q')
                    return false;
            }
        return true;
    }


string Room::getCharacterName()
{
    return jerry.getName();
}

const Inventory* Room::getCharacterInv()
{
    return jerry.getInventory();
}

void Room::exit(string destination)
{
    nextRoom = destination;
    state = done;
}

/*        firstInput = input;
        if(submenuChoices.find(choices[firstInput]) == submenuChoices.end())
        {
            jerry.takeAction(choices[firstInput]);
            return "continue";
        }
        else
        {
            //string subChoice = choices[firstInput];
            //map<char,string> sub = submenuChoices[subChoice];
            //PrintList Sub(submenuOutput);

            //gameWindow.setPlayerChoice(Sub);
            GameWindow.display(choices[firstInput], submenuOutput, cout);
            Action* action;

            char secInput = Inputting.getChar(cin);
            if(submenuChoices.find(choices[firstInput]) != submenuChoices.end())
            {
                map<string,Action*> actions = jerry.getActions();
                action = actions[choices[firstInput]];
            }


            //CharacterAction* charAction;

            if((charAction = dynamic_cast<CharacterAction*>(action)))
                charAction->setSubject(characters[submenuOutput[secInput]]);

            jerry.takeAction(choices[firstInput]);
            char c = Inputting.getChar(cin);
            //Inputting.getEnterKey(cin);

            return "continue";

        }
        */
