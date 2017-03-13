#include "TextBox.h"
#include <string>
#include <iostream>
using namespace std;

const char ch = '*';

TextBox::TextBox(std::string body)
{
    this->assignText(body);
}
TextBox::~TextBox()
{
    this->deallocateMem();
}
TextBox::TextBox(TextBox& tb)
{
    this->copy(tb);
}
void TextBox::copy(const TextBox& c)
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
void TextBox::operator=(const TextBox& t)
{
    if(this != &t)
    {
        this->deallocateMem();
            this->copy(t);
    }
}
void TextBox::print(ostream& os) const
{
    fillChar(80, ch, os);
    os<<endl<<ch;
    fillChar(78, ' ', os);
    os<<ch<<endl<<ch;
    fillChar(78, ' ', os);
    os<<ch<<endl;
    for(int i = 0; i < rows; i++)
    {
        os<<ch;
        fillChar(9, ' ', os);
        for(int j = 0; j < COLUMN; j++)
            os<<textBody[i][j];
        fillChar(9, ' ', os);
        os<<ch<<endl;
    }
    os<<ch;
    fillChar(78, ' ', os);
    os<<ch<<endl<<ch;
    fillChar(78, ' ', os);
    os<<ch<<endl;
    fillChar(80, ch, os);
    os<<endl;
}
void TextBox::fillChar(int howMany, char ch, ostream& os) const
{
    for(int i = 0; i < howMany; i++)
        os<<ch;
}

void TextBox::assignText(string body)
{
    this->deallocateMem();
    rows = static_cast<int>(body.size()/COLUMN)+1;
    textBody = new char*[rows];
    int lastSpace = 0;
    int counter = 0;

    for(int i = 0; i < rows; i++)
    {
        textBody[i] = new char[COLUMN];
            for(int s = counter; s < counter+COLUMN; s++)
                {
                    if(i == rows-1)
                        lastSpace = body.size();
                    else if(body[s] == ' ')
                        lastSpace = s;
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

void TextBox::deallocateMem()
{
    if(textBody != nullptr)
    {
        for(int i = 0; i < rows; i++)
            delete [] textBody[i];
        delete [] textBody;
        textBody = nullptr;
    }
}

ostream& operator<<(ostream& os, const TextBox& x)
{
    x.print(os);
    return os;
}
