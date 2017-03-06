#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

class characterNameError: public std::runtime_error
{
public:
    characterNameError(const char* errMessage) :
        std::runtime_error(errMessage){}
};

class itemDoesNotExist: public std::runtime_error
{
public:
    itemDoesNotExist(const char* errMessage) :
        std::runtime_error(errMessage){}
};

class inventoryEmpty: public std::runtime_error
{
public:
    inventoryEmpty(const char* errMessage) :
        std::runtime_error(errMessage){}
};
#endif // EXCEPTIONS_H_INCLUDED
