#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include "QTimer"
#include "Timer.h"

// a class responsible for creating bullets
class Bullet: public QObject{
    Q_OBJECT
public:
    // constructor
    Bullet(int x, int y, int w, int h, QString p);
    // destructor
    ~Bullet(){delete timer;}
    // data interface
    void setX(int x){coordX = x;}
    void setY(int y){coordY = y;}
    int getX(){return coordX;}
    int getY(){return coordY;}
    int getWidth(){return width;}
    int getHeight(){return height;}
    QString getPath(){return path;}
    bool getCollided(){return collided;}
    void setCollided(bool c){collided = c;}
    int getId(){return id;}
public slots:
    // method for periodically moving the bullet upwards
    void update();
private:
    // bullet data
    int coordX;
    int coordY;
    int width;
    int height;
    QString path;
    QTimer * timer;
    bool collided;
    // unique id for bullet retrieval
    int id;
    static int counter;
};
#endif // BULLET_H
