#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Window.h"
#include <string>

const int COLUMN = 60;

class TextBox //: public Window
{
public:
    TextBox(std::string);
    ~TextBox();
    
private:
    char ** textBody;
    int rows;
};

#endif
