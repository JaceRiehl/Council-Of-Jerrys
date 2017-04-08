#include "TextBox.h"
#include <string>
#include <iostream>
using namespace std;

char ch = '*';

TextBox::TextBox(std::string body)
{
    if(body == "")
        deallocateMem();
    else
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
        textBody[i] = new char[WIDTH];
        for(int j = 0; j < WIDTH; j++)
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
    if(textBody)
    {
        fillChar(80, ch, os);
        os<<'\n'<<ch;
        fillChar(78, ' ', os);
        os<<ch<<endl<<ch;
        fillChar(78, ' ', os);
        os<<ch<<endl;
        for(int i = 0; i < rows; i++)
        {
            os<<ch;
            fillChar(9, ' ', os);
            for(int j = 0; j < WIDTH; j++)
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
}
void TextBox::fillChar(int howMany, char ch, ostream& os) const
{
    for(int i = 0; i < howMany; i++)
        os<<ch;
}

void TextBox::assignText(string body)
{
    this->deallocateMem();
    rows = static_cast<int>(body.size()/WIDTH);
    if(((int)(body.size()) % WIDTH) != 0)
        rows += 2;

    textBody = new char*[rows];
    int k = 0;

    for(int i = 0; i < rows; i++)
    {
        textBody[i] = new char[WIDTH];
        int j = 0;
        while(j < WIDTH)
        {
            if(body[k] == ' ' && j == 0)
            {
                ++k;
                continue;
            }

            if(k < body.size())
            {
                int wordLength = 1;
                int currentBodyIndex = k;
                while(body[++currentBodyIndex] != ' ' && currentBodyIndex < body.size())
                    wordLength++;

                if(wordLength >= WIDTH)
                    while(j < WIDTH)
                        textBody[i][j++] = body[k++];

                else if(j+wordLength >= WIDTH)
                    while(j < WIDTH)
                        textBody[i][j++] = ' ';

                else if(j+wordLength < WIDTH)
                {
                    int currentPosition = j;
                    while(j < currentPosition + wordLength)
                        textBody[i][j++]= body[k++];
                }

                else
                {
                    textBody[i][j++] = body[k++];
                }
            }

            else
                while(j < WIDTH)
                    textBody[i][j++] = ' ';

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

bool TextBox::isEmpty() const
{
    return (textBody == nullptr);
}

ostream& operator<<(ostream& os, const TextBox& x)
{
    x.print(os);
    return os;
}


