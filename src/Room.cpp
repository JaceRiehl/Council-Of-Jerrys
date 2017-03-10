#include "Room.h"


    Room::Room(PlayableCharacter& j) : jerry(j)
    {
        GameWindow.display(intro, cout);

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

        characters["Rick"] = new NPC("Rick");
        characters["Summer"] =  new NPC("Summer");

    }

    int Room::run()
    {

    string finishedScenario = "continue";

        do{
        //clear the screen and put a new template up

        //call vinces input to find out the char chosen

        //if(submenuChoices.find(choices[firstInput]) == submenuChoices.end())
        GameWindow.display(intro, output, cout);
        char input = Inputting.getChar(cin);
        finishedScenario = inputExecution(input);



        }while(finishedScenario == "continue");
        //test value
        int room = 1;
        return room;
    }

    string Room::inputExecution(char input)
    {
        firstInput = input;
        if(submenuChoices.find(choices[firstInput]) == submenuChoices.end())
        {
            jerry.takeAction(choices[firstInput]);
            //not sure about the return statement for exit room
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
            if(submenuChoices.find(choices[firstInput]) == submenuChoices.end())
            {
                map<string,Action*> actions = jerry.getActions();
                action = actions[choices[firstInput]];
            }

            if(typeid(CharacterAction) == typeid(action))
            {
            CharacterAction* charAction = dynamic_cast<CharacterAction*>(action);
            charAction->setSubject(characters[submenuOutput[secInput]]);
            }

            jerry.takeAction(choices[firstInput]);

            return "Continue";

        }
    }


           /* switch(input)
            {
            //case for talking to character
            case 'a':
                {
                    //intakes vector returns character a or b (need to make sure its a or b)
                    secondInput = userInterface.display(charKeys);
                    switch(secondInput)
                    {
                        //first character in vector(linear)
                    case 'a':
                        {
                            /*
                            if(characters[charKeys[0]].getRiddle() != " ")
                            {
                                string ans = characters[charKeys[0]].getRiddleAnswer();
                                string riddle = characters[charKeys[0]].getRiddle();
                                string userAnswer = " ";
                                while(ans =! userAnswer || userAnswer != "stop")
                                {
                                     //inputs string, returns string, have "Type stop to stop"
                                    userAnswer = userInterface.displayRiddle(riddle));
                                    if(ans == userAnswer)
                                        jerry.addItem(items[itemKeys[0]]);
                                }
                            }


                        }
                        //talking to second character (linear)
                    case 'b':
                        {
                            //characters[charKeys[1]].getDialog();
                        }

                    }
                }
            //case for searching surroundings?
            case 'b':


            //case for switching rooms
            case 'c':

            //case for printing inventory
            case 'd':
                jerry.printItems();

            }
     */



