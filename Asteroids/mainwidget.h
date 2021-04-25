#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QDebug>
#include <QWidget>
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
#include <QRandomGenerator>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    // constructor
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    // a function to start the game
    void startGame();
    // a funtion to clean up everything for a clean game restart
    void cleanup();
public slots:
    // a function to restart the game
    void restartGame();
private slots:
    // a function to replay the music
    void replay();
private:
    Ui::MainWidget *ui;
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
    Scene* scene;
};

#endif // MAINWIDGET_H
