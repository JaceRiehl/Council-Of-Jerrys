
#include "TextBox.h"
#include <string>

TextBox::TextBox(std::string body)
{
    rows = static_cast<int>(body.size()/COLUMN)+1;
    textBody = new char*[rows];
    bool endOfLine = false;
    
    int counter = 0;
    for(int i = 0; i < rows; i++)
    {
        endOfLine = false;
        textBody[i] = new char[COLUMN];
        for(int j = 0; j < COLUMN; j++)
        {
            if(body.size() > counter && i > 50 && body[counter] == ' ')
                endOfLine = true;
            if(body.size() > counter)
            {
                if(endOfLine)
                    textBody[i][j] = ' ';
                else
                    textBody[i][j] = body[counter++];
            }
            else
                textBody[i][j] = ' ';

            
            /*if(body.size() > counter)
                textBody[i][j] = body[counter++];
            else
                textBody[i][j] = ' ';
             */
        }
    }
}
TextBox::~TextBox()
{
    for(int i = 0; i < rows; i++)
        delete [] textBody[i];
    delete [] textBody;
}

