#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsTextItem>
#include <QFont>

class GameOver : public QGraphicsTextItem
{
public:
    GameOver(QGraphicsItem *parent = nullptr);
};

#endif // GAMEOVER_H
