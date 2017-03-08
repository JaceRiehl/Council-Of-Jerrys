#ifndef UI_H
#define UI_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int COLUMN = 60;

class UI
{
public:
    UI(string, vector<string>);
    ~UI();
    void printUI();
    void fill(char, int);
    char getAt(int=0, int=0);
    
private:
    int rows;
    vector<string> actions;
    char ** textBody;
};

#endif
