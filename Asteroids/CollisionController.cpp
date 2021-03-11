#include "CollisionController.h"
#include "Score.h"
#include <QDebug>

// constructor of the collision controller
CollisionController::CollisionController(){
    // set the collision sound
    media.setMedia(QUrl("qrc:/sounds/sounds/explosion.mp3"));
    timer = new QTimer();
    this->connect(timer, SIGNAL(timeout()), this, SLOT(collide()));
    timer->start(1); // shoot every 1 ms
}

// a function to handle collisions and trigger dispersed explosion
void CollisionController::collide(){
    // gather the bullets
    std::list<Bullet*> bullets = Player::getBullets();
    // gather the asteroids on screen
    std::list<Asteroid*> asteroids = AsteroidFactory::getAsteroids();

    // check for collisions between bullets and asteroids
    for(std::list<Asteroid*>::iterator iterA = asteroids.begin();
        iterA != asteroids.end(); ++iterA){
        for(std::list<Bullet*>::iterator iterB = bullets.begin();
            iterB != bullets.end(); ++iterB){
            // check if there is a collision between a bullet and a
            // an asteroid
            // bullet data
            int xa = (*iterA)->getX(); int ya = (*iterA)->getY();
            int wa = (*iterA)->getWidth(); int ha = (*iterA)->getHeight();
            // asteroid data
            int xb = (*iterB)->getX(); int yb = (*iterB)->getY();
            int wb = (*iterB)->getWidth(); int hb = (*iterB)->getHeight();

            // collision detection
            if((*iterA)->getCollided()== false && (*iterB)->getCollided()== false && xa + wa > xb && xb + wb > xa && ya + ha > yb && yb + hb > ya + ha){
                // disable collisions for the colliding elements
                (*iterA)->setCollided(true);
                (*iterB)->setCollided(true);
                // play collision sound
                if(media.state() == QMediaPlayer::PlayingState){
                    // reset the sound
                    media.setPosition(0);
                }else if(media.state() == QMediaPlayer::StoppedState){
                    // play the media
                    media.play();
                }

                // get the concerned asteroid renderer
                AsteroidRenderer* asteroidRenderer = AsteroidFactory::getAsteroidRenderer(*iterA);
                 // remove that asteroid from the scene
                if(asteroidRenderer != 0) Scene::getScene()->removeItem(asteroidRenderer);
                // scatter the residues of the destroyed asteroid
                AsteroidFactory::scatter(*iterA);
                // get the concerned bullet
                BulletRenderer* bulletRenderer = PlayerRenderer::getBulletRenderer(*iterB);
                // remove the bullet fromt he scene
                if(bulletRenderer != 0) Scene::getScene()->removeItem(bulletRenderer);

                // update the score on the screen
                Score::updateScore();
                 break;
            }
        }
    }
}
