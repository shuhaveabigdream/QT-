#ifndef HERO_H
#define HERO_H
#include "myobj.h"
#include "commdata.h"
#include "bullet.h"

class Hero : public myObj
{
public:
    Hero(QString path):myObj(path){set_min(0,0);}
    void shot();
    bool hero_move(int val);
};

#endif // HERO_H
