#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include "enemy.h"
#include "commdata.h"
#include <QKeyEvent>
#include <vector>
#include <time.h>
using namespace ::std;

Hero *role;

const QString enemy_src_path="C:\\Users\\root\\Documents\\game\\res\\enemy.png";
const QString hero_src_path="C:\\Users\\root\\Documents\\game\\res\\hero.png";
const QString enemy_distory1="C:\\Users\\root\\Documents\\game\\res\\enemy1_down1.png";
const QString enemy_distory2="C:\\Users\\root\\Documents\\game\\res\\enemy1_down2.png";
const QString enemy_distory3="C:\\Users\\root\\Documents\\game\\res\\enemy1_down3.png";
const QString hero_distory="C:\\Users\\root\\Documents\\game\\res\\enemy1_down3.png";

vector<QString>e_ds{enemy_distory1,enemy_distory2,enemy_distory3};

void QWidget::keyPressEvent(QKeyEvent *event){
    int key=event->key();
    if(key==Qt::Key_Left){
        buffer.Instraction=LEFT;
    }
    else if(key==Qt::Key_Right){
        buffer.Instraction=RIGHT;
    }
    else if(key==Qt::Key_Down){
        buffer.Instraction=DOWN;
    }
    else if(key==Qt::Key_Up){
        buffer.Instraction=UP;
    }
    else if(key==Qt::Key_Space){
        buffer.isShot=true;
    }
}

void QWidget::paintEvent ( QPaintEvent * ){

      QPainter painter(this);
     //刷新玩家飞机
     QPixmap pix=role->pic;
     vector<int>shape=role->shape();
     painter.drawPixmap(shape[0],shape[1],shape[2],shape[3],pix);
     //刷新敌人
     //边界超出检测
     for(int i=0;i<buffer.enemies.size();){
         if(!buffer.enemies[i].get_out_border()){
             buffer.enemies.erase(buffer.enemies.begin()+i);
         }
         else i++;
     }

     for(int i=0;i<buffer.enemies.size();){
         //碰撞检测
         for(bullet item:buffer.bullets){
             if(item.get_isEnemy()==false){
                  if(item.check(item.shape(),buffer.enemies[i].shape()))
                  {
                      buffer.enemies[i].set_Active(false);
                      break;
                  }
             }
         }
         QPixmap pis=buffer.enemies[i].pic;
         buffer.enemies[i].enemy_move();
         vector<int> sa=buffer.enemies[i].shape();
         painter.drawPixmap(sa[0],sa[1],sa[2],sa[3],pis);
         //碰撞处理
         if(buffer.enemies[i].get_isActive()==false){
             //已经被碰到了  3帧循环破坏
             buffer.enemies[i].times++;
             buffer.enemies[i].pic_index=(buffer.enemies[i].times-1)/3;
             buffer.enemies[i].pic=QPixmap(e_ds[buffer.enemies[i].pic_index]);
             if(buffer.enemies[i].times==9){
                 buffer.enemies.erase(buffer.enemies.begin()+i);
             }
             else i++;
         }
         else i++;
     }
     //刷新子弹
    for(int i=0;i<buffer.bullets.size();){
        QPixmap pp=buffer.bullets[i].pic;
        buffer.bullets[i].move();

        vector<int> sp=buffer.bullets[i].shape();
        painter.drawPixmap(sp[0],sp[1],sp[2],sp[3],pp);
        if(buffer.bullets[i].get_isActive()==false){
            buffer.bullets.erase(buffer.bullets.begin()+i);
        }
        else i++;
    }

     painter.end();
}


void Widget::fresh(){
    role->hero_move(buffer.Instraction);

    if(buffer.isShot==true)role->shot();
    buffer.isShot=false;
    buffer.Instraction=-1;

    //敌人处理
    while(buffer.enemies.size()<4){
        enemy obj=enemy(enemy_src_path);
        //随机生成出生位置
        int pos=rand();
        obj.set_x_pos(pos%300);
        pos=rand();
        obj.set_y_pos(pos%400);
        obj.set_height(50);
        obj.set_lenth(50);
        obj.set_speed(3);
        obj.set_Active(true);
        buffer.enemies.push_back(obj);

    }
    update();
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    role=new Hero(hero_src_path);
    role->set_x_pos(250);
    role->set_y_pos(700);
    role->set_speed(10);

    srand(unsigned(time(0)));
    ui->setupUi(this);
    real_time_fresh=new QTimer;
    connect(real_time_fresh,SIGNAL(timeout()),this,SLOT(fresh()));
    real_time_fresh->start(30);
}

Widget::~Widget()
{
    delete ui;
}

