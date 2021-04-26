#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include "Actor.h"
#include "Bullet.h"
#include <list>
#include <QMediaPlayer>
#include "Scene.h"
#include <QRandomGenerator>

// a class responsible for managing the only instance of the player
class Player : public Actor{
private:
    // constructor
    Player(int, int, int, int, QString);
    // player data
    static int width;
    static int height;
    static Player* player;
    static QString path;
    static std::list<Bullet*> bullets;
    QMediaPlayer media;
public:
    // destructor
    virtual ~Player();
    // data interface
    static Player* getPlayer();
    static QString getPath(){return path;}
    void resetX();
    int getWidth(){return width;}
    Bullet* shoot();
    // a collection of shot bullets
    static std::list<Bullet*>& getBullets();
    // a function which determine the player image
    void setPlayerImage();
    // a function which determines the bullet sound at run time
    void setBulletSound();
};

#endif // PLAYER_H
