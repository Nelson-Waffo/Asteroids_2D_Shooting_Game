#include "Bullet.h"
#include <list>
#include <Player.h>

// initialise the counter variable
int Bullet::counter = 0;

// constructor for the bullet class
Bullet::Bullet(int x, int y, int w, int h, QString p){
    // initialise data variables
    coordX = x;
    coordY = y;
    width = w;
    height = h;
    path = p;
    collided = false;
    id = counter;
    counter++;
    // signal and slots
    timer = new QTimer();
    // periodic execution of the update() method every 40 ms
    this->connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    // start the timer and time out every 40 ms
    timer->start(40);
}

// update function to move the bullet upwards
void Bullet::update(){
    // stop the timer if necessary
    if(Timer::getTime() <= 0 || collided){
        timer->stop();
        return;
    }
    // the bullet moves up after being created.
    if(this->coordY + this->height >= 0){
        this->coordY -= 5;
    }
    else{
        // the bullet is no longer available for collision
        this->collided = true;
    }
}
