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
        *Used to run the situation
        *@return String that can be used to represent the result of the situation
        */
        string run();
        /**
        *Initalization of the player into the situation
        */
        void init();



    private:
         string jerry = "my name is jerry";
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
