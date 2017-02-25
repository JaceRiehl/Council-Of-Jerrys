#ifndef SITUATION_H
#define SITUATION_H

#include<string>
#include<vector>
#include<map>
/**
*This class is to generate situations within different Levels of the game
*/

class Situation
{
    public:
        /**
        *Constructor for Situation
        */
        Situation();
        /**
        *Used to take over execution of Level until the situation is over
        *@return String that can be used to represent the result of the situation
        */
        string run();




    private:
         PlayableCharacter& jerry;
         /**
         *Holds the current characters in the situation
         */
         //vector<Character> characters;
         /**
         *Map of actions
         */
         map<string, Action> actions;



};
#endif //SITUATION_H
