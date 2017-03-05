#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>

const int COLUMN = 60;

class TextBox //: public Window
{
public:
    TextBox(std::string);
    virtual ~TextBox();
    TextBox(TextBox&);
    void copy(TextBox&);
    void operator=(TextBox&);
    void print();
    void fillChar(int, char);

private:
    char ** textBody;
    int rows;
};

#endif
