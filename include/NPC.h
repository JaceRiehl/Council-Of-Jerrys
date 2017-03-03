#ifndef NPC_H
#define NPC_H

#include <Character.h>
#include <string>

class NPC : public Character
{
    public:
        NPC(string name);
        virtual ~NPC(){};

    protected:

    private:
};

#endif // NPC_H
