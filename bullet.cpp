#include "bullet.h"
#include "commdata.h"
void bullet::move(){
    if(isEnemy){
        //只需要改y
        isActive=move_down();
    }
    else{
        //只需要改y
        isActive=move_up();
    }
}
