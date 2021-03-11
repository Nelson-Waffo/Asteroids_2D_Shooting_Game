#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <QKeyEvent>
#include "Player.h"
// a class to control the player
class PlayerController{
public:
   void keyPressEvent(QKeyEvent * event);
private:
   // static Player * player;
};

#endif // PLAYERCONTROLLER_H
