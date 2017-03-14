#ifndef XMLLOADDATA_H
#define XMLLOADDATA_H
#include "tinyxml2.h"
#include "SaveData.h"
using namespace tinyxml2;

class XMLLoadData
{
public:
    static bool loadData(SaveData);

};

#endif // XMLLOADDATA_H
