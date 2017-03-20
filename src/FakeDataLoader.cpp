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
    changeRoomCarpetContext["change_room"] = "under_garage";

    vector<Item> changeRoomCarpetItems;

    vector<string> changeRoomCarpetConditions = { "search_shelf" };

    Action* changeRoomCarpet = new ChangeRoom(mainChar, changeRoomCarpetKey, room1, changeRoomCarpetContext, changeRoomCarpetConditions, changeRoomCarpetItems);

    room1Actions[changeRoomCarpet->getKey()] = changeRoomCarpet;

    room1->setActions(room1Actions);

    rooms[room1->getKey()] = room1;

    //room 2 **********************************************************************
    string room2Key = "under_garage";
    string room2Intro = "You pull the rope attached to the trap door and lift it. A stairway is unveiled, and a set of straight tube halogen lights are engaged in series – lighting your way down. You decide you're brave today and make your way downstairs. A quick inspection of the room reveals a workbench with various common tools, a large box covered with a blanket, a lab coat hanging on a hook and a safe.";
    map<string, NPC*> room2Characters;
    NPC* Snowball = new NPC("snowball");

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
    room2SubMenuInput['2'] = "cage";
    room2SubMenuInput['3'] = "leave";


    string subMenuText = "You remove the blanket off the box and it reveals a kennel with a cute fluffy white dog inside. \'What "
                        "kind of human being would leave their dog behind?\’ you think to yourself. You decide animal control "
                        "would probably be the best people to handle this situation, so you pick up your phone and start dialing "
                        "when suddenly a voice comes from what seems to be the dog collar - \“Greetings fellow human. My "
                        "name is \‘Snowballs\’ I have been locked in this cage and forgotten by my owner. Would you be so kind "
                        "as to liberate me?\”";


    Menu* topMenu2 = new Menu(menuOutput, room2TopMenuOutput, room2TopMenuInput);
    Menu* subMenu2 = new Menu(subMenuText, room2SubMenuOutput, room2SubMenuInput);
    map<string, Menu*> room2Menus;
    room2Menus["top"] = topMenu2;
    room2Menus["search_box"] = subMenu2;

    Room* room2 = new Room(room2Key, room2Intro, room2Characters, room2Menus);
    //make action parameters




    //talk to snowball
    string snowballTalkKey = "search_box_talk_snowball";
    map<string,string> snowballDialog;
    snowballDialog["conditions_met"] = "Perhaps the key could be found somewhere around this room. Your cooperation in this matter is greatly appreciated.";

    Snowball->setDialog(snowballDialog);

    vector<string> snowballTalkConditions;
    vector<Item> snowballItems;

    Action* Talk1 = new Talk(mainChar, snowballTalkKey, Snowball, snowballTalkConditions, snowballItems);

    room2Actions[Talk1->getKey()] = Talk1;


    //open cage
    string cageSearchKey = "search_box_cage";
    map<string,string> cageSearchContext;
    cageSearchContext["conditions_met"] = "\"You saved my life 'Jerry'. Your actions will not be forgotten. However, no humans can be allowed to live, and your species must be extinct. Good bye Jerry.\" - GAME OVER";

    cageSearchContext["conditions_not_met"] = "The cage is locked.";
    cageSearchContext["default"] = "Ignore the cute fluffy white dog begging for help.";

    vector<Item> room2Items;

    vector<string> cageSearchConditions = {"sledgehammer"};

    Action* cageSearch = new Search(mainChar, cageSearchKey, room2, cageSearchContext, cageSearchConditions, room2Items);

    room2Actions[cageSearch->getKey()] = cageSearch;


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
    coatSearchContext["conditions_met"] = "Upon touching the lab coat, you hear a sound coming from one of the pocket. You found two keys! One key is labeled 'Kennel' the other, 'Safe'.";

    coatSearchContext["searched"] = "There doesn't seem to be anything here.";

    vector<Item> keys = {Item("safe_key"), Item("kennel_key")};

    vector<string> coatSearchConditions;

    Action* coatSearch = new Search(mainChar, coatSearchKey, room2, coatSearchContext, crateSearchConditions, keys);

    room2Actions[coatSearch->getKey()] = coatSearch;


    //open safe leave room 2
    string changeRoomSafeKey = "open_safe";
    map<string,string> changeRoomSafeContext;
    changeRoomSafeContext["conditions_met"] = "You hear a 'click' - You've cracked the code! You proceed to turn the safe's handle and pull the heavy door outwards - revealing its contents. Inside is nothing else other than what looks like a futuristic toy gun. You're slightly disappointed, but realize the gun would make a great toy for your nephew. Better check if it still works. You aim the gun at the cement wall in front of you and with your best Schwarzenegger accent, you deliver your totally original line - \"Hasta la vista, baby\". You press the trigger. A large portal opens up on the wall. Startled, you drop the gun and take a step back which causes you to stumble on the kennel behind you, flipping it over and making the kennel's bottom floor come loose – liberating Snowballs. The dog slowly approaches you with a menacing look on its face. You slowly back away while suddenly – you find yourself in a medieval town – No portal. No dog. No garage. You start inspecting your surroundings – to each of your sides seems to be a variety of buildings; each of them decorated with their own storefront sign – There's a store which you're not sure what is being sold, another store labeled 'general store' and a castle can be seen far in the distance. People are coming and going.";

    changeRoomSafeContext["conditions_not_met"] = "The door still seems stuck and won't open";

    changeRoomSafeContext["change_room"] = "medieval_village";

     vector<Item> changeRoomSafeItems;

     vector<string> changeRoomSafeConditions = { "safe_key" };

     Action* changeRoomSafe = new ChangeRoom(mainChar, changeRoomSafeKey, room2, changeRoomSafeContext, changeRoomSafeConditions, changeRoomSafeItems);

     room2Actions[changeRoomSafe->getKey()] = changeRoomSafe;

     room2->setActions(room2Actions);

     rooms[room2->getKey()]= room2;

     //**************************************ROOM 4***********************************************************************

