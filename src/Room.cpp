#include "Room.h"


    Room::Room(PlayableCharacter j, string n, UI& u, string i, vector<string> charKey, vector<Character> charMap, vector<string> itemKeys,
               vector<Item> itemMap)
    {
        jerry = j;
        intro = i;
        name = n;
        userInterface = u;
        charKeys = charKey;
        itemKeys = items;
        charMap = characterMap;
        itemMap = itemsMap;

        //Choices = {displayItems}

       for(int i = 0; i < charKeys; i++)
         {
             characters[charKeys[i]] = charMap[i];
         }

        //for(int i = 0; i < actionKeys; i++)
      //  {
      //      actions[actionKeys[i]] = actionMap[i];
      //  }


        for(int i = 0; i < itemKeys; i++)
        {
            availableItems[itemKeys[i]] = itemMap[i];
        }

    }

    string Room::run()
    {
        vector<string> introChoice = {};
        //void confirmation =
        userInterface.display(intro);

        do{
        //returns a, b, c, or d
        char userInput = userInterface.displayChoices(introChoices);
        //call the switch
        string finishedSenario inputSwitch(userInput);
        }while(finishedSenario == "continue");
    }

    string Room::inputSwitch(char input)
    {
            switch(input)
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
                            characters[charKeys[1]].getDialog();
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
            /*
        case "talk":
            action["talk"]-> exectute
            break;
        case "pickup":
            jerry.addItem
        }
        */


    }
    vector<string> Room::displayChoices(vector<string> input)
    {

    }
