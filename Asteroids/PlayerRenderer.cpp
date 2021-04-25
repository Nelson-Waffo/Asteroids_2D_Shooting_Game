#include "PlayerRenderer.h"
#include "Scene.h"
#include "Life.h"

// initialise the player slide variable
int PlayerRenderer::slide = 12; // was first 10

// initialise the collection of bullet renderers
std::list<BulletRenderer*> PlayerRenderer::bulletRenderers;

// implementation of the constructor
PlayerRenderer::PlayerRenderer(Player* p, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent){
    // inialise player
    player = p;
    // reset the position of the player
    player->resetX();
    // update the image of the player
    player->setPlayerImage();
    // update the sound of the gun shots
    player->setBulletSound();
    // render the image of the player
    this->setPixmap(QPixmap(player->getPath()));
    // position the image of the player
    this->setPos(player->getX(), player->getY());
    // create a connection to clear bullets out of the screen
    timer = new QTimer(this);
    this->connect(timer, &QTimer::timeout, this, &PlayerRenderer::deleteBulletsInPlay);
    timer->start(1000); // clean up every 1 second
}

// destructor
PlayerRenderer::~PlayerRenderer(){
    // get the scene
    Scene * scene = Scene::getScene();
    // delete bullet renderers
    for(std::list<BulletRenderer*>::iterator iter = bulletRenderers.begin(); iter != bulletRenderers.end(); ++iter){
        // remove the bullets from the scene
        if(scene != nullptr) scene->removeItem(*iter);
        delete *iter;
    }
    // clear the collection completely
    bulletRenderers.clear();
}



// a method used to control player movements
void PlayerRenderer::keyPressEvent(QKeyEvent * event){
    // key pressed
    int key = event->key();

    if(Life::getLife() > 0 && Timer::getTime() > 0 && (key == Qt::Key_A || key == Qt::Key_Left)){
       if(player->getX() >= slide - player->getWidth()/3){
           player->setX(player->getX() - slide);
           this->setPos(player->getX(), player->getY());
       }
    }

    else if(Life::getLife() > 0 && Timer::getTime() > 0 && (key == Qt::Key_D || key == Qt::Key_Right)){
        // x + w + slide <= scene width + 1/3w
        if(player->getX() + slide <= Scene::getScene()->getWidth() - 0.67*player->getWidth()){
            player->setX(player->getX() + slide);
            this->setPos(player->getX(), player->getY());
        }
    }

    // render bullets. the player shoots by pressing S or Space
    else if(Timer::getTime() > 0 && (key == Qt::Key_S || key == Qt::Key_Space)){
        // create the bullet
        Bullet* bullet = player->shoot();
        // render the bullet using the bullet renderer
        BulletRenderer* bulletRenderer = new BulletRenderer(bullet);
        // add bullet to the scene
        Scene::getScene()->addItem(bulletRenderer);
        // add the bullet renderer to a collection so as to delete all later
        bulletRenderers.push_back(bulletRenderer);
    }
    else if(key == Qt::Key_Escape){
        // make the game restart
        emit restart();
    }
}

// a function to return a specific bullet renderer
BulletRenderer* PlayerRenderer::getBulletRenderer(Bullet* b){
    // search for the bullet renderer and return it
    for(std::list<BulletRenderer*>::iterator iter = bulletRenderers.begin();
        iter != bulletRenderers.end(); ++iter){
        if((*iter)->getId() == b->getId()){
            return *iter;
        }
    }
    return 0;
}

// a function which returns bullet renderers
std::list<BulletRenderer *> &PlayerRenderer::getBulletRenderers()
{
    return bulletRenderers;
}

// a function to dynamically remove bullets no longer viisble in the screen
void PlayerRenderer::deleteBulletsInPlay()
{
    // get the scene object
    Scene * scene = Scene::getScene();
    // remove bullet renderers during game play
    for(std::list<BulletRenderer*>::iterator iter = bulletRenderers.begin();
        iter != bulletRenderers.end(); ++iter){
        // remove renderer from the scene
        if((*iter)->getY() < -(*iter)->getHeight()){
            // remove from scene
            if(scene != nullptr) scene->removeItem(*iter);
            // remove from collection
            bulletRenderers.remove(*iter);
            // release memory
            delete *iter;
         }
    }
    // remove bullets during game play
    for(std::list<Bullet*>::iterator iter = player->getBullets().begin();
        iter != player->getBullets().end(); ++iter){
        // remove renderer from the scene
        if((*iter)->getY() < -(*iter)->getHeight()){
            // remove from collection
            player->getBullets().remove(*iter);
            // release memory
            delete *iter;
        }
    }
}
