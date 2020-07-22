#ifndef MYOBJ_H
#define MYOBJ_H
#include <QPixmap>
#include <QRectF>
#include <vector>
using namespace ::std;

class myObj
{
public:
    QString src="";
    QPixmap pic;//自身图片
    myObj(QString path);

    bool move_left();
    bool move_right();
    bool move_up();
    bool move_down();
    bool move_Step();

    bool set_lenth(int val);
    bool set_height(int val);
    bool set_rotate(int val);
    bool set_x_pos(int val);
    bool set_y_pos(int val);
    bool set_speed(int val);
    void set_Active(bool val);
    bool get_isActive(){return isActive;}
    bool get_isChanged(){return isChanged;}
    vector<int>shape();//返回形状数据
    bool check(vector<int>A,vector<int>B);//碰撞检测函数
    void set_min(int x,int y){min_x=x;min_y=y;}

private:
    int x_pos=0,y_pos=0;
    int lenth=100,height=100;
    int speed=10;
    int rotate=0;//旋转角度
    double k=0.0;
protected:
    bool isChanged;//位置是否改变
    bool isActive;//是否依然被激活
    int screen_x=600;
    int screen_y=800;
    int min_x;
    int min_y;
};

#endif // MYOBJ_H
