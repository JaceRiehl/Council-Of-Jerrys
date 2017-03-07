#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>
#include <iostream>
#include <ostream>
using namespace std;

const int COLUMN = 60;

class TextBox //: public Window
{
public:
    TextBox(std::string);
    virtual ~TextBox();
    TextBox(TextBox&);
    void copy(TextBox&);
    void operator=(TextBox&);
    void print(ostream&) const;
    friend ostream& operator<<(ostream&, const TextBox&);

private:
    void fillChar(int, char, ostream&) const;

    char ** textBody;
    int rows;
};

#endif
