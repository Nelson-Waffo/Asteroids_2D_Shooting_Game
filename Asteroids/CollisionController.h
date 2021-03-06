#ifndef COLLISIONCONTROLLER_H
#define COLLISIONCONTROLLER_H

#include "PlayerRenderer.h"
#include "AsteroidFactory.h"
#include <QTimer>
#include <QObject>
#include <list>
#include <QMediaPlayer>
#include "BulletRenderer.h"
#include "Scene.h"
#include "Score.h"
#include <QDebug>
#include <QRandomGenerator>

// explosion sounds
struct Meta{
    static const QString explosion1;
    static const QString explosion2;
};

// a class responsible for checking collisions between
// bullets and asteroids
class CollisionController: public QObject{
    Q_OBJECT
public:
    // constructor
    CollisionController();
    // destructor
    ~CollisionController(){delete timer;}
public slots:
    // collision function enabled by the timer
    void collide();
private:
    // timer to enable periodic execution of the collide method
    QTimer* timer;
    QMediaPlayer media;
};

#endif // COLLISIONCONTROLLER_H
