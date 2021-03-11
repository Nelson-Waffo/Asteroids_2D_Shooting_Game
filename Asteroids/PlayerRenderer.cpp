#include "PlayerRenderer.h"
#include "Scene.h"
#include "Life.h"

// initialise the player slide variable
int PlayerRenderer::slide = 10;

// initialise the collection of bullet renderers
std::list<BulletRenderer*> PlayerRenderer::bulletRenderers;

// implementation of the constructor
PlayerRenderer::PlayerRenderer(Player* p, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent){
    // inialise player
    player = p;
    // render the image of the player
    this->setPixmap(QPixmap(player->getPath()));
    // position the image of the player
    this->setPos(player->getX(), player->getY());
}

// destructor
PlayerRenderer::~PlayerRenderer(){
    // delete bullet renderers
    for(std::list<BulletRenderer*>::iterator iter = bulletRenderers.begin(); iter != bulletRenderers.end(); ++iter){
        delete *iter;
    }
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
