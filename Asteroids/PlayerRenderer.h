#ifndef PLAYERRENDERER_H
#define PLAYERRENDERER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "Player.h"
#include <QKeyEvent>
#include "BulletRenderer.h"
#include "Timer.h"
#include <list>
#include <QTimer>
#include <QDebug>

// a class responsible for rendering the player on the screen
class PlayerRenderer :public QObject, public QGraphicsPixmapItem{
     Q_OBJECT
public:
    // the constructor takes a player object and renders it
    // the player contains all the information needed to be rendered
    PlayerRenderer(Player* p, QGraphicsItem* parent = 0);
    virtual ~PlayerRenderer();
    // a method used to control the player movement
    void keyPressEvent(QKeyEvent * event)override;
    // a function to return a specific bullet renderer
    static BulletRenderer* getBulletRenderer(Bullet* b);
    static std::list<BulletRenderer*>& getBulletRenderers();
    // a function to remove bullets no longer visible
    void deleteBulletsInPlay();
signals:
    // a signal for restarting the game
    void restart();
private:
    static std::list<BulletRenderer*> bulletRenderers;
    Player* player;
    // a variable to define the sliding speed of the player
    static int slide;
    // timing variable for deleting bullets
    QTimer* timer;

};

#endif // PLAYERRENDERER_H
