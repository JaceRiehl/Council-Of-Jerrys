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
        choices['3'] = "search";
        choices['4'] = "print";

        submenuOutput['1'] = "Rick";
        submenuOutput['2'] = "Summer";

        submenuChoices["talk"] = submenuOutput;

        map<string, string> rickDialog;
        rickDialog["talk"] = "FUCK YOU JERRY!";

        map<string, string> summerDialog;
        summerDialog["talk"] = "Get a job!";

        characters["Rick"] = new NPC("Rick");
        characters["Rick"]->setDialog(rickDialog);
        characters["Summer"] =  new NPC("Summer");
        characters["Summer"]->setDialog(summerDialog);

    }

    string Room::run()
    {

    string finishedScenario = "continue";

        do{
        GameWindow.display(intro, output, cout);
        char input = Inputting.getChar(cin);
        if(!checkStatus(input))
            break;

        finishedScenario = inputExecution(input);



        }while(state == running);
        return nextRoom;
    }

    string Room::inputExecution(char input)
    {
        firstInput = input;
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


            CharacterAction* charAction;

            if(charAction = dynamic_cast<CharacterAction*>(action))
                charAction->setSubject(characters[submenuOutput[secInput]]);

            jerry.takeAction(choices[firstInput]);
            //char c = Inputting.getChar(cin);
            //Inputting.getEnterKey(cin);

            return "continue";

        }
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

