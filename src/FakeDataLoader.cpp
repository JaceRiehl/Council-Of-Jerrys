#include "FakeDataLoader.h"

map<string, Level> FakeDataLoader::LoadLevels()
{
    mainChar = new PlayableCharacter("Jerry");

    string room1Key = "jerrys_garage";
    string room1Intro = "On a summer day in the hot August heat, you’ve finally reached the back of the moving truck. There’s "
                        "not much room left in the house, so you decide to bring the last remaining boxes to the garage. Upon "
                        "entering the garage, you notice that the previous owners didn’t bother to clean the garage from their "
                        "belongings. Looks like you’ll have to clean this mess up yourself. There’s a broken down shelving unit "
                        "sitting on top of a worn out carpet to the far right of the room, and a few crates are sitting collecting "
                        "dust in the left corner of the room.";
    map<string, NPC*> room1Characters;

    map<string, Action*> room1Actions;

    string menuOutput = "What would you like to do?: ";

    map<char, string> room1TopMenuOutput;
    room1TopMenuOutput['1'] = "Move crates";
    room1TopMenuOutput['2'] = "Move shelving unit";
    room1TopMenuOutput['3'] = "Move carpet";

    map<char, string> room1TopMenuInput;
    room1TopMenuInput['1'] = "search_crate";
    room1TopMenuInput['2'] = "search_shelf";
    room1TopMenuInput['3'] = "move_carpet";

    Menu* topMenu = new Menu(menuOutput, room1TopMenuOutput, room1TopMenuInput);

    map<string, Menu*> room1Menus;
    room1Menus["top"] = topMenu;

    Room* room1 = new Room(room1Key, room1Intro, room1Characters, room1Menus);
    // Make action parameters
    string crateSearchKey = "search_crate";
    map<string, string> crateSearchContext;
    crateSearchContext["conditions_met"] = "You’ve found a pile of coins of what seems like a foreign currency. A crown bearing jellybean is "
                                           "portrayed on each side of the coins with the word ‘Smeckmle’ engraved at the bottom. Wow, what a "
                                           "score this’ll make in your coin collection!";

    crateSearchContext["searched"] = "There doesn't seem to be anything here.";

    unsigned int numberOfShmekles = 25;

    vector<Item> scmekles;

    for(unsigned int i = 0; i < numberOfShmekles; ++i)
    {
        scmekles.push_back(Item("smeckle"));
    }

    vector<string> crateSearchConditions;

    Action* crateSearch = new Search(mainChar, crateSearchKey, room1, crateSearchContext, crateSearchConditions, scmekles);

    room1Actions[crateSearch->getKey()] = crateSearch;

    string shelfSearchKey = "search_shelf";
    map<string, string> shelfSearchContext;
    shelfSearchContext["conditions_met"] = "As you wrap your arms around the shelving unit, a diary topples over. You don’t think you should read "
                                           "someone else’s personal diary, but having to clean someone else’s mess as made you feel somewhat "
                                           "rebellious, so you open it. Most of its content is filled with gibberish mathematical equations but the "
                                           "last entry stands out, it reads - “These posers discovered the combination to my safe, I HAD to make "
                                           "them pay. Anyway, time to change it now; maybe I’ll use the year Doc Brown took Marty back in time. "
                                           "God, Back to the Future is such a great movie!”. This seems like an odd man, you think to yourself. "
                                           "Anyhow, you finish moving the shelving unit and discard the diary.";

    crateSearchContext["searched"] = "There doesn't seem to be anything here.";

    vector<Item> items;

    vector<string> shelfSearchConditions;

    Action* shelfSearch = new Search(mainChar, shelfSearchKey, room1, shelfSearchContext, shelfSearchConditions, items);

    room1Actions[shelfSearch->getKey()] = shelfSearch;

    string changeRoomCarpetKey = "change_room_under_garage";

    //Level level1;
}
