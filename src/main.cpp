#include "Window.h"
#include"PlayerChoice.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using std::cout;
using std::endl;

int main()
{
     string text, a, b, c, d;
    text = "Hello this is some text to try out how this thing will work i have no Idea what I am doing. this is getting weird Jerry!!!!!! oh well we will keep writing text to see what happends blah blah blassda. What if i keep adding text and more text and keep on writing text, IM FREAKING OUT!!!! holy crap what is going on??";
    a = "This is action one";
    b = "This is action two";
    c = "This is action three";
    d = "This is action four";
    vector<string> actn;
    actn.push_back(a);
    actn.push_back(b);
    actn.push_back(c);
    actn.push_back(d);
    TextBox testing(text);
    PlayerChoice choices(actn);
    testing.print();
    choices.print();
    return 0;
}
