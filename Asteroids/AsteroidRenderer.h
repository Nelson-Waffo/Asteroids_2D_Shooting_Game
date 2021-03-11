
#ifndef ASTEROIDRENDERER_H
#define ASTEROIDRENDERER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Asteroid.h"
#include <QTimer>
#include "Timer.h"

// a class responsible for rendering asteroids
class AsteroidRenderer : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    // constructor
    AsteroidRenderer(Asteroid* a, QGraphicsItem* parent=0);
    // destructor
    ~AsteroidRenderer();
    // data interface
    int getX(){return coordX;}
    int getY(){return coordY;}
    int getId(){return id;}
public slots:
    void update();
private:
    // data
    int coordX; int coordY;
    QTimer* timer;
    Asteroid* asteroid;
    // rotation angle
    int angle;
    // unique id for retrieval
    int id;
};

#endif // ASTEROIDRENDERER_H

