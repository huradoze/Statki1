#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer> // Dodano QTimer
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "enemy.h"


class Game: public QGraphicsView
{
public:

    Game(QWidget *parent =0);

    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;
    QTimer *endofgame;

    void ifGameOver();

private:
    QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;
};

#endif // GAME_H
