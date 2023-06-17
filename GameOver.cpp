#include <QGraphicsTextItem>
#include <QFont>
#include "GameOver.h"

GameOver::GameOver(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    setPlainText("Game Over");
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 32));
}
