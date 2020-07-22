#include "myobj.h"
#include <cmath>
#include <QRectF>
using namespace ::std;

const double pi(3.14159265);

myObj::myObj(QString path)
{
    pic=QPixmap(path);
}

bool myObj::set_lenth(int val){
    if(val<=600&&val>=0){
        lenth=val;
        return true;
    }
    return false;
}

bool myObj::set_x_pos(int val){
    if(val<=screen_x-lenth&&val>=min_x){
        x_pos=val;
        return true;
    }
    return false;
}

bool myObj::set_y_pos(int val){
    if(val<=screen_y-height&&val>=min_y){
        y_pos=val;
        return true;
    }
    return false;
}

bool myObj::set_height(int val){
    if(val<=600&&val>=0){
        height=val;
        return true;
    }
    return false;
}

bool myObj::set_rotate(int val){
    if(val<=90&&val>=0){
        rotate=val;
        return true;
    }
    return false;
}

bool myObj::set_speed(int val){
    if(val<=30&&val>=0){
        speed=val;
        return true;
    }
    return false;
}

vector<int>myObj::shape(){
    return vector<int>{x_pos,y_pos,lenth,height};
}

bool myObj::move_left(){
    return set_x_pos(x_pos-speed);
}

bool myObj::move_right (){
    return set_x_pos(x_pos+speed);
}

bool myObj::move_up(){
    return set_y_pos(y_pos-speed);
}

bool myObj::move_down(){
    return set_y_pos(y_pos+speed);
}

void myObj::set_Active(bool val){
    isActive=val;
}

bool myObj::move_Step(){
    //计算出轨道公式
    int new_y=y_pos-speed;
    double k = tan(rotate*pi/180);
    int new_x= int(double(x_pos)-double(y_pos-new_y)/k);
    set_x_pos(new_x);
    set_y_pos(new_y);
    return true;
}

bool myObj::check(vector<int> A, vector<int> B){
    //坐标转换
    A[2]+=A[0];
    A[3]+=A[1];

    B[2]+=B[0];
    B[3]+=B[1];

   return !(A[2] <= B[0] ||A[3] <= B[1] || A[0] >= B[2] ||  A[1] >= B[3]);
}
