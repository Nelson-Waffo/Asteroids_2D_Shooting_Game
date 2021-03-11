#ifndef PLAYERAGENT_H
#define PLAYERAGENT_H

#include "Player.h"
#include "BulletAgent.h"
#include <QString>

// a class responsible for forwarding requests from the UI layer
// to the player
/**
 * @brief The PlayerAgent class
 * delegation: to forward requests to the Player class,
 * PlayerAgent maintains a reference to the Player class
 * and use that delegate to the reference all requests
 * to the Player class.
 * the idea is to decouple UI classes with Logic classes
 */
class PlayerAgent{
public:
    PlayerAgent(int, int, int, QString);
    ~PlayerAgent();
    static Player* getPlayer();
    static QString getPath();
    int getWidth();
    BulletAgent* shoot();
    static std::list<BulletAgent> getBullets();

private:
    Player* player;
};

#endif // PLAYERAGENT_H
