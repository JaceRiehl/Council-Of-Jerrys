#ifndef PLAYERCHOICE_H
#define PLAYERCHOICE_H

#include <vector>
#include <string>

class PlayerChoice //: public Window
{
public:
    PlayerChoice(std::vector<std::string>);
    ~PlayerChoice();
    void print();
private:
    std::vector<std::string> plyrActions;

};

#endif