//    string room2Key = "castle";
//    string room2Intro = "\“Hahaha! I have made millions for the past five years reselling the food the villagers produced, the best part is I haven’t even had to pay taxes to the legion of kings. At this rate, I will be the richest king of all time in no time. Oh I hope no one is hearing me speak out loud about my crimes. One could not only put my life in jeopardy with this information, but this person could also overtake my position as King.\""
//
//    "Finally wrapping up your business in the bathroom, you make your way to the throne room. "
//
//    "\"A yes, Mr. slippery stairs I’ve been expecting you.\"";
//
//    map<char,string> room2TopMenuOutput;
//    room2TopMenuOutput['1'] = "Kill King JellyBean";
//    room2TopMenuOutput['2'] = "Blackmail the king about his tax evasions";
//
//
//    map<char,string> room2TopMenuInput;
//    room2TopMenuInput['1'] = "talk_king";
//    room2TopMenuInput['2'] = "talk_jelly";







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
    map<string, string> villagerDialog;
    villagerDialog["conditions_met"] = "\“Oh bless you kind sir. I do not have much to offer, but please accept this invitation"
                                        "to the king castle for the ball.\”";
    villagerDialog["conditions_not_met"] = "\“Well thanks for nothing. Wow, what a tease.\”";
    villagerDialog["talked"] = "“Your generosity is greatly appreciated - kind sir. If only we could have a king as generous as you.”";

    villager->setDialog(villagerDialog);

    map<string, Action*> room3Actions;

    // MENUS
    string room3TopMenuMessage = "What would you like to do?: ";

    map<char, string> room3TopMenuOutput;
    room3TopMenuOutput['1'] = "Talk to Villager";
    room3TopMenuOutput['2'] = "Go to Unknown Store";
    room3TopMenuOutput['3'] = "Go to General Store";
    room3TopMenuOutput['4'] = "Go to Castle";

    map<char, string> room3TopMenuInput;
    room3TopMenuInput['1'] = "talk_villager";
    room3TopMenuInput['2'] = "unknown_store";
    room3TopMenuInput['3'] = "general_store";
    room3TopMenuInput['4'] = "castle";

    Menu* room3TopMenu = new Menu(menuOutput, room3TopMenuOutput, room3TopMenuInput);

    string room3TalkMenuMessage =   "\"Oh, good day kind sir. I can tell by the clothes you’re wearing that you are not from here. Want my "
                                    "advice – turn back and return to where you’ve come from. King Jelly Bean is using all of the food "
                                    "supplies and we’re all slowly dying. But before you leave, would you have any food to spare?\"";

    map<char, string> room3TalkMenuOutput;
    room3TalkMenuOutput['1'] = "Give the villager some food.";
    room3TalkMenuOutput['2'] = "Ignore the hungry villager.";

    map<char, string> room3TalkMenuInput;
    room3TalkMenuInput['1'] = "give_food";
    room3TalkMenuInput['2'] = "ignore";

    Menu* room3TalkMenu = new Menu(room3TalkMenuMessage, room3TalkMenuOutput, room3TalkMenuInput);

    string room3UnknownStoreMenuMessage =    "“Hey, are you tired of real doors, cluttering up your house, where you open 'em, and they actually go"
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

    map<char, string> room3UnknownStoreMenuInput;
    room3UnknownStoreMenuInput['1'] = "search_door_1";
    room3UnknownStoreMenuInput['2'] = "search_door_2";
    room3UnknownStoreMenuInput['3'] = "search_door_3";
    room3UnknownStoreMenuInput['4'] = "search_door_4";
    room3UnknownStoreMenuInput['5'] = "search_door_5";
    room3UnknownStoreMenuInput['6'] = "leave";

    Menu* room3UnknownStoreMenu = new Menu(room3UnknownStoreMenuMessage, room3UnknownStoreMenuOutput, room3UnknownStoreMenuInput);

    string room3GeneralStoreMenuMessage = "\"Welcome to the General store what would you like to buy? We have a loaf of bread for 30 Smeckles. That’s it.\"";

    map<char, string> room3GeneralStoreMenuOutput;
    room3GeneralStoreMenuOutput['1'] = "Buy a loaf of bread.";
    room3GeneralStoreMenuOutput['2'] = "Go back to the village.";
    room3GeneralStoreMenuOutput['3'] = "Print inventory.";

    map<char, string> room3GeneralStoreMenuInput;
    room3GeneralStoreMenuInput['1'] = "buy_bread";
    room3GeneralStoreMenuInput['2'] = "leave";
    room3GeneralStoreMenuInput['3'] = "print_inventory";

    Menu* room3GeneralStoreMenu = new Menu(room3GeneralStoreMenuMessage, room3GeneralStoreMenuOutput, room3GeneralStoreMenuInput);

    string room3CastleMenuMessage = "Upon arriving to the castle wall, you are confronted by two guards. \"Halt! What business do you have with King Jelly Bean?\"";

    map<char, string> room3CastleOutput;
    room3CastleOutput['1'] = "I have an invitation";
    room3CastleOutput['2'] = "Try to sneak pass the guards.";
    room3CastleOutput['3'] = "Ask them to let you in with an assertive tone.";
    room3CastleOutput['4'] = "Go back to the village";

    map<char, string> room3CastleInput;
    room3CastleInput['1'] = "present_invitation";
    room3CastleInput['2'] = "sneak";
    room3CastleInput['3'] = "assertive";
    room3CastleInput['4'] = "leave";

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

    // TALK TO VILLAGER ACTION
    string talkToVillagerKey = "talk_villager_give_food";
    vector<string> talkVillagerConditions = { "bread" };
    vector<Item> talkVillagerItems = { Item("invitation") };

    Action* talkToVillagerAction = new Talk(mainChar, talkToVillagerKey, villager, talkVillagerConditions, talkVillagerItems);

    room3Actions[talkToVillagerAction->getKey()]= talkToVillagerAction;

    // ***********************************************************************************************************
    // Ignore Villager

    string ignoreVillagerKey = "talk_villager_ignore";

    vector<Item> ignoreVillagerItems;
    vector<string> ignoreVillagerConditions;

    map<string, string> ignoreVillagerContext;

    ignoreVillagerContext["change_room"] = room3->getKey();

    Action* ignoreVillager = new ChangeRoom(mainChar, ignoreVillagerKey, room3, ignoreVillagerContext,
                                                  ignoreVillagerConditions, ignoreVillagerItems);

    room3Actions[ignoreVillager->getKey()] = ignoreVillager;

    // ************************************************************************************************************

    // Door1
    string searchDoor1Key = "unknown_store_search_door_1";
    map<string, string> searchDoor1Context;
    searchDoor1Context["conditions_not_met"] = "\“Oh boy – that’s a fake door. Better luck next time pal!\”";
    searchDoor1Context["conditions_met"] = "\"Get out of here. I already gave you my damn smeckles!\"";

    vector<Item> searchDoor1Items;

    vector<string> searchDoor1Conditions = { "unknown_store_search_door_2" };

    Action* searchDoor1 = new Search(mainChar, searchDoor1Key, room3, searchDoor1Context, searchDoor1Conditions, searchDoor1Items);

    room3Actions[searchDoor1->getKey()] = searchDoor1;

    // **************************************************************************************************************

    // Door2
    string searchDoor2Key = "unknown_store_search_door_2";
    map<string, string> searchDoor2Context;
    searchDoor2Context["conditions_met"] = "“Wow, you really know your fake doors – a real connoisseur. Here are your thirty Smeckles kind sir. I"
                                            "don’t know I am still in business doing that - This game is full of plot holes.\”";

    searchDoor2Context["searched"] = "“Hey, I know you. You’re that fake door master who cost me 30 Smeckles. Get out of here!”";

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
    string searchDoor3Key = "unknown_store_search_door_3";
    map<string, string> searchDoor3Context;
    searchDoor3Context["conditions_not_met"] = "\“Oh boy – that’s a fake door. Better luck next time pal!\”";
    searchDoor3Context["conditions_met"] = "\"Get out of here. I already gave you my damn smeckles!\"";
    searchDoor3Context["searched"] = "\"Sorry, No more food – store closed\".";

    vector<Item> searchDoor3Items;

    vector<string> searchDoor3Conditions = { "unknown_store_search_door_2" };

    Action* searchDoor3 = new Search(mainChar, searchDoor3Key, room3, searchDoor3Context, searchDoor3Conditions, searchDoor3Items);

    room3Actions[searchDoor3->getKey()] = searchDoor3;

    // **************************************************************************************************************

    // Door4
    string searchDoor4Key = "unknown_store_search_door_4";
    map<string, string> searchDoor4Context;
    searchDoor4Context["conditions_not_met"] = "\“Oh boy – that’s a fake door. Better luck next time pal!\”";
    searchDoor4Context["conditions_met"] = "\"Get out of here. I already gave you my damn smeckles!\"";

    vector<Item> searchDoor4Items;

    vector<string> searchDoor4Conditions = { "unknown_store_search_door_2" };

    Action* searchDoor4 = new Search(mainChar, searchDoor4Key, room3, searchDoor4Context, searchDoor4Conditions, searchDoor4Items);

    room3Actions[searchDoor4->getKey()] = searchDoor4;

    // **************************************************************************************************************

    // Door5
    string searchDoor5Key = "unknown_store_search_door_5";
    map<string, string> searchDoor5Context;
    searchDoor5Context["conditions_not_met"] = "\“Oh boy – that’s a fake door. Better luck next time pal!\”";
    searchDoor5Context["conditions_met"] = "\"Get out of here. I already gave you my damn smeckles!\"";

    vector<Item> searchDoor5Items;

    vector<string> searchDoor5Conditions = { "unknown_store_search_door_2" };

    Action* searchDoor5 = new Search(mainChar, searchDoor5Key, room3, searchDoor5Context, searchDoor5Conditions, searchDoor5Items);

    room3Actions[searchDoor5->getKey()] = searchDoor5;
    //***************************************************************************************************************

    // Leave Unknown Store

    string leaveUnknownStoreKey = "unknown_store_leave";

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

    string buyBreadKey = "general_store_buy_bread";

    map<string, string> buyBreadContext;
    buyBreadContext["conditions_met"] = "“Enjoy! You know, not many people get to eat around here. I hope you really enjoy every bite of that loaf you just bought while someone else out there doesn’t.”";
    buyBreadContext["conditions_not_met"] = "“You don’t have enough Smeckles. No Smeckles, no food.”";

    vector<Item> buyBreadItems = { Item("bread") };
    vector<string> buyBreadConditions = { "smeckle" };

    Action* buyBread = new Search(mainChar, buyBreadKey, room3, buyBreadContext, buyBreadConditions, buyBreadItems);

    room3Actions[buyBread->getKey()] = buyBread;

    //***************************************************************************************************************

    // Leave General Store


    string leaveGeneralStoreKey = "general_store_leave";

    vector<Item> leaveGeneralStoreItems;
    vector<string> leaveGeneralStoreConditions;

    map<string, string> leaveGeneralStoreContext;

    leaveGeneralStoreContext["change_room"] = room3->getKey();

    Action* leaveGeneralStore = new ChangeRoom(mainChar, leaveGeneralStoreKey, room3, leaveGeneralStoreContext,
                                                  leaveGeneralStoreConditions, leaveGeneralStoreItems);

    room3Actions[leaveGeneralStore->getKey()] = leaveGeneralStore;

    //***************************************************************************************************************

    // Invitation
    string presentInvitationKey = "castle_present_invitation";

    vector<Item> presentInvitationItems;
    vector<string> presentInvitationConditions = {"invitation"};

    map<string, string> presentInvitationContext;

    presentInvitationContext["conditions_not_met"] = "Oh yeah? Well where is it? HUH? Get your ass outta here!";
    presentInvitationContext["change_room"] = "final_room";

    Action* presentInvitation = new ChangeRoom(mainChar, presentInvitationKey, room3, presentInvitationContext,
                                                  presentInvitationConditions, presentInvitationItems);

    room3Actions[presentInvitation->getKey()] = presentInvitation;
    //***************************************************************************************************************

    //Sneak
    string sneakPastKey = "castle_sneak";

    vector<Item> sneakPastItems;
    vector<string> sneakPastConditions;

    map<string, string> sneakPastContext;

    sneakPastContext["change_room"] = "sneak_death";

    Action* sneakPast = new ChangeRoom(mainChar, sneakPastKey, room3, sneakPastContext,
                                                  sneakPastConditions, sneakPastItems);

    room3Actions[sneakPast->getKey()] = sneakPast;

    // **************************************************************************************************************

    // Assertive
    string beAssertiveKey = "castle_assertive";

    vector<Item> beAssertiveItems;
    vector<string> beAssertiveConditions;

    map<string, string> beAssertiveContext;

    beAssertiveContext["change_room"] = "assertive_death";

    Action* beAssertive = new ChangeRoom(mainChar, beAssertiveKey, room3, beAssertiveContext,
                                                  beAssertiveConditions, beAssertiveItems);

    room3Actions[beAssertive->getKey()] = beAssertive;

    // *************************************************************************************************************

    // Go back to village

    string leaveCastleKey = "castle_leave";

    vector<Item> leaveCastleItems;
    vector<string> leaveCastleConditions;

    map<string, string> leaveCastleContext;

    leaveCastleContext["change_room"] = room3->getKey();

    Action* leaveCastle = new ChangeRoom(mainChar, leaveCastleKey, room3, leaveCastleContext,
                                                  leaveCastleConditions, leaveCastleItems);

    room3Actions[leaveCastle->getKey()] = leaveCastle;

    // *************************************************************************************************************

    room3->setActions(room3Actions);

    rooms[room3->getKey()] = room3;

    string levelKey = "intro";
    string startingLevelKey = "jerrys_garage";
    Level* level1 = new Level(levelKey, startingLevelKey, rooms);

    levels[level1->getKey()] = level1;
}
