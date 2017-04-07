#ifndef XMLLOADDATA_H
#define XMLLOADDATA_H
#include "tinyxml2.h"
#include "XMLSaveData.h"

using namespace tinyxml2;

class XMLLoadData
{
    public:
        static bool loadData(string filePath);
        static const string SAVED_DATA_PATH;
        static const string NEW_DATA_PATH;
};

#endif // XMLLOADDATA_H

