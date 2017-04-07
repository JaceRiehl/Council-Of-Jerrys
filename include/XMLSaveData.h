#ifndef XMLSAVEDATA_H
#define XMLSAVEDATA_H
#include "tinyxml2.h"
#include "SaveData.h"
#include "Exceptions.h"



using namespace tinyxml2;

class XMLSaveData
{
public:
    static bool saveData();
    static SaveData Data;
};

#endif // XMLSAVEDATA_H
