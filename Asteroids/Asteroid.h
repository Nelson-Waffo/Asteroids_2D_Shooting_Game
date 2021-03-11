#ifndef ASTEROID_H
#define ASTEROID_H
#include <QString>
#include "Actor.h"
#include <QTimer>
#include "Timer.h"

// a class which represents an opponent
class Asteroid : public Actor{
    Q_OBJECT
private:
    // asteroid data
    int width;
    int height;
    QString path;
    QTimer* timer;
    bool collided;
    int id;
    // a variable for unique id
    static int counter;
public slots:
    // a method to update asteroids so they move downwards
    void update();
public:
    // constructor
    Asteroid(int x, int y, int w, int h, QString p);
    // destructor
    virtual ~Asteroid(){delete timer;}
    // data interface
    QString getPath(){return path;}
    int getWidth(){return width;}
    int getHeight(){return height;}
    bool getCollided(){return collided;}
    void setCollided(bool c){collided = c;}
    int getId(){return id;}
};

#endif // ASTEROID_H
