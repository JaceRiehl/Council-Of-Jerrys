#include "DataManager.h"

DataManager* DataManager::_instance = nullptr;

DataManager* DataManager::Instance()
{
    if(!_instance)
        _instance = new DataManager();

    return _instance;
}

DataManager::DataManager()
{
    dataLoader = FakeDataLoader::Instance();
}

bool DataManager::saveGameData()
{
    return XMLSaveData::saveData();
}

bool DataManager::loadNewData(PlayableCharacter* mainChar)
{
    if(XMLLoadData::loadData(XMLLoadData::NEW_DATA_PATH))
    {
        loadCharacter(mainChar);
        return true;
    }

    return false;
}

bool DataManager::loadSaveData(PlayableCharacter* mainChar)
{
    if(XMLLoadData::loadData(XMLLoadData::SAVED_DATA_PATH))
    {
        loadCharacter(mainChar);
        return true;
    }

    return false;
}

map<string, Level*> DataManager::loadGameData(PlayableCharacter* mainChar)
{
    map<string, Level*> gameData;

    dataLoader->LoadLevels(mainChar, gameData);

    return gameData;
}

map<string, string> DataManager::loadEndGameText()
{
    map<string, string> endGameText;

    dataLoader->LoadEndOfGameText(endGameText);

    return endGameText;
}

void DataManager::loadCharacter(PlayableCharacter* mainChar)
{
    if(!mainChar)
        return;

    Item* itemToAdd = nullptr;
    vector<string> savedItems = XMLSaveData::Data.inventoryItems;
    for(auto& str : savedItems)
    {
        itemToAdd = new Item(str);
        mainChar->addItem(*itemToAdd);
    }

    mainChar->setActionsTaken(XMLSaveData::Data.playerActions);
}
