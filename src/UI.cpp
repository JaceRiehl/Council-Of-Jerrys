#include "UI.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

UI::UI(string body, vector<string> choices) : actions(choices)
{
    rows = static_cast<int>(body.size()/60)+1;
    textBody = new char*[rows];
    int counter = 0;
    for(int i = 0; i < rows; i++)
    {
        textBody[i] = new char[COLUMN];
        for(int j = 0; j < COLUMN; j++)
        {

            if(body.size() > counter)
                textBody[i][j] = body[counter++];
            else
                textBody[i][j] = ' ';
        }
    }

}
UI::~UI()
{
    for(int i = 0; i < rows; i++)
        delete [] textBody[i];
    delete [] textBody;
}
void UI::printUI()
{
    int choice;
    int choiceNum = static_cast<int>(actions.size());
    bool invalid = true;
    this->fill('*', 80);
    cout<<endl;
    for(int k = 0; k < 3; k++)
    {
        cout<<'*';
        this->fill(' ', 78);
        cout<<'*'<<endl;
    }
    for(int i = 0; i < rows; i++)
    {
        cout<<"*         ";
        for(int j = 0; j < COLUMN; j++)
        {
            cout<<getAt(i,j);
            if(j  == 59)
                cout<<"         *"<<endl;
        }
    }
    for(int k = 0; k < 3; k++)
    {
        cout<<'*';
        this->fill(' ', 78);
        cout<<'*'<<endl;
    }
    this->fill('*', 80);
    cout<<endl;
    for(int n = 0; n < choiceNum; n++)
        cout<<n+1<<") "<<actions[n]<<endl;
    cout<<endl<<"Enter your Choide: ";
    cin>>choice;
    if(choice < 0 || choice > choiceNum)
    {
        cout<<"Invalid entry, try again: ";
        invalid = false;
    }
    else
        invalid = true;
}
void UI::fill(char fillVal, int howMany)
{
    for(int i = 0; i < howMany; i++)
        cout<<fillVal;
}
char UI::getAt(int x, int y)
{
    return textBody[x][y];
}
