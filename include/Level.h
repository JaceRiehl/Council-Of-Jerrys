#ifndef LEVEL_H
#define LEVEL_H

#include<string>
#include<vector>
#include<map>
#include "Room.h"

/**
*This is for buildiing each of the levels and enacting on situations
*/
class Level
{
public:
    /**
     *Constructor for level
     *@param string name of the level
     *@param map results of Rooms
     *@param vector of the Rooms in the level
     */
    Level(PlayableCharacter&, string, vector<Room>);

    /**
     *Takes over the execution from the main until the situation is over
     *@return result of running the level
     */
     string run();

    /**
     *Enumeration for the state of the level
     */
     enum State { RUNNING, PAUSED, FINISHED };

    /**
     *Getter for state
     *@return State of the level
     */
     int returnState();

    /**
     *Getter for the name of the level
     *@return Level name
     */
     string getName();



private:

    /**
     *Vector of the situations that will be contained within the level
     */
     vector<Room> rooms;

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
     PlayableCharacter* jerry;

     string openingMessage;
};

#endif
