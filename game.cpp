#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QBrush>
#include <QImage>
#include "qgraphicsscene.h"
#include <motionless.h>
#include "score.h"
#include <QGraphicsScene>
#include <QApplication>
#include "Player.h"

    Game::Game(QWidget *parent) {
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 900, 900);
    setBackgroundBrush(QBrush(QImage(":/images/nakladka.png")));

    // make the newly created scene the scene to visualize
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900, 900);

    // create the player
    player = new Player();
    player->setPos(300, 300);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    // spawn enemies
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(create()));
    timer->start(5000);

    // spawn obstacles
    timer1 = new QTimer();
    QObject::connect(timer1, SIGNAL(timeout()), player, SLOT(create_obstacle_ice_hill()));
    timer1->start(5000);

    timer2 = new QTimer();
    QObject::connect(timer2, SIGNAL(timeout()), player, SLOT(create_obstacle_fale()));
    timer2->start(3000);

    show();
}

    void Game::ifGameOver()
    {
    if (health->getHealth() <= 3)
    {
        scene = new QGraphicsScene();
        scene->setSceneRect(0, 0, 900, 900);
        setScene(scene);
        setBackgroundBrush(QBrush(QImage(":/images/game_over.png")));
        timer->stop();
        timer1->stop();
        timer2->stop();

        // Dodaj tekst z wynikiem
        QGraphicsTextItem* scoreText = new QGraphicsTextItem();
        scoreText->setPlainText("Wynik: " + QString::number(score->getScore()));
        QFont scoreFont("Helvetica", 24);
        scoreText->setFont(scoreFont);
        int xPos = scene->width() / 2 - scoreText->boundingRect().width() / 2;
        int yPos = 100;
        scoreText->setPos(xPos, yPos);
        scene->addItem(scoreText);

        QTimer::singleShot(7000, QApplication::instance(), &QApplication::quit);
    }
    }



