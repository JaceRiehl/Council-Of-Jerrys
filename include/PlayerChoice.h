#ifndef PLAYERCHOICE_H
#define PLAYERCHOICE_H

#include <vector>
#include <string>

class PlayerChoice //: public Window
{
public:
    PlayerChoice();
//    PlayerChoice(std::map<char, string>);
    PlayerChoice(std::vector<std::string>);
    ~PlayerChoice();
    void operator=(PlayerChoice &);
    bool isEmpty();
    void print();

private:
    std::vector<std::string> plyrActions;


};

#endif
