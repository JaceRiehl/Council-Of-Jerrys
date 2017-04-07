#include "FakeDataLoader.h"

FakeDataLoader* FakeDataLoader::_instance = nullptr;

FakeDataLoader::FakeDataLoader() {}

FakeDataLoader* FakeDataLoader::Instance()
{
    if(!_instance)
        _instance = new FakeDataLoader();

    return _instance;
}

void FakeDataLoader::LoadEndOfGameText(map<string, string>& endOfGameText)
{
    endOfGameText["sneak_death"] = "You decide to wait till nighttime and scale the castle walls to sneak-in without the guard noticing. You "
                                    "start climbing. Everything is going great, you’ve almost cleared the wall when you suddenly lose your "
                                    "grip and fall to the ground. You break both your legs. The guards come rushing to investigate the "
                                    "commotion - \"Castle scalars will not be tolerated in King Jelly Bean’s land. Off with your head! \". - "
                                    "GAME OVER!";

    endOfGameText["death_by_snowball"] = "\"You saved my life 'Jerry'. Your actions will not be forgotten. However, no humans can be allowe d"
                                        "to live, and your species must be extinct. Good bye Jerry.\" - GAME OVER";

    endOfGameText["assertive_death"] = "\"Rudeness will not be tolerated in king Jelly Bean’s land. Off with your head!\" - GAME OVER";

    endOfGameText["failed_assassination"] = "\"Your reign is over King Jelly Bean – hand the crown over or die fighting for it! I will not let these "
                                            "villagers I’ve just met die for nothing at your hand.”. The king snaps his fingers and ten guards rush to "
                                            "the throne room. \"Bravery will not be tolerated in King Jelly Bean’s land. Off with your head!\" - GAME OVER";

    endOfGameText["king_jerry"] ="\"Your reign is over King Jelly Bean – hand the crown over or I will expose you for tax evasion! I will "
                                "not let these villagers I’ve just met die for nothing at your hand.\" You spoke with a new found confidence."
                                "\"Who are you?! How have you heard of this information I’ve loudly spoken about five minutes ago?!\""
                                "\"What will you do of me? The Legion of Kings cannot find of this treason – I will be eaten alive! Have "
                                "mercy for an old Jellybean.\""
                                "\"The name’s Jerry. King Jerry. Now leave this land and never return.\""
                                "\"As you wish... my King.” the jellybean grudgingly spoke.\""
                                "And so begins the reign of... KING... JERRY!";
    endOfGameText["save_and_exit"] = "Game Saved!";
}

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
    room1TopMenuOutput['4'] = "Print Inventory";
    room1TopMenuOutput['5'] = "Save and Exit";

    map<char, string> room1TopMenuInput;
    room1TopMenuInput['1'] = "search_crate";
    room1TopMenuInput['2'] = "search_shelf";
    room1TopMenuInput['3'] = "change_room_under_garage";
    room1TopMenuInput['4'] = "print_inventory";
    room1TopMenuInput['5'] = "save_and_exit";

    Menu* topMenu = new Menu(menuOutput, room1TopMenuOutput, room1TopMenuInput);

    map<string, Menu*> room1Menus;
    room1Menus["top"] = topMenu;

    Room* room1 = new Room(room1Key, room1Intro, room1Characters, room1Menus);
    // ACTIONS

    // SEARCH CRATE
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
    // **********************************************************************************************************************

    // SEARCH SHELF
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

    // **********************************************************************************************************************

    // CHANGEROOM CARPET

    string changeRoomCarpetKey = "change_room_under_garage";

    map<string, string> changeRoomCarpetContext;
    changeRoomCarpetContext["conditions_met"] = "You've discarded the carpet and uncovered a trap door. Da na na naaaaaaaaa! ";

    changeRoomCarpetContext["conditions_not_met"] = "You have back pain and weak knees. You can't move the carpet with the shelving unit on. This reminds "
                                                    "you of how weak and all alone you are and you start to feel sad.";
    changeRoomCarpetContext["change_room"] = "under_garage";

    vector<Item> changeRoomCarpetItems;

    vector<string> changeRoomCarpetConditions = { "search_shelf" };

    Action* changeRoomCarpet = new ChangeRoom(mainChar, changeRoomCarpetKey, room1, changeRoomCarpetContext, changeRoomCarpetConditions, changeRoomCarpetItems);

    room1Actions[changeRoomCarpet->getKey()] = changeRoomCarpet;

    // **********************************************************************************************************************

    // PRINT INVENTORY

    string room1PrintInventoryKey = "print_inventory";

    vector<string> room1PrintInventoryConditions;
    vector<Item> room1PrintInventoryItems;

    Action* room1PrintInventory = new PrintInventory(mainChar, room1PrintInventoryKey, room1PrintInventoryConditions, room1PrintInventoryItems);

    room1Actions[room1PrintInventory->getKey()] = room1PrintInventory;

    // **********************************************************************************************************************

    // SAVE AND EXIT

    string room1SaveAndExitKey = "save_and_exit";

    Action* room1SaveAndExit = new SaveAndExit(mainChar, room1SaveAndExitKey, room1);

    room1Actions[room1SaveAndExit->getKey()] = room1SaveAndExit;

    // **********************************************************************************************************************

    room1->setActions(room1Actions);

    rooms[room1->getKey()] = room1;

    //room 2 **********************************************************************
    string room2Key = "under_garage";
    string room2Intro = "You pull the rope attached to the trap door and lift it. A stairway is unveiled, and a set of straight tube halogen lights are engaged in series - lighting your way down. You decide you're brave today and make your way downstairs. A quick inspection of the room reveals a workbench with various common tools, a large box covered with a blanket, a lab coat hanging on a hook and a safe.";
    map<string, NPC*> room2Characters;
    NPC* Snowball = new NPC("snowball");

    room2Characters["snowball"] = Snowball;
    map <string, Action*> room2Actions;

    string menuOut = "What would you like to do?: ";

    map<char,string> room2TopMenuOutput;
    room2TopMenuOutput['1'] = "Look at Workbench";
    room2TopMenuOutput['2'] = "Look at Large Box";
    room2TopMenuOutput['3'] = "Search Labcoat";
    room2TopMenuOutput['4'] = "Open Safe";
    room2TopMenuOutput['5'] = "Print Inventory";
    room2TopMenuOutput['6'] = "Save and Exit";

    map<char,string> room2TopMenuInput;
    room2TopMenuInput['1'] = "search_workbench";
    room2TopMenuInput['2'] = "search_box";
    room2TopMenuInput['3'] = "search_coat";
    room2TopMenuInput['4'] = "open_safe";
    room2TopMenuInput['5'] = "print_inventory";
    room2TopMenuInput['6'] = "save_and_exit";

    map<char,string> room2SubMenuOutput;
    room2SubMenuOutput['1'] = "Talk to SnowBall";
    room2SubMenuOutput['2'] = "Open Cage";
    room2SubMenuOutput['3'] = "Ignore the cute fluffy dog begging for help";
    room2SubMenuOutput['4'] = "Print Inventory";
    room2SubMenuOutput['5'] = "Save and Exit";

    map<char,string> room2SubMenuInput;
    room2SubMenuInput['1'] = "talk_snowball";
    room2SubMenuInput['2'] = "cage";
    room2SubMenuInput['3'] = "ignore";
    room2SubMenuInput['4'] = "print_inventory";
    room2SubMenuInput['5'] = "save_and_exit";


    string subMenuText = "You remove the blanket off the box and it reveals a kennel with a cute fluffy white dog inside. \'What "
                        "kind of human being would leave their dog behind?\' you think to yourself. You decide animal control "
                        "would probably be the best people to handle this situation, so you pick up your phone and start dialing "
                        "when suddenly a voice comes from what seems to be the dog collar - \"Greetings fellow human. My "
                        "name is \'Snowballs\' I have been locked in this cage and forgotten by my owner. Would you be so kind "
                        "as to liberate me?\"";


    Menu* topMenu2 = new Menu(menuOutput, room2TopMenuOutput, room2TopMenuInput);
    Menu* subMenu2 = new Menu(subMenuText, room2SubMenuOutput, room2SubMenuInput);
    map<string, Menu*> room2Menus;
    room2Menus["top"] = topMenu2;
    room2Menus["search_box"] = subMenu2;

    Room* room2 = new Room(room2Key, room2Intro, room2Characters, room2Menus);
    //make action parameters




    //talk to snowball
    string snowballTalkKey = "talk_snowball";
    map<string,string> snowballDialog;
    snowballDialog["talk"] = "Perhaps the key could be found somewhere around this room. Your cooperation in this matter is greatly appreciated.";
    snowballDialog["talked"] = "I told you Jerry, the key must be somewhere in this room. Please located it.";

    Snowball->setDialog(snowballDialog);

    vector<string> snowballTalkConditions;
    vector<Item> snowballItems;

    Action* Talk1 = new Talk(mainChar, snowballTalkKey, Snowball, snowballTalkConditions, snowballItems);

    room2Actions[Talk1->getKey()] = Talk1;


    //open cage
    string cageOpenKey = "cage";
    map<string,string> cageOpenContext;
    cageOpenContext["conditions_met"] = "\"You saved my life 'Jerry'. Your actions will not be forgotten. However, no humans can be allowed to live, and your species must be extinct. Good bye Jerry.\" - GAME OVER";
    cageOpenContext["change_room"] = "death_by_snowball";

    cageOpenContext["conditions_not_met"] = "The cage is locked.";

    vector<Item> cageOpenItems;

    vector<string> cageOpenConditions = {"sledgehammer"};

    Action* cageOpen = new ChangeRoom(mainChar, cageOpenKey, room2, cageOpenContext, cageOpenConditions, cageOpenItems);

    room2Actions[cageOpen->getKey()] = cageOpen;

    // IGNORE SNOWBALL
    string ignoreSnowballKey = "ignore";
    map<string, string> ignoreSnowballContext;
    ignoreSnowballContext["change_room"] = room2->getKey();

    vector<string> ignoreSnowballConditions;
    vector<Item> ignoreSnowballItems;

    Action* ignoreSnowball = new ChangeRoom(mainChar, ignoreSnowballKey, room2, ignoreSnowballContext, ignoreSnowballConditions, ignoreSnowballItems);

    room2Actions[ignoreSnowball->getKey()] = ignoreSnowball;

    // PRINT INVENTORY

    string room2PrintInventoryKey = "print_inventory";

    vector<string> room2PrintInventoryConditions;
    vector<Item> room2PrintInventoryItems;

    Action* room2PrintInventory = new PrintInventory(mainChar, room2PrintInventoryKey, room2PrintInventoryConditions, room2PrintInventoryItems);

    room2Actions[room2PrintInventory->getKey()] = room2PrintInventory;


    //workbench
    string workbenchSearchKey = "search_workbench";
    map<string,string> workbenchSearchContext;
    workbenchSearchContext["conditions_met"] = "Just your basic small electronics tool set: an arrangement of screwdrivers, a soldering kit and a sledgehammer. Well, they’re yours now, better add these to your inventory!";

    workbenchSearchContext["searched"] = "There doesn't seem to be anything here.";

    vector<Item> tools = {Item("screwdriver"), Item("soldering_kit"), Item("sledgehammer")};

    vector<string> workbenchSearchConditions;

    Action* workbenchSearch = new Search(mainChar, workbenchSearchKey, room2, workbenchSearchContext, workbenchSearchConditions, tools);

    room2Actions[workbenchSearch->getKey()] = workbenchSearch;

    //coat
    string coatSearchKey = "search_coat";
    map<string,string> coatSearchContext;
    coatSearchContext["conditions_met"] = "Upon touching the lab coat, you hear a sound coming from one of the pocket. You found two keys! One key is labeled \'Kennel\' the other, \'Safe\'.";

    coatSearchContext["searched"] = "There doesn't seem to be anything here.";

    vector<Item> keys = {Item("safe_key"), Item("kennel_key")};

    vector<string> coatSearchConditions;

    Action* coatSearch = new Search(mainChar, coatSearchKey, room2, coatSearchContext, crateSearchConditions, keys);

    room2Actions[coatSearch->getKey()] = coatSearch;


    //open safe leave room 2
    string changeRoomSafeKey = "open_safe";
    map<string,string> changeRoomSafeContext;
    changeRoomSafeContext["conditions_met"] = "You hear a \'click\' - You've cracked the code! You proceed to turn the safe's handle and pull the heavy door outwards - revealing its contents. Inside is nothing else other than what looks like a futuristic toy gun. You're slightly disappointed, but realize the gun would make a great toy for your nephew. Better check if it still works. You aim the gun at the cement wall in front of you and with your best Schwarzenegger accent, you deliver your totally original line - \"Hasta la vista, baby\". You press the trigger. A large portal opens up on the wall. Startled, you drop the gun and take a step back which causes you to stumble on the kennel behind you, flipping it over and making the kennel\'s bottom floor come loose - liberating Snowballs. The dog slowly approaches you with a menacing look on its face. You slowly back away while suddenly - you find yourself in a medieval town - No portal. No dog. No garage. You start inspecting your surroundings - to each of your sides seems to be a variety of buildings; each of them decorated with their own storefront sign - There's a store which you're not sure what is being sold, another store labeled 'general store' and a castle can be seen far in the distance. People are coming and going.";

    changeRoomSafeContext["conditions_not_met"] = "The door still seems stuck and won't open";

    changeRoomSafeContext["change_room"] = "medieval_village";

     vector<Item> changeRoomSafeItems;

     vector<string> changeRoomSafeConditions = { "safe_key" };

     Action* changeRoomSafe = new ChangeRoom(mainChar, changeRoomSafeKey, room2, changeRoomSafeContext, changeRoomSafeConditions, changeRoomSafeItems);

     room2Actions[changeRoomSafe->getKey()] = changeRoomSafe;

    // SAVE AND EXIT

    string room2SaveAndExitKey = "save_and_exit";

    Action* room2SaveAndExit = new SaveAndExit(mainChar, room1SaveAndExitKey, room2);

    room2Actions[room2SaveAndExit->getKey()] = room2SaveAndExit;

    // **********************************************************************************************************************

     room2->setActions(room2Actions);

     rooms[room2->getKey()]= room2;

    //*****************************************************ROOM 3******************

    string room3Key = "medieval_village";
    string room3Intro = "You hear a 'click' - You've cracked the code! You proceed to turn the handle on the safe and open the "
                        "safe's door. Inside is what seems like a futuristic toy gun. You think this would make a great toy for "
                        "your nephew. Better check if it still works. You aim the gun at the cement wall in front of you and with "
                        "stumble on the kennel behind you, flipping it over and making the bottom floor come apart - liberating "
                        "Snowballs. The dog slowly approaches you with a menacing look on its face. You slowly back away "
                        "while suddenly - you find yourself in a medieval town - No portal. No dog. No garage. You start"
                        "inspecting your surroundings - to each of your sides seems to be a variety of buildings; each of them"
                        "decorated with their own storefront sign - There's a store which you're not sure what is being sold,"
                        "another store labeled \'general store\' and a castle can be seen far in the distance. People are coming and going.";
    map<string, NPC*> room3Characters;
    NPC* villager = new NPC("villager");
    map<string, string> villagerDialog;
    villagerDialog["talk"] = "\"Oh bless you kind sir. I do not have much to offer, but please accept this invitation"
                                        "to the king castle for the ball.\"";
    villagerDialog["rejected"] = "\"Well thanks for nothing. Wow, what a tease.\"";
    villagerDialog["talked"] = "\"Your generosity is greatly appreciated - kind sir. If only we could have a king as generous as you.\"";

    villager->setDialog(villagerDialog);

    map<string, Action*> room3Actions;

    // MENUS
    string room3TopMenuMessage = "What would you like to do?: ";

    map<char, string> room3TopMenuOutput;
    room3TopMenuOutput['1'] = "Talk to Villager";
    room3TopMenuOutput['2'] = "Go to Unknown Store";
    room3TopMenuOutput['3'] = "Go to General Store";
    room3TopMenuOutput['4'] = "Go to Castle";
    room3TopMenuOutput['5'] = "Print Inventory";
    room3TopMenuOutput['6'] = "Save and Exit";

    map<char, string> room3TopMenuInput;
    room3TopMenuInput['1'] = "talk_villager";
    room3TopMenuInput['2'] = "unknown_store";
    room3TopMenuInput['3'] = "general_store";
    room3TopMenuInput['4'] = "castle";
    room3TopMenuInput['5'] = "print_inventory";
    room3TopMenuInput['6'] = "save_and_exit";

    Menu* room3TopMenu = new Menu(menuOutput, room3TopMenuOutput, room3TopMenuInput);

    string room3TalkMenuMessage =   "\"Oh, good day kind sir. I can tell by the clothes you’re wearing that you are not from here. Want my "
                                    "advice - turn back and return to where you’ve come from. King Jelly Bean is using all of the food "
                                    "supplies and we’re all slowly dying. But before you leave, would you have any food to spare?\"";

    map<char, string> room3TalkMenuOutput;
    room3TalkMenuOutput['1'] = "Give the villager some food.";
    room3TalkMenuOutput['2'] = "Ignore the hungry villager.";
    room3TalkMenuOutput['3'] = "Print Inventory";
    room3TalkMenuOutput['4'] = "Save and Exit";

    map<char, string> room3TalkMenuInput;
    room3TalkMenuInput['1'] = "give_food";
    room3TalkMenuInput['2'] = "ignore";
    room3TalkMenuInput['3'] = "print_inventory";
    room3TalkMenuInput['4'] = "save_and_exit";

    Menu* room3TalkMenu = new Menu(room3TalkMenuMessage, room3TalkMenuOutput, room3TalkMenuInput);

    string room3UnknownStoreMenuMessage =    "\"Hey, are you tired of real doors, cluttering up your house, where you open 'em, and they actually go"
                                            "somewhere? And you go in another room? Well welcome to \"Real Fake Doors\"! That's us. We’ve filled"
                                            "a whole room with them. Tell you what, if you can find the one real door in this store, I’ll give you 30"
                                            "Smeckles.\"";

    map<char, string> room3UnknownStoreMenuOutput;
    room3UnknownStoreMenuOutput['1'] = "Choose Door 1";
    room3UnknownStoreMenuOutput['2'] = "Choose Door 2";
    room3UnknownStoreMenuOutput['3'] = "Choose Door 3";
    room3UnknownStoreMenuOutput['4'] = "Choose Door 4";
    room3UnknownStoreMenuOutput['5'] = "Choose Door 5";
    room3UnknownStoreMenuOutput['6'] = "Leave";
    room3UnknownStoreMenuOutput['7'] = "Print Inventory";
    room3UnknownStoreMenuOutput['8'] = "Save and Exit";

    map<char, string> room3UnknownStoreMenuInput;
    room3UnknownStoreMenuInput['1'] = "search_door_1";
    room3UnknownStoreMenuInput['2'] = "search_door_2";
    room3UnknownStoreMenuInput['3'] = "search_door_3";
    room3UnknownStoreMenuInput['4'] = "search_door_4";
    room3UnknownStoreMenuInput['5'] = "search_door_5";
    room3UnknownStoreMenuInput['6'] = "leave_unknown_store";
    room3UnknownStoreMenuInput['7'] = "print_inventory";
    room3UnknownStoreMenuInput['8'] = "save_and_exit";

    Menu* room3UnknownStoreMenu = new Menu(room3UnknownStoreMenuMessage, room3UnknownStoreMenuOutput, room3UnknownStoreMenuInput);

    string room3GeneralStoreMenuMessage = "\"Welcome to the General store what would you like to buy? We have a loaf of bread for 30 Smeckles. That’s it.\"";

    map<char, string> room3GeneralStoreMenuOutput;
    room3GeneralStoreMenuOutput['1'] = "Buy a loaf of bread.";
    room3GeneralStoreMenuOutput['2'] = "Go back to the village.";
    room3GeneralStoreMenuOutput['3'] = "Print inventory.";
    room3GeneralStoreMenuOutput['4'] = "Save and Exit";

    map<char, string> room3GeneralStoreMenuInput;
    room3GeneralStoreMenuInput['1'] = "buy_bread";
    room3GeneralStoreMenuInput['2'] = "leave_general_store";
    room3GeneralStoreMenuInput['3'] = "print_inventory";
    room3GeneralStoreMenuInput['4'] = "save_and_exit";

    Menu* room3GeneralStoreMenu = new Menu(room3GeneralStoreMenuMessage, room3GeneralStoreMenuOutput, room3GeneralStoreMenuInput);

    string room3CastleMenuMessage = "Upon arriving to the castle wall, you are confronted by two guards. \"Halt! What business do you have with King Jelly Bean?\"";

    map<char, string> room3CastleOutput;
    room3CastleOutput['1'] = "I have an invitation";
    room3CastleOutput['2'] = "Try to sneak pass the guards.";
    room3CastleOutput['3'] = "Ask them to let you in with an assertive tone.";
    room3CastleOutput['4'] = "Go back to the village";
    room3CastleOutput['5'] = "Print Inventory";
    room3CastleOutput['6'] = "Save and Exit";

    map<char, string> room3CastleInput;
    room3CastleInput['1'] = "present_invitation";
    room3CastleInput['2'] = "sneak";
    room3CastleInput['3'] = "assertive";
    room3CastleInput['4'] = "leave_castle";
    room3CastleInput['5'] = "print_inventory";
    room3CastleInput['6'] = "save_and_exit";

    Menu* room3CastleMenu = new Menu(room3CastleMenuMessage, room3CastleOutput, room3CastleInput);

    map<string, Menu*> room3Menus;
    room3Menus["top"] = room3TopMenu;
    room3Menus["talk_villager"] = room3TalkMenu;
    room3Menus["unknown_store"] = room3UnknownStoreMenu;
    room3Menus["general_store"] = room3GeneralStoreMenu;
    room3Menus["castle"] = room3CastleMenu;


    // ***********************************************************************************************************
    Room* room3 = new Room(room3Key, room3Intro, room3Characters, room3Menus);

    // ACTIONS

    // PRINT INVENTORY

    string room3PrintInventoryKey = "print_inventory";

    vector<string> room3PrintInventoryConditions;
    vector<Item> room3PrintInventoryItems;

    Action* room3PrintInventory = new PrintInventory(mainChar, room3PrintInventoryKey, room3PrintInventoryConditions, room3PrintInventoryItems);

    room3Actions[room3PrintInventory->getKey()] = room3PrintInventory;

    // ***********************************************************************************************************

    // TALK TO VILLAGER ACTION
    string talkToVillagerKey = "give_food";
    vector<string> talkVillagerConditions = { "bread" };
    vector<Item> talkVillagerItems = { Item("invitation") };

    Action* talkToVillagerAction = new Talk(mainChar, talkToVillagerKey, villager, talkVillagerConditions, talkVillagerItems);

    room3Actions[talkToVillagerAction->getKey()]= talkToVillagerAction;

    // ***********************************************************************************************************
    // Ignore Villager

    string ignoreVillagerKey = "ignore";

    vector<Item> ignoreVillagerItems;
    vector<string> ignoreVillagerConditions;

    map<string, string> ignoreVillagerContext;

    ignoreVillagerContext["change_room"] = room3->getKey();

    Action* ignoreVillager = new ChangeRoom(mainChar, ignoreVillagerKey, room3, ignoreVillagerContext,
                                                  ignoreVillagerConditions, ignoreVillagerItems);

    room3Actions[ignoreVillager->getKey()] = ignoreVillager;

    // ************************************************************************************************************

    // Door1
    string searchDoor1Key = "search_door_1";
    map<string, string> searchDoor1Context;
    searchDoor1Context["conditions_not_met"] = "\"Oh boy – that’s a fake door. Better luck next time pal!\"";
    searchDoor1Context["conditions_met"] = "\"Get out of here. I already gave you my damn smeckles!\"";

    vector<Item> searchDoor1Items;

    vector<string> searchDoor1Conditions = { "search_door_2" };

    Action* searchDoor1 = new Search(mainChar, searchDoor1Key, room3, searchDoor1Context, searchDoor1Conditions, searchDoor1Items);

    room3Actions[searchDoor1->getKey()] = searchDoor1;

    // **************************************************************************************************************

    // Door2
    string searchDoor2Key = "search_door_2";
    map<string, string> searchDoor2Context;
    searchDoor2Context["conditions_met"] = "\"Wow, you really know your fake doors - a real connoisseur. Here are your thirty Smeckles kind sir. I"
                                            "don’t know I am still in business doing that - This game is full of plot holes.\"";

    searchDoor2Context["searched"] = "\"Hey, I know you. You’re that fake door master who cost me 30 Smeckles. Get out of here!\"";

    unsigned int door2Smekles = 30;
    vector<Item> searchDoor2Items;

    for(unsigned int i = 0; i < door2Smekles; ++i)
    {
        searchDoor2Items.push_back(Item("smeckle"));
    }

    vector<string> searchDoor2Conditions;

    Action* searchDoor2 = new Search(mainChar, searchDoor2Key, room3, searchDoor2Context, searchDoor2Conditions, searchDoor2Items);

    room3Actions[searchDoor2->getKey()] = searchDoor2;

    // **************************************************************************************************************

    // Door3
    string searchDoor3Key = "search_door_3";
    map<string, string> searchDoor3Context;
    searchDoor3Context["conditions_not_met"] = "\"Oh boy - that’s a fake door. Better luck next time pal!\"";
    searchDoor3Context["conditions_met"] = "\"Get out of here. I already gave you my damn smeckles!\"";
    searchDoor3Context["searched"] = "\"Sorry, No more food - store closed\".";

    vector<Item> searchDoor3Items;

    vector<string> searchDoor3Conditions = { "search_door_2" };

    Action* searchDoor3 = new Search(mainChar, searchDoor3Key, room3, searchDoor3Context, searchDoor3Conditions, searchDoor3Items);

    room3Actions[searchDoor3->getKey()] = searchDoor3;

    // **************************************************************************************************************

    // Door4
    string searchDoor4Key = "search_door_4";
    map<string, string> searchDoor4Context;
    searchDoor4Context["conditions_not_met"] = "\"Oh boy - that’s a fake door. Better luck next time pal!\"";
    searchDoor4Context["conditions_met"] = "\"Get out of here. I already gave you my damn smeckles!\"";

    vector<Item> searchDoor4Items;

    vector<string> searchDoor4Conditions = { "search_door_2" };

    Action* searchDoor4 = new Search(mainChar, searchDoor4Key, room3, searchDoor4Context, searchDoor4Conditions, searchDoor4Items);

    room3Actions[searchDoor4->getKey()] = searchDoor4;

    // **************************************************************************************************************

    // Door5
    string searchDoor5Key = "search_door_5";
    map<string, string> searchDoor5Context;
    searchDoor5Context["conditions_not_met"] = "\"Oh boy - that’s a fake door. Better luck next time pal!\"";
    searchDoor5Context["conditions_met"] = "\"Get out of here. I already gave you my damn smeckles!\"";

    vector<Item> searchDoor5Items;

    vector<string> searchDoor5Conditions = { "search_door_2" };

    Action* searchDoor5 = new Search(mainChar, searchDoor5Key, room3, searchDoor5Context, searchDoor5Conditions, searchDoor5Items);

    room3Actions[searchDoor5->getKey()] = searchDoor5;
    //***************************************************************************************************************

    // Leave Unknown Store

    string leaveUnknownStoreKey = "leave_unknown_store";

    vector<Item> leaveUnknownStoreItems;
    vector<string> leaveUnknownStoreConditions;

    map<string, string> leaveUnknownStoreContext;

    leaveUnknownStoreContext["change_room"] = room3->getKey();

    Action* leaveUnknownStore = new ChangeRoom(mainChar, leaveUnknownStoreKey, room3, leaveUnknownStoreContext,
                                                  leaveUnknownStoreConditions, leaveUnknownStoreItems);

    room3Actions[leaveUnknownStore->getKey()] = leaveUnknownStore;

    //***************************************************************************************************************

    // **************************************************************************************************************

    // Buy Bread

    string buyBreadKey = "buy_bread";

    map<string, string> buyBreadContext;
    buyBreadContext["conditions_met"] = "\"Enjoy! You know, not many people get to eat around here. I hope you really enjoy every bite of that loaf you just bought while someone else out there doesn’t.\"";
    buyBreadContext["conditions_not_met"] = "\"You don’t have enough Smeckles. No Smeckles, no food.\"";

    vector<Item> buyBreadItems = { Item("bread") };
    vector<string> buyBreadConditions = { "smeckle" };

    Action* buyBread = new Search(mainChar, buyBreadKey, room3, buyBreadContext, buyBreadConditions, buyBreadItems);

    room3Actions[buyBread->getKey()] = buyBread;

    //***************************************************************************************************************

    // Leave General Store


    string leaveGeneralStoreKey = "leave_general_store";

    vector<Item> leaveGeneralStoreItems;
    vector<string> leaveGeneralStoreConditions;

    map<string, string> leaveGeneralStoreContext;

    leaveGeneralStoreContext["change_room"] = room3->getKey();

    Action* leaveGeneralStore = new ChangeRoom(mainChar, leaveGeneralStoreKey, room3, leaveGeneralStoreContext,
                                                  leaveGeneralStoreConditions, leaveGeneralStoreItems);

    room3Actions[leaveGeneralStore->getKey()] = leaveGeneralStore;

    //***************************************************************************************************************

    // Invitation
    string presentInvitationKey = "present_invitation";

    vector<Item> presentInvitationItems;
    vector<string> presentInvitationConditions = {"invitation"};

    map<string, string> presentInvitationContext;

    presentInvitationContext["conditions_not_met"] = "Oh yeah? Well where is it? HUH? Get your ass outta here!";
    presentInvitationContext["change_room"] = "castle";

    Action* presentInvitation = new ChangeRoom(mainChar, presentInvitationKey, room3, presentInvitationContext,
                                                  presentInvitationConditions, presentInvitationItems);

    room3Actions[presentInvitation->getKey()] = presentInvitation;
    //***************************************************************************************************************

    //Sneak
    string sneakPastKey = "sneak";

    vector<Item> sneakPastItems;
    vector<string> sneakPastConditions;

    map<string, string> sneakPastContext;

    sneakPastContext["change_room"] = "sneak_death";

    Action* sneakPast = new ChangeRoom(mainChar, sneakPastKey, room3, sneakPastContext,
                                                  sneakPastConditions, sneakPastItems);

    room3Actions[sneakPast->getKey()] = sneakPast;

    // **************************************************************************************************************

    // Assertive
    string beAssertiveKey = "assertive";

    vector<Item> beAssertiveItems;
    vector<string> beAssertiveConditions;

    map<string, string> beAssertiveContext;

    beAssertiveContext["change_room"] = "assertive_death";

    Action* beAssertive = new ChangeRoom(mainChar, beAssertiveKey, room3, beAssertiveContext,
                                                  beAssertiveConditions, beAssertiveItems);

    room3Actions[beAssertive->getKey()] = beAssertive;

    // *************************************************************************************************************

    // Go back to village

    string leaveCastleKey = "leave_castle";

    vector<Item> leaveCastleItems;
    vector<string> leaveCastleConditions;

    map<string, string> leaveCastleContext;

    leaveCastleContext["change_room"] = room3->getKey();

    Action* leaveCastle = new ChangeRoom(mainChar, leaveCastleKey, room3, leaveCastleContext,
                                                  leaveCastleConditions, leaveCastleItems);

    room3Actions[leaveCastle->getKey()] = leaveCastle;

    // *************************************************************************************************************

    // SAVE AND EXIT

    string room3SaveAndExitKey = "save_and_exit";

    Action* room3SaveAndExit = new SaveAndExit(mainChar, room3SaveAndExitKey, room3);

    room3Actions[room3SaveAndExit->getKey()] = room3SaveAndExit;

    // **********************************************************************************************************************

    room3->setActions(room3Actions);

    rooms[room3->getKey()] = room3;

    // *************************************************************************************************************


    // ***************************************** ROOM 4 ************************************************************
    string room4Key = "castle";
    string room4Intro = "After entering the castle, an urge to pee overtakes you. In a panic, you make haste to the closest "
                        "bathroom. While you\'re doing your thing you notice sound coming from the wall to your left. You can "
                        "hear everything coming from the throne room. " // ADD AN ACTUAL PARAGRAPH WHEN TEXTBOX IS FIXED
                        "\"Hahaha! I have made millions for the past five years reselling the food the villagers produced, the best"
                        "part is I haven\'t even had to pay taxes to the legion of kings. At this rate, I will be the richest king of all"
                        "time in no time. Oh I hope no one is hearing me speak out loud about my crimes. One could not only"
                        "put my life in jeopardy with this information, but this person could also overtake my position as King.\""
                        "Finally wrapping up your business in the bathroom, you make your way to the throne room."
                        "\"A yes, Mr. slippery stairs I’ve been expecting you.\"";

    map<string, NPC*> room4Characters;

    string room4TopMenuMessage = "What would you like to do?: ";
    map<char,string> room4TopMenuOutput;
    room4TopMenuOutput['1'] = "Kill the King";
    room4TopMenuOutput['2'] = "Use the information you just heard to Blackmail the King ";

    map<char, string> room4TopMenuInput;
    room4TopMenuInput['1'] = "kill_king";
    room4TopMenuInput['2'] = "blackmail_king";

    Menu* room4TopMenu = new Menu(room4TopMenuMessage, room4TopMenuOutput, room4TopMenuInput);

    map<string, Menu*> room4Menus;
    room4Menus["top"] = room4TopMenu;

    Room* room4 = new Room(room4Key, room4Intro, room4Characters, room4Menus);

    // ROOM 4 ACTIONS

    map<string, Action*> room4Actions;

    // Kill King
    string killKingKey = "kill_king";
    map<string, string> killKingContext;
    killKingContext["change_room"] = "failed_assassination";
    vector<string> killKingConditions;
    vector<Item> killKingItems;

    Action* killKing = new ChangeRoom(mainChar, killKingKey, room4, killKingContext, killKingConditions, killKingItems);

    room4Actions[killKing->getKey()] = killKing;
    // ****************************************************************************************************************

    // Blackmail King

    string blackmailKingKey = "blackmail_king";
    map<string, string> blackmailKingContext;
    blackmailKingContext["change_room"] = "king_jerry";
    vector<string> blackmailKingConditions;
    vector<Item> blackmailKingItems;

    Action* blackmailKing = new ChangeRoom(mainChar, blackmailKingKey, room4, blackmailKingContext, blackmailKingConditions, blackmailKingItems);

    room4Actions[blackmailKing->getKey()] = blackmailKing;

    // ****************************************************************************************************************

    room4->setActions(room4Actions);

    rooms[room4->getKey()] = room4;

    string levelKey = "intro";
    string startingLevelKey = "jerrys_garage";
    Level* level1 = new Level(levelKey, startingLevelKey, rooms);

    levels[level1->getKey()] = level1;
}
