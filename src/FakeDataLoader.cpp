#include "FakeDataLoader.h"

void FakeDataLoader::LoadLevels(PlayableCharacter* mainChar, map<string, Level*> &levels)
{
    map<string, Room*> rooms;

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
    room1TopMenuInput['3'] = "change_room_under_garage";

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
                                           "last entry stands out, it reads - \“These posers discovered the combination to my safe, I HAD to make "
                                           "them pay. Anyway, time to change it now; maybe I’ll use the year Doc Brown took Marty back in time. "
                                           "God, Back to the Future is such a great movie!\”. This seems like an odd man, you think to yourself. "
                                           "Anyhow, you finish moving the shelving unit and discard the diary.";

    crateSearchContext["searched"] = "There doesn't seem to be anything here.";

    vector<Item> crateSearchItems;

    vector<string> shelfSearchConditions;

    Action* shelfSearch = new Search(mainChar, shelfSearchKey, room1, shelfSearchContext, shelfSearchConditions, crateSearchItems);

    room1Actions[shelfSearch->getKey()] = shelfSearch;

    string changeRoomCarpetKey = "change_room_under_garage";

    map<string, string> changeRoomCarpetContext;
    changeRoomCarpetContext["conditions_met"] = "You’ve discarded the carpet and uncovered a trap door. Da na na naaaaaaaaa! ";

    changeRoomCarpetContext["conditions_not_met"] = "You have back pain and weak knees. You can’t move the carpet with the shelving unit on. This reminds "
                                                    "you of how weak and all alone you are and you start to feel sad.";

    vector<Item> changeRoomCarpetItems;

    vector<string> changeRoomCarpetConditions = { "search_shelf" };

    Action* changeRoomCarpet = new ChangeRoom(mainChar, changeRoomCarpetKey, room1, changeRoomCarpetContext, changeRoomCarpetConditions, changeRoomCarpetItems);

    room1Actions[changeRoomCarpet->getKey()] = changeRoomCarpet;

    room1->setActions(room1Actions);

    rooms[room1->getKey()] = room1;

    string levelKey = "intro";
    string startingLevelKey = "jerrys_garage";
    Level* level1 = new Level(levelKey, startingLevelKey, rooms);

    string room3Key = "medieval_village";
    string room3Intro = "You hear a ‘click’ - You’ve cracked the code! You proceed to turn the handle on the safe and open the "
                        "safe’s door. Inside is what seems like a futuristic toy gun. You think this would make a great toy for "
                        "your nephew. Better check if it still works. You aim the gun at the cement wall in front of you and with "
                        "stumble on the kennel behind you, flipping it over and making the bottom floor come apart – liberating "
                        "Snowballs. The dog slowly approaches you with a menacing look on its face. You slowly back away "
                        "while suddenly – you find yourself in a medieval town – No portal. No dog. No garage. You start"
                        "inspecting your surroundings – to each of your sides seems to be a variety of buildings; each of them"
                        "decorated with their own storefront sign – There’s a store which you’re not sure what is being sold,"
                        "another store labeled ‘general store’ and a castle can be seen far in the distance. People are coming and going.";
    map<string, NPC*> room3Characters;
    NPC* villager = new NPC("villager");

    map<string, Action*> room3Actions;

    string room3TopMenuMessage = "What would you like to do?: ";

    map<char, string> room3TopMenuOutput;
    room3TopMenuOutput['1'] = "Move crates";
    room3TopMenuOutput['2'] = "Move shelving unit";
    room3TopMenuOutput['3'] = "Move carpet";

    map<char, string> room3TopMenuInput;
    room3TopMenuInput['1'] = "search_crate";
    room3TopMenuInput['2'] = "search_shelf";
    room3TopMenuInput['3'] = "change_room_under_garage";

    Menu* room3TopMenu = new Menu(menuOutput, room1TopMenuOutput, room1TopMenuInput);

    map<string, Menu*> room3Menus;
    room3Menus["top"] = room3TopMenu;

    Room* room3 = new Room(room3Key, room3Intro, room3Characters, room3Menus);

    levels[level1->getKey()] = level1;
}
