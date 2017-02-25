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
    Level(string, map, vector);

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

private:

    /**
     *Map for the results of the current situation
     */
     map<string,string> situationReults;

    /**
     *Vector of the situations that will be contained within the level
     */
     vector<Situation> situations;

    /**
     *Name of the level
     */
    string name;

    /**
     *State of the level
     */
    State state;

    /**
     *Reference to Jerry
     */
     PlayableCharacter& jerry;
};
