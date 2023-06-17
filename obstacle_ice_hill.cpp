#include "obstacle_ice_hill.h"
#include <QTimer>
#include "bullet.h"
#include "game.h"
#include "bullet.h"
#include "qgraphicsscene.h"
#include "score.h"
#include "game.h"

extern Game*game;

Obstacle_ice_hill::Obstacle_ice_hill()
{

    setPixmap(QPixmap(":/images/gora_lodowa.png"));;

    QTimer *timer = new QTimer();
    int ranx,rany;
    ranx= rand() %1200+100;
    rany = rand() %600 + 100;

    setPos(ranx,rany);
    scale=12;

    connect(timer,SIGNAL(timeout()),this,SLOT(collision()));

    timer->start(50);

}

void Obstacle_ice_hill::attribute()
{
    game->health->decrease();
    game->ifGameOver();
    game->score->decrease();
}


void Obstacle_ice_hill::collision()
{     {
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0 , n = colliding_items.size(); i<n; i++)
        {
            if (typeid(*(colliding_items[i])) == typeid(Player))
            {   if (typeid(*(colliding_items[i])) == typeid(Player))
                    attribute();
                scene()->removeItem(this);
                //delete this;
            }

        }

    }

}
