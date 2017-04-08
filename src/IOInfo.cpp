#include "IOInfo.h"

IOInfo::IOInfo()
{
    outputStream = new ostream(cout.rdbuf());
    inputStream = new istream(cin.rdbuf());
}

IOInfo::IOInfo(string outputFile, string inputFile)
{
    inputBuffer = new filebuf();
    outputBuffer = new filebuf();
    if(!inputFile.empty())
    {
        if(inputBuffer->open(inputFile, std::ios::in))
            inputStream = new istream(inputBuffer);
        else
            cerr << "COULD NOT OPEN INPUT BUFFER" << endl;
    }

    if(!outputFile.empty())
    {
        if(outputBuffer->open(outputFile, std::ios::out | std::ios::trunc))
            outputStream = new ostream(outputBuffer);
        else
            cerr << "COULD NOT OPEN OUTPUT BUFFER" << endl;
    }

}

IOInfo::~IOInfo()
{
    if(inputBuffer->is_open())
    {
        inputBuffer->close();
        delete inputBuffer;
    }

    if(outputBuffer->is_open())
    {
        outputBuffer->close();
        delete outputBuffer;
    }

    if(outputStream)
        delete outputStream;

    if(inputStream)
        delete inputStream;
}

ostream& IOInfo::getOutputStream() const
{
    return *outputStream;
}

istream& IOInfo::getInputStream() const
{
    return *inputStream;
}
