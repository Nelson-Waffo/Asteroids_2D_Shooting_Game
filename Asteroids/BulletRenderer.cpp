#include "BulletRenderer.h"
#include "Life.h"

// constructor
BulletRenderer::BulletRenderer(Bullet* b, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent){
    // initiliase the bullet
    bullet = b;
    // y position
    coordY = bullet->getY();
    height = bullet->getHeight();
    // initialise the id
    id = b->getId();
    timer = new QTimer();
    // create the image
    this->setPixmap(bullet->getPath());
    // position the image
    this->setPos(bullet->getX(), bullet->getY());
    // set up the update
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(40); // timer shoots every 40 ms
}

// a function to update the bullet image position
void BulletRenderer::update(){
    // update as long as the bullet is visible on the screen
    if(Life::getLife() > 0 && Timer::getTime() > 0 && bullet->getY() + bullet->getHeight() >= 0){
        coordY = bullet->getY();
        this->setPos(bullet->getX(), coordY);
    }
    else{
        coordY = bullet->getY();
        // stop the timer
        timer->stop();
    }
}

// implement the destructor
BulletRenderer::~BulletRenderer(){
    delete timer;
}
