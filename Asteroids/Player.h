#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include "Actor.h"
#include "Bullet.h"
#include <list>
#include <QMediaPlayer>

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
    int getWidth(){return width;}
    Bullet* shoot();
    static std::list<Bullet*> getBullets();

};

#endif // PLAYER_H
