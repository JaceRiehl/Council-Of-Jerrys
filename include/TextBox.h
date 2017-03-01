#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>

const int COLUMN = 60;

class TextBox //: public Window
{
public:
    TextBox(std::string);
    ~TextBox();
    void print();
    void fillChar(int, char);

private:
    char ** textBody;
    int rows;
};

#endif
