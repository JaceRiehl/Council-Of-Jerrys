#include "Room.h"


    Room::Room(PlayableCharacter& j) : jerry(j)
    {
        state = running;

        map<char, string> output;

        output['1'] = "Talk: ";
        output['2'] = "Search: ";
        output['3'] = "Exit Room: ";
        output['4'] = "Print inventory: ";

        map<char, string> input;

        input['1'] = "talk";
        input['2'] = "search";
        input['3'] = "change_room";
        input['4'] = "print";
        Menu* topMenu = new Menu(intro, output, input);

        map<char, string> submenuTalkOutput;
        submenuTalkOutput['1'] = "Rick";
        submenuTalkOutput['2'] = "Summer";

        map<char, string> submenuTalkInput;
        submenuTalkInput['1'] = "rick";
        submenuTalkInput['2'] = "summer";

        string talkMenuText = "Who would you like to talk to?: ";

        Menu* talkSubMenu = new Menu(talkMenuText, submenuTalkOutput, submenuTalkInput);
        menus["top"] = topMenu;
        menus["talk"] = talkSubMenu;

        string changeRoomText = "Which room would you like to go to?: ";
        map<char, string> changeRoomOutput;
        changeRoomOutput['1'] = "Town";
        changeRoomOutput['2'] = "Bar";
        changeRoomOutput['3'] = "Exit Level";

        map<char,string> changeRoomInput;
        changeRoomInput['1'] = "town";
        changeRoomInput['2'] = "bar";
        changeRoomInput['3'] = "exit_level";

        Menu* changeRoomSubMenu = new Menu(changeRoomText, changeRoomOutput, changeRoomInput);
        menus["change_room"] = changeRoomSubMenu;


        map<string, string> rickDialog;
        rickDialog["talk"] = "FUCK YOU JERRY!";

        map<string, string> summerDialog;
        summerDialog["talk"] = "Get a job!";

        characters["Rick"] = new NPC("Rick");
        characters["Rick"]->setDialog(rickDialog);
        characters["Summer"] =  new NPC("Summer");
        characters["Summer"]->setDialog(summerDialog);

        map<string,Action*> actions;
        Action* rickTalkAction = new Talk(&jerry, "talk_rick", characters["Rick"]);
        actions["talk_rick"] = rickTalkAction;
        Action* summerTalkAction = new Talk(&jerry, "talk_summer", characters["Summer"]);
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
                        if(input == 'q')
                        {
                            state = done;
                            break;
                        }
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

            catch(invalid_action inv)
            {
                GameWindow.display(inv.what(), cout);
            }
        }while(state == running);
        cout << "RETURNING: " + nextRoom << endl;
        return nextRoom;
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
