#include "Window.h"
#include "PrintList.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using std::cout;
using std::endl;

int main()
{
    string text, a, b, c, d, aa, bb;
    text = "Hello this is some text to try out how this thing will work i have no Idea what I am doing. this is getting weird Jerry!!!!!! oh well we will keep writing text to see what happends blah blah blassda. What if i keep adding text and more text and keep on writing text, IM FREAKING OUT!!!! holy crap what is going on??";
    a = "talk";
    b = "Search";
    c = "Leave";
    aa = "Talk to Rick";
    bb = "talk to Summer";
    vector<string> actn;
    actn.push_back(a);
    actn.push_back(b);
    actn.push_back(c);
    map<char, string> ma;
    ma['1'] = "Hello";
    ma['b'] = "Bye";
    PrintList listActions(ma);
    vector<string> subAction;
    subAction.push_back(aa);
    subAction.push_back(bb);
    TextBox testing(text);
    Window window(testing);
    window.setPlayerChoice(listActions);
    window.print();
    return 0;

}
