#ifndef BULLET_H
#define BULLET_H
#include "myobj.h"

class bullet : public myObj
{
public:
    bullet(QString path):myObj(path){
        set_height(11);
        set_lenth(5);
        set_min(-5,-11);
    }
    void move();
    void set_isEnemy(bool val){isEnemy=val;}
    bool get_isEnemy(){return isEnemy;}
private:
    bool isEnemy=false;
};

#endif // BULLET_H
