#ifndef ACTOR_H
#define ACTOR_H
#include <QString>
#include <QObject>

// a super class for the actors in the game
class Actor : public QObject{
protected:
    int xCoord;
    int yCoord;
    Actor(int x, int y) : xCoord(x), yCoord(y){}
    virtual ~Actor(){}
public:
    void setX(int x){xCoord = x;}
    void setY(int y){yCoord = y;}
    int getX(){return xCoord;}
    int getY(){return yCoord;}
};

#endif // ACTOR_H
