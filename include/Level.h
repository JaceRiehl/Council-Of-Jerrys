#ifndef LEVEL_H
#define LEVEL_H

#include<string>
#include<vector>
#include<map>

/**
*This is for buildiing each of the levels and enacting on situations
*/
class Level
{
public:
    /**
     *Constructor for level
     *@param string name of the level
     *@param map results of situation
     *@param vector of the situations in the level
     */
    Level(string, vector, string);

    /**
     *Takes over the execution from the main until the situation is over
     *@return result of running the level
     */
     string run();

    /**
     *Enumeration for the state of the level
     */
     enum State(RUNNING, PAUSED, FINISHED);

    /**
     *Getter for state
     *@return State of the level
     */
     State returnState();

    /**
     *Getter for the name of the level
     *@return Level name
     */
     string getName();



private:

    /**
     *Vector of the situations that will be contained within the level
     */
     vector<Situation> situations;

    /**
     *Vector of the situations that will be contained within the level
     */
     vector<string> situationResults;

    /**
     *Name of the level
     */
    string name;

     /**
     *Opening message displayed to user when the level starts
     */
    string openingMessage;

    /**
     *State of the level
     */
    State state;

    /**
     *Reference to Jerry
     */
     PlayableCharacter& jerry;
};
