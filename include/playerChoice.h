#ifndef PLAYERCHOICE_H
#define PLAYERCHOICE_H

#include "Window.h"
#include <vector>
#include <string>

class playerChoice //: public Window
{
public:
    playerChoice(std::vector<std::string>);
    ~playerChoice();
private:
    std::vector<std::string> plyrActions;
    
};

#endif
