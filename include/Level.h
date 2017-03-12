#ifndef LEVEL_H
#define LEVEL_H

#include<string>
#include<vector>
#include<map>
#include "Room.h"

/**
*This is for building each of the levels and enacting on situations
*/
class Level
{
public:
    Level();

    /**
     *Constructor for level
     *@param string name of the level
     *@param map results of Rooms
     *@param vector of the Rooms in the level
     *@param opening message for the level
     */
    Level(string, PlayableCharacter&, map<string,Room*>, string = "");

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
     *Name of the level
     */
    string name;
    /**
     *Reference to Jerry
     */
     PlayableCharacter& jerry;
    /**
     *Vector of the situations that will be contained within the level
     */
     map<string, Room*> rooms;

    /**
     *State of the level
     */
    State state;


    string openingMessage;
    string nextRoom;
    const string terminatingString = "exit_level";
};

#endif
