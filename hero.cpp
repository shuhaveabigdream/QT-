#include "hero.h"
#include "bullet.h"
#include "commdata.h"

QString bullet_hero_src="C:\\Users\\root\\Documents\\game\\res\\bullet.png";

void Hero::shot(){
    bullet t(bullet_hero_src);
    vector<int>shape=this->shape();
    t.set_x_pos(shape[0]+50);
    t.set_y_pos(shape[1]);
    t.set_rotate(0);
    t.set_isEnemy(false);
    buffer.bullets.push_back(t);
}

bool Hero::hero_move(int val){
    if(val==LEFT)move_left();
    else if(val==RIGHT)move_right();
    else if(val==UP)move_up();
    else if(val==DOWN)move_down();
}
