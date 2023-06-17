#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"
#include "qgraphicsscene.h"

extern Game * game;

Enemy::Enemy(){
    QTimer *timer = new QTimer();
    int ranx,rany,ran;
    ranx = rand() %200+200;
    rany = rand() %200+200;
    ran = rand() %4;
    setPixmap(QPixmap(":/images/enemy.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);
    if(ran==0)
    {
        setPos(game->player->pos().x()+ranx,game->player->pos().y()+rany);
    }
    if(ran==1)
    {
        setPos(game->player->pos().x()-ranx,game->player->pos().y()+rany);
    }
    if(ran==2)
    {
        setPos(game->player->pos().x()+ranx,game->player->pos().y()-rany);
    }
    if(ran==3)
    {
        setPos(game->player->pos().x()-ranx,game->player->pos().y()-rany);
    }


    connect(timer,&QTimer::timeout,[&, this](){

        move_to(); });


    timer->start(50);

}

void Enemy::collision()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0 , n = colliding_items.size(); i<n ; i++)
    {
        if(typeid(*(colliding_items[i]))==typeid(Player))
        {
            game -> health -> decrease();
            game->ifGameOver();
            scene()->removeItem(this);

        }
    }
}

void Enemy::move_to()
{
    if(game->player->pos().x()>pos().x())
        setPos(pos().x()+2,pos().y());
    else if(game->player->pos().x()<pos().x())
        setPos(pos().x()-2,pos().y());
    if(game->player->pos().y()>pos().y())
        setPos(pos().x(),pos().y()+2);
    else if(game->player->pos().y()<pos().y())
        setPos(pos().x(),pos().y()-2);
    collision();

}


