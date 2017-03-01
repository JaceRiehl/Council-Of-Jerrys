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
        *@param vector of Characters
        *@param map from string to Action
        */
        Situation(vector<Character>, map<string,Action>, int);
        /**
        *Used to take over execution of Level until the situation is over
        *@return String that can be used to represent the result of the situation
        */
        string run();




    private:
        /**
         *Reference to the main character, Jerry
         */
         PlayableCharacter& jerry;
         /**
         *Holds the current characters in the situation
         */
         vector<Character> characters;
         /**
         *Map of actions
         */
         map<string, Action> actions;
        /**
         *Index for loading game
         */
         int index;



};
#endif //SITUATION_H
