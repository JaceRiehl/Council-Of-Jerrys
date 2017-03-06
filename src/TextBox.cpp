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
    textBody = nullptr;
}
TextBox::TextBox(TextBox& tb)
{
    this->copy(tb);
}
void TextBox::copy(TextBox& c)
{
    this->rows = c.rows;
    textBody = new char*[rows];
    for(int i = 0; i < rows; i++)
    {
        textBody[i] = new char[COLUMN];
        for(int j = 0; j < COLUMN; j++)
            this->textBody[i][j] = c.textBody[i][j];
    }
}
void TextBox::operator=(TextBox& t)
{
    if(this != &t)
    {
        for(int i = 0; i < rows; i++)
        delete [] textBody[i];
        delete [] textBody;
        textBody = nullptr;
            this->copy(t);
    }
}
void TextBox::print(ostream& os) const
{
    fillChar(80, '|', os);
    os<<endl<<'|';
    fillChar(78, ' ', os);
    os<<'|'<<endl<<'|';
    fillChar(78, ' ', os);
    os<<'|'<<endl;
    for(int i = 0; i < rows; i++)
    {
        os<<'|';
        fillChar(9, ' ', os);
        for(int j = 0; j < COLUMN; j++)
            os<<textBody[i][j];
        fillChar(9, ' ', os);
        os<<'|'<<endl;
    }
    os<<'|';
    fillChar(78, ' ', os);
    os<<'|'<<endl<<'|';
    fillChar(78, ' ', os);
    os<<'|'<<endl;
    fillChar(80, '|', os);
    os<<endl;
}
void TextBox::fillChar(int howMany, char ch, ostream& os) const
{
    for(int i = 0; i < howMany; i++)
        os<<ch;
}

ostream& operator<<(ostream& os, const TextBox& x)
{
    x.print(os);
    return os;
}
