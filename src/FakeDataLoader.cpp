#include "FakeDataLoader.h"

void FakeDataLoader::LoadLevels(PlayableCharacter* mainChar, map<string, Level*> &levels)
{
    map<string, Room*> rooms;

    string room1Key = "jerrys_garage";
    string room1Intro = "On a summer day in the hot August heat, you've finally reached the back of the moving truck. There's "
                        "not much room left in the house, so you decide to bring the last remaining boxes to the garage. Upon "
                        "entering the garage, you notice that the previous owners didn't bother to clean the garage from their "
                        "belongings. Looks like you'll have to clean this mess up yourself. There's a broken down shelving unit "
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
    crateSearchContext["conditions_met"] = "You've found a pile of coins of what seems like a foreign currency. A crown bearing jellybean is "
                                           "portrayed on each side of the coins with the word 'Smeckmle' engraved at the bottom. Wow, what a "
                                           "score this'll make in your coin collection!";

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
    shelfSearchContext["conditions_met"] = "As you wrap your arms around the shelving unit, a diary topples over. You don't think you should read "
                                           "someone else's personal diary, but having to clean someone else's mess as made you feel somewhat "
                                           "rebellious, so you open it. Most of its content is filled with gibberish mathematical equations but the "
                                           "last entry stands out, it reads - \"These posers discovered the combination to my safe, I HAD to make "
                                           "them pay. Anyway, time to change it now; maybe I'll use the year Doc Brown took Marty back in time. "
                                           "God, Back to the Future is such a great movie!\". This seems like an odd man, you think to yourself. "
                                           "Anyhow, you finish moving the shelving unit and discard the diary.";

    crateSearchContext["searched"] = "There doesn't seem to be anything here.";

    vector<Item> crateSearchItems;

    vector<string> shelfSearchConditions;

    Action* shelfSearch = new Search(mainChar, shelfSearchKey, room1, shelfSearchContext, shelfSearchConditions, crateSearchItems);

    room1Actions[shelfSearch->getKey()] = shelfSearch;

    string changeRoomCarpetKey = "change_room_under_garage";

    map<string, string> changeRoomCarpetContext;
    changeRoomCarpetContext["conditions_met"] = "You've discarded the carpet and uncovered a trap door. Da na na naaaaaaaaa! ";

    changeRoomCarpetContext["conditions_not_met"] = "You have back pain and weak knees. You can't move the carpet with the shelving unit on. This reminds "
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

    //room 2 **********************************************************************
    string room2Key = "under_garage";
    string room2Intro = "You pull the rope attached to the trap door and lift it. A stairway is unveiled, and a set of straight tube halogen lights are engaged in series – lighting your way down. You decide you're brave today and make your way downstairs. A quick inspection of the room reveals a workbench with various common tools, a large box covered with a blanket, a lab coat hanging on a hook and a safe.";
    map<string, NPC*> room2Characters;
    NPC* Snowball = new NPC("Snowball");
    room2Characters["snowball"] = Snowball;
    map <string, Action*> room2Actions;

    string menuOut = "What would you like to do?: ";

    map<char,string> room2TopMenuOutput;
    room2TopMenuOutput['1'] = "Look at workbench";
    room2TopMenuOutput['2'] = "Look at large box";
    room2TopMenuOutput['3'] =  "Search  lab coat";
    room2TopMenuOutput['4'] = "Open safe";

    map<char,string> room2TopMenuInput;
    room2TopMenuInput['1'] = "search_workbench";
    room2TopMenuInput['2'] = "search_box";
    room2TopMenuInput['3'] =  "search_coat";
    room2TopMenuInput['4'] = "open_safe";

    map<char,string> room2SubMenuOutput;
    room2SubMenuOutput['1'] = "Talk to SnowBall";
    room2SubMenuOutput['2'] =  "Open Cage";
    room2SubMenuOutput['3'] = "Ignore the cute fluffy dog begging for help";

    map<char,string> room2SubMenuInput;
    room2SubMenuInput['1'] ="talk_snowball";
    room2SubMenuInput['2'] = "search_cage";
    room2SubMenuInput['3'] = "leave";




    Menu* topMenu2 = new Menu(menuOutput, room2TopMenuOutput, room2TopMenuInput);
    Menu* subMenu2 = new Menu(menuOutput, room2SubMenuOutput, room2SubMenuInput);
    map<string, Menu*> room2Menus;
    room2Menus["top"] = topMenu2;
    room2Menus["sub"] = subMenu2;

    Room* room2 = new Room(room2Key, room2Intro, room2Characters, room2Menus);
    //make action parameters




    //talk to snowball
    string snowballTalkKey = "talk_snowball";
    map<string,string> snowballTalkContext;
    snowballTalkContext["conditions_met"] = "Perhaps the key could be found somewhere around this room. Your cooperation in this matter is greatly appreciated.";


    vector<string> snowballTalkConditions;
    vector<Item> snowballItems;

    Action* Talk1 = new Talk(mainChar, "talk_snowball", Snowball, snowballTalkConditions, snowballItems);

    room2Actions["talk_snowball"] = Talk1;


    //open cage
    string cageSearchKey = "search_cage";
    map<string,string> cageSearchContext;
    cageSearchContext["conditions_met"] = "\"You saved my life 'Jerry'. Your actions will not be forgotten. However, no humans can be allowed to live, and your species must be extinct. Good bye Jerry.\" - GAME OVER";

    cageSearchContext["conditions_not_met"] = "The cage is locked.";

    vector<Item> noItems;

    vector<string> cageSearchConditions = {"search_workbench"};

    Action* cageSearch = new Search(mainChar, cageSearchKey, room2, cageSearchContext, cageSearchConditions, noItems);

    room2Actions["search_cage"] = cageSearch;


    //workbench
    string workbenchSearchKey = "search_workbench";
    map<string,string> workbenchSearchContext;
    workbenchSearchContext["conditions_met"] = "ust your basic small electronics tool set: an arrangement of screwdrivers, a soldering kit and a sledgehammer. Well, they’re yours now, better add these to your inventory!";

    workbenchSearchContext["searched"] = "There doesn't seem to be anything here.";

    vector<Item> tools = {Item("Screwdriver"), Item("Soldering Kit"), Item("Sledgehammer")};

    vector<string> workbenchSearchConditions;

    Action* workbenchSearch = new Search(mainChar, workbenchSearchKey, room2, workbenchSearchContext, workbenchSearchConditions, tools);

    room2Actions[workbenchSearch->getKey()] = workbenchSearch;

    //coat
    string coatSearchKey = "search_coat";
    map<string,string> coatSearchContext;
    coatSearchContext["conditions_met"] = "Upon touching the lab coat, you hear a sound coming from one of the pocket. You found two keys! One key is labeled 'Kennel' the other, 'Safe'.";

    coatSearchContext["searched"] = "There doesn't seem to be anything here.";

    vector<Item> keys = {Item("safe key"), Item("kennel key")};

    vector<string> coatSearchConditions;

    Action* coatSearch = new Search(mainChar, coatSearchKey, room2, coatSearchContext, crateSearchConditions, keys);

    room2Actions[coatSearch->getKey()] = coatSearch;


    //open safe leave room 2
    string changeRoomSafeKey = "open_safe";
    map<string,string> changeRoomSafeContext;
    changeRoomSafeContext["conditions_met"] = "You hear a 'click' - You've cracked the code! You proceed to turn the safe's handle and pull the heavy door outwards - revealing its contents. Inside is nothing else other than what looks like a futuristic toy gun. You're slightly disappointed, but realize the gun would make a great toy for your nephew. Better check if it still works. You aim the gun at the cement wall in front of you and with your best Schwarzenegger accent, you deliver your totally original line - \"Hasta la vista, baby\". You press the trigger. A large portal opens up on the wall. Startled, you drop the gun and take a step back which causes you to stumble on the kennel behind you, flipping it over and making the kennel's bottom floor come loose – liberating Snowballs. The dog slowly approaches you with a menacing look on its face. You slowly back away while suddenly – you find yourself in a medieval town – No portal. No dog. No garage. You start inspecting your surroundings – to each of your sides seems to be a variety of buildings; each of them decorated with their own storefront sign – There's a store which you're not sure what is being sold, another store labeled 'general store' and a castle can be seen far in the distance. People are coming and going.";

    changeRoomSafeContext["conditions_not_met"] = "The door still seems stuck and won't open";

     vector<Item> changeRoomSafeItems;

     vector<string> changeRoomSafeConditions = { "search_coat" };

     Action* changeRoomSafe = new ChangeRoom(mainChar, changeRoomSafeKey, room1, changeRoomSafeContext, changeRoomSafeConditions, changeRoomSafeItems);


     //**************************************ROOM 4***********************************************************************

    String room2Key = "castle";
    string room2Intro = "\“Hahaha! I have made millions for the past five years reselling the food the villagers produced, the best part is I haven’t even had to pay taxes to the legion of kings. At this rate, I will be the richest king of all time in no time. Oh I hope no one is hearing me speak out loud about my crimes. One could not only put my life in jeopardy with this information, but this person could also overtake my position as King.\""

    "Finally wrapping up your business in the bathroom, you make your way to the throne room. "

    "\"A yes, Mr. slippery stairs I’ve been expecting you.\"";

    map<char,string> room2TopMenuOutput;
    room2TopMenuOutput['1'] = "Kill King JellyBean";
    room2TopMenuOutput['2'] = "Blackmail the king about his tax evasions";


    map<char,string> room2TopMenuInput;
    room2TopMenuInput['1'] = "talk_king";
    room2TopMenuInput['2'] = "talk_jelly";







    //*****************************************************ROOM 3******************

    string room3Key = "medieval_village";
    string room3Intro = "You hear a 'click' - You've cracked the code! You proceed to turn the handle on the safe and open the "
                        "safe's door. Inside is what seems like a futuristic toy gun. You think this would make a great toy for "
                        "your nephew. Better check if it still works. You aim the gun at the cement wall in front of you and with "
                        "stumble on the kennel behind you, flipping it over and making the bottom floor come apart – liberating "
                        "Snowballs. The dog slowly approaches you with a menacing look on its face. You slowly back away "
                        "while suddenly – you find yourself in a medieval town – No portal. No dog. No garage. You start"
                        "inspecting your surroundings – to each of your sides seems to be a variety of buildings; each of them"
                        "decorated with their own storefront sign – There's a store which you're not sure what is being sold,"
                        "another store labeled 'general store' and a castle can be seen far in the distance. People are coming and going.";
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
