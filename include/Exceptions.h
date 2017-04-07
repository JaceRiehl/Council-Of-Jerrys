#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>
/**
    @file Exceptions.h
    @author Michel Martel
    @date March 3, 2017
    @brief Exceptions is the class where all thrown errors are stored.
*/

class characterNameError: public std::runtime_error
{
public:
    /**
        @brief runtime_error for when a name with length 0 or exceeding 30 is provided.
        @pre a pointer to an error message
        @post the given message is displayed as a runtime_error.
        @param Pointer to an error message.
        @return runtime_error with given message.
    */
    characterNameError(const char* errMessage) :
        std::runtime_error(errMessage){}
};

class itemDoesNotExist: public std::runtime_error
{
public:
    /**
        @brief runtime_error used by Inventory::getItem for when a user tries to get an item which does not exist.
        @pre a pointer to an error message
        @post the given message is displayed as a runtime_error.
        @param Pointer to an error message.
        @return runtime_error with given message.
    */
    itemDoesNotExist(const char* errMessage) :
        std::runtime_error(errMessage){}
};

class inventoryEmpty: public std::runtime_error
{
public:
    /**
        @brief runtime_error used for when a user tries to create an empty inventory.
        @pre a pointer to an error message
        @post the given message is displayed as a runtime_error.
        @param Pointer to an error message.
        @return runtime_error with given message.
    */
    inventoryEmpty(const char* errMessage) :
        std::runtime_error(errMessage){}
};

class itemNameError: public std::runtime_error
{
public:
    /**
        @brief runtime_error for when an item name with length 0 or exceeding 30 is provided.
        @pre a pointer to an error message
        @post the given message is displayed as a runtime_error.
        @param Pointer to an error message.
        @return runtime_error with given message.
    */
    itemNameError(const char* errMessage) :
        std::runtime_error(errMessage){}
};

class keyDoesNotExist: public std::runtime_error
{
public:
    /**
        @brief runtime_error used for when a user tries to get a key which does not exist.
        @pre a pointer to an error message
        @post the given message is displayed as a runtime_error.
        @param Pointer to an error message.
        @return runtime_error with given message.
    */
    keyDoesNotExist(const char* errMessage) :
        std::runtime_error(errMessage){}
};

class invalid_action : public std::runtime_error
{
public:
    /**
        @brief runtime_error used for when an action is used that cannot be run.
        @pre a pointer to an error message
        @post the given message is displayed as a runtime_error.
        @param Pointer to an error message.
        @return runtime_error with given message.
    */
    invalid_action(const char* errMessage) :
        std::runtime_error(errMessage){}
};

#endif // EXCEPTIONS_H_INCLUDED
