#ifndef ENEMY_H
#define ENEMY_H
#include "myobj.h"

class enemy : public myObj
{
public:
    enemy(QString path):myObj(path){
        set_lenth(50);
        set_height(50);
        set_min(-50,-50);
    }
    void enemy_move();
    void set_Out_border(bool val){Out_border=val;}
    bool get_out_border(){return Out_border;}
    int pic_index=0;//摧毁图片变化
    int times=3;//帧数
protected:
    bool Out_border=false;
};

#endif // ENEMY_H
