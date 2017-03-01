#include "Situation.h"

Situation:Situation(vector<Character> chars, map<string,Action> action, int i = 0)
{
    characters = chars;
    actions = action;
    index = i;
}
string Situation::run()
{

    for(int i = index; i < situations.size(); i++)
    {
        string result;
        situationResults[result]->executeAction();

    }

   return returned:

}
