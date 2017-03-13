#include "SearchTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(SearchTest);

void SearchTest::testConditionsNotMet()
{
    PlayableCharacter* mainChar = new PlayableCharacter("Jerry");
    Room* roomToSearch = new Room(mainChar);

    map<string, string> searchContext;
    searchContext["conditions_not_met"] = "cnm";
    searchContext["conditions_met"] = "cm";
    searchContext["searched"] = "sd";

    vector<string> conditions = { "search_carpet" };

    Action* searchAction = new Search(mainChar, "search_shelf", roomToSearch, searchContext, conditions);

    vector<string> playerActions;

    searchAction->execute(playerActions);
}

void SearchTest::testConditionsMet()
{
    PlayableCharacter* mainChar = new PlayableCharacter("Jerry");
    Room* roomToSearch = new Room(mainChar);

    map<string, string> searchContext;
    searchContext["conditions_not_met"] = "cnm";
    searchContext["conditions_met"] = "cm";
    searchContext["searched"] = "sd";

    vector<string> conditions = { "search_carpet" };

    Action* searchAction = new Search(mainChar, "search_shelf", roomToSearch, searchContext, conditions);

    vector<string> playerActions = { "search_carpet" };

    searchAction->execute(playerActions);
}

void SearchTest::testSearched()
{
    PlayableCharacter* mainChar = new PlayableCharacter("Jerry");
    Room* roomToSearch = new Room(mainChar);

    map<string, string> searchContext;
    searchContext["conditions_not_met"] = "SEARCHTEST: CONDITIONS NOT MET";
    searchContext["conditions_met"] = "SEARCHTEST: CONDTIONS MET";
    searchContext["searched"] = "SEARCHTEST: SEARCHED";

    vector<string> conditions = { "search_carpet" };

    Action* searchAction = new Search(mainChar, "search_shelf", roomToSearch, searchContext, conditions);

    vector<string> playerActions = { "search_shelf" };

    searchAction->execute(playerActions);
}
