#ifndef COMMDATA_H
#define COMMDATA_H

//用于数据交换的类
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define SHOT 4
#include <vector>
#include "enemy.h"
#include "bullet.h"

using namespace ::std;
class commdata
{
public:
    int Instraction;
    bool isShot=false;
    vector<int>enemy_pos_x{0,550};
    vector<enemy>enemies;
    vector<bullet>bullets;
    commdata();
};
extern commdata buffer;
#endif // COMMDATA_H
