#ifndef GAME_H
#define GAME_H

#include "PlayerController.h"
#include "PlayerRenderer.h"
#include "Player.h"
#include <QTimer>
#include <QGraphicsView>
#include <QObject>
#include <QMediaPlayer>
#include "AsteroidFactory.h"
#include "CollisionController.h"
#include "Scene.h"
#include "Score.h"
#include "Timer.h"
#include "Life.h"

// the game class where all the rendering takes place
class Game : public QGraphicsView{
    Q_OBJECT
public:
    // constructor
    Game();
    // destructor
    ~Game();
public slots:
    // a function to replay the music
    void replay();
private:
    // media and rendering variables
    QMediaPlayer mediaPlayer;
    QTimer* timer;
    PlayerRenderer* playerRenderer;
    Player* player;
    AsteroidFactory* factory;
    CollisionController * collisionController;
    Score * score;
    Timer * timed;
    Life * life;

};

#endif // GAME_H
