#include "TextBox.h"
#include <string>
#include <iostream>
using namespace std;

TextBox::TextBox(std::string body)
{
    rows = static_cast<int>(body.size()/COLUMN)+1;
    textBody = new char*[rows];
    int lastSpace = 0;
    int counter = 0;

    for(int i = 0; i < rows; i++)
    {
        textBody[i] = new char[COLUMN];
            for(int s = counter; s < counter+COLUMN; s++)
                {
                    if(body[s] == ' ')
                        lastSpace = s;
                    if(i == rows-1)
                        lastSpace = body.size();
                }
        for(int j = 0; j < COLUMN; j++)
        {
            if(j == 0 && body[counter] == ' ')
                counter++;
            if(counter >= lastSpace)
                textBody[i][j] = ' ';
            else
                textBody[i][j] = body[counter++];
        }
    }
}
TextBox::~TextBox()
{
    for(int i = 0; i < rows; i++)
        delete [] textBody[i];
    delete [] textBody;
}
void TextBox::print()
{
    fillChar(80, '|');
    cout<<endl<<'|';
    fillChar(78, ' ');
    cout<<'|'<<endl<<'|';
    fillChar(78, ' ');
    cout<<'|'<<endl;
    for(int i = 0; i < rows; i++)
    {
        cout<<'|';
        fillChar(9, ' ');
        for(int j = 0; j < COLUMN; j++)
            cout<<textBody[i][j];
        fillChar(9, ' ');
        cout<<'|'<<endl;
    }
    cout<<'|';
    fillChar(78, ' ');
    cout<<'|'<<endl<<'|';
    fillChar(78, ' ');
    cout<<'|'<<endl;
    fillChar(80, '|');
    cout<<endl;
}
void TextBox::fillChar(int howMany, char ch)
{
    for(int i = 0; i < howMany; i++)
        cout<<ch;
}
