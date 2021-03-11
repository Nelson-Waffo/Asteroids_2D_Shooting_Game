#ifndef PLAYERRENDERER_H
#define PLAYERRENDERER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "Player.h"
#include <QKeyEvent>
#include "BulletRenderer.h"
#include "Timer.h"
#include <list>

// a class responsible for rendering the player on the screen
class PlayerRenderer :public QObject, public QGraphicsPixmapItem{
     Q_OBJECT
public:
    // the constructor takes a player object and renders it
    // the player contains all the information needed to be rendered
    PlayerRenderer(Player* p, QGraphicsItem* parent = 0);
    virtual ~PlayerRenderer();
    // a method used to control the player movement
    void keyPressEvent(QKeyEvent * event);
    // a function to return a specific bullet renderer
    static BulletRenderer* getBulletRenderer(Bullet* b);
private:
    static std::list<BulletRenderer*> bulletRenderers;
    Player* player;
    // a variable to define the sliding speed of the player
    static int slide;
};

#endif // PLAYERRENDERER_H
