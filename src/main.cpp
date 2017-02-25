#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "Hello, world" << endl;

     string text, a, b, c, d;
    text = "This is a test for the body This ihis is a test for the body This ihis is a test for the body This ihis is a test for the body This ihis i\
s a test for the body This ihis is a test for the body This ihis is a test for the body This i";
    a = "This is action one";
    b = "This is action two";
    c = "This is action three";
    d = "This is action four";
    vector<string> actn;
    actn.push_back(a);
    actn.push_back(b);
    actn.push_back(c);
    actn.push_back(d);

    UI UITest(text, actn);
    UITest.printUI();
}
