#ifndef IOINFO_H
#define IOINFO_H

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::filebuf;

class IOInfo
{
    public:
        IOInfo();
        IOInfo(string, string);
        ~IOInfo();

        ostream& getOutputStream() const;
        istream& getInputStream() const;

    private:
        ostream* outputStream;
        istream* inputStream;

        filebuf* outputBuffer;
        filebuf* inputBuffer;
};

#endif // IOINFO_H
