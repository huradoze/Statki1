#include "Health.h"
#include <QFont>
#include "game.h"

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 5;


    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 5
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health:4

}

void Health::increase()
{
    health++;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 6
}

int Health::getHealth()
{
    return health;
}
