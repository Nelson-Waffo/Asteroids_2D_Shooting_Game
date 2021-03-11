#include "Asteroid.h"
#include "AsteroidFactory.h"
#include "Scene.h"
#include <list>

// initialise the counter variable
int Asteroid::counter = 0;

Asteroid::Asteroid(int x, int y, int w, int h, QString p) : Actor(x,y),
    width(w), height(h), path(p){
    // initialise the collision variable
    collided = false;
    // initialise the id variable
    id = counter;
    counter++;
    // create the timer
    timer = new QTimer();
    // create a signal and slot connection
    this->connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    // start the timer
    timer->start(40); // shoot every 100 seconds
}

// a method to update the asteroid downwards
void Asteroid::update(){
    // increase the y-component for the slow fall
    this->yCoord += 5;
    // stop the timer if time has elapsed
    if(Timer::getTime() <= 0){
        timer->stop();
    }
}
