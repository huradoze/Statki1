#include "obstacle_fale.h"
#include <QTimer>
#include "bullet.h"
#include "game.h"
#include "bullet.h"
#include "qgraphicsscene.h"
#include "score.h"

extern Game*game;

Obstacle_fale::Obstacle_fale()
{
    setPixmap(QPixmap(":/images/fale.png"));;

    QTimer *timer = new QTimer();
    int ranx,rany;
    ranx= rand() %1200+100;
    rany = rand() %600 + 100;

    setPos(ranx,rany);
    scale=10;

    connect(timer,SIGNAL(timeout()),this,SLOT(collision()));

    timer->start(50);

}

void Obstacle_fale::attribute()
{
    game->health->increase();
    game->score->increase();
}


void Obstacle_fale::collision()
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
