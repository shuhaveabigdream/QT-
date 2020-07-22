#include "enemy.h"
#include "commdata.h"
#include "bullet.h"
void enemy::enemy_move(){

    int dir=rand()%3;
    if(dir==0){
        Out_border=move_left();
    }
    else if(dir==1){
        Out_border=move_right();
    }
    else if(dir==2){
        Out_border=move_down();
    }
}
