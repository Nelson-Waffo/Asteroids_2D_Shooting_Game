#include "AsteroidRenderer.h"
#include "Scene.h"
#include "Life.h"

// constructor for the asteroid renderer
AsteroidRenderer::AsteroidRenderer(Asteroid* a, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent){
    // initialise asteroid and angle
    asteroid = a;
    // intialise the rotation angle
    angle = 45;
    // initialise the id
    id = a->getId();
    // create the enemy
    this->setPixmap(asteroid->getPath());
    // origin of the rotation at the center of the image
    this->setTransformOriginPoint(asteroid->getWidth()/2, asteroid->getHeight()/2);
    // rotate image by 45 degrees
    this->setRotation(angle);
    // set the position of the enemy
    coordX = asteroid->getX(); coordY = asteroid->getY();
    this->setPos(coordX, coordY);

    // organise the periodic execution of the update method
    timer = new QTimer();
    this->connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    // start the timer to shoot every 40 ms
    timer->start(40);
}

// a function to update the position of the asteroid
void AsteroidRenderer::update(){
    // update the position of the asteroid when possible
    if(Life::getLife() > 0 && Timer::getTime() > 0 && asteroid->getY() < Scene::getScene()->getHeight() + 10){
            angle += 5;
            this->setRotation(angle);
            coordX = asteroid->getX(); coordY = asteroid->getY();
            this->setPos(coordX, coordY);
    }
    else{
        // update the y position
        coordY = asteroid->getY();
        // update player's life if the asteroid didnt get collided
        if(asteroid->getCollided() == false){
             Life::updateLife();
        }
        // stop the timer because it does not need to move anymore
        timer->stop();
    }
}

// destructor
AsteroidRenderer::~AsteroidRenderer(){
    delete timer;
}

