#include "AsteroidFactory.h"
#include <QDebug>

// initialise the asteroid factory
list<Asteroid*> AsteroidFactory::asteroids;
list<AsteroidRenderer*> AsteroidFactory::ast;
list<Asteroid*> AsteroidFactory::tinyAsteroids;
list<AsteroidRenderer*> AsteroidFactory::tinyAst;

// constructor
AsteroidFactory::AsteroidFactory(){
    // create timer
    timer = new QTimer();
    // creation of asteroids
    this->connect(timer, SIGNAL(timeout()), this, SLOT(create()));
    this->connect(timer, SIGNAL(timeout()), this, SLOT(cleanAsteroidsInPlay()));
    timer->start(1200);
}

// a function to determine the image for the asteroid
QString asteroid_image(){
    // int random = rand() % 1000; // between 0 and 99
    int random = QRandomGenerator::global()->bounded(1, 1000);
    QString path = "";
    if(random % 11 == 0) {
        path = ":/assets/assets/asteroid3.png";
    }
    else if(random % 9 == 0) {
        path = ":/assets/assets/asteroid6.png";
    }
    else if(random % 7 == 0) {
        path = ":/assets/assets/asteroid5.png";
    }
    else if(random % 5 == 0) {
        path = ":/assets/assets/asteroid4.png";
    }
    else if(random % 3 == 0) {
        path = ":/assets/assets/asteroid2.png";
    }
    else{
        path = ":/assets/assets/asteroid.png";
    }
    return path;
}

// function used to create asteroids
void AsteroidFactory::create(){
    if(Timer::getTime() > 0){
        // generate a random number for the asteroid x coordinate
        int x = (rand() % 100) + (rand() % 100) * 8; // a random number 0 and 99
        static Scene * scene = Scene::getScene();
        static int scene_width = scene->getWidth();
        // 50 represents the width of the asteroid
        if(x + 50 > scene_width){
            // if yes, bring it back to the screen
            x =  scene_width - 50 - 5; // 5 for a small margin
        }
        // get the random image of the asteroid
        QString path = asteroid_image();
        Asteroid * asteroid = new Asteroid(x, -70, 50, 64, path);
        // add the asteroid to the collection
        asteroids.push_front(asteroid);
        // create an asteroid renderer at a random position and place in the world
        AsteroidRenderer * a = new AsteroidRenderer(asteroid);
        scene->addItem(a);
        ast.push_back(a);
    }
    else{
        // otherwise stop the timer
        timer->stop();
    }
}



// a method to return the collection
list<Asteroid*> AsteroidFactory::getAsteroids(){
    return asteroids;
}

// a function to return a given asteroid renderer
AsteroidRenderer* AsteroidFactory::getAsteroidRenderer(Asteroid* a){
   for(list<AsteroidRenderer*>::iterator iter = ast.begin();
     iter != ast.end(); ++iter){
         if((*iter)->getId() == a->getId()){
             return *iter;
         }
   }
   return 0;
}

// a function responsible for scaterring an asteroid in the world
void AsteroidFactory::scatter(Asteroid* asteroid){
    // scattering factor
    static int scatterFactor = 30;
    // useful data for asteroid crumbs
    int ax = asteroid->getX();
    int ay = asteroid->getY();
    QString path = asteroid->getPath();
    int aw = asteroid->getWidth();
    int ah = asteroid->getHeight();

    // first crumb
    int r1 = (rand()%10 + 2)/2;
    scatterHelper(ax+scatterFactor/r1/*5*/, ay-scatterFactor, aw, ah, path);
    // second crumb
    r1 = (rand()%10 + 2)/2;
    int r2 = (rand()%10 + 2)/2;
    scatterHelper(ax+scatterFactor/r1/*3*/, ay-scatterFactor/r2/*2*/, aw, ah, path);
    // third crumb
    r1 = (rand()%10 + 2)/2;
    scatterHelper(ax+scatterFactor, ay-scatterFactor/r1/*5*/, aw, ah, path);
    // fourth crumb
    r1 = (rand()%10 + 2)/2;
    r2 = (rand()%10 + 2)/2;
    scatterHelper(ax+scatterFactor/r1/*3*/, ay+scatterFactor/r2/*4*/, aw, ah, path);
    // fifth crumb
    r1 = (rand()%10 + 2)/2;
    scatterHelper(ax-scatterFactor/r1/*5*/, ay+scatterFactor, aw, ah, path);
    // 6th crumb
    r1 = (rand()%10 + 2)/2;
    r2 = (rand()%10 + 2)/2;
    scatterHelper(ax-scatterFactor/r1/*4*/, ay+scatterFactor/r2/*3*/, aw, ah, path);
    // 7th crumb
    r2 = (rand()%10 + 2)/2;
    scatterHelper(ax-scatterFactor, ay+scatterFactor/r2/*5*/, aw, ah, path);
    // 8th crumb
    r1 = (rand()%10 + 2)/2;
    r2 = (rand()%10 + 2)/2;
    scatterHelper(ax-scatterFactor/r1/*2*/, ay-scatterFactor/r2/*3*/, aw, ah, path);
    // center crumb: 9th crumb
    scatterHelper(ax, ay, aw, ah, path);
}

// a function to help the scattering to prevent code repetition
void AsteroidFactory::scatterHelper(int scatterX, int scatterY, int astWidth, int astHeight, QString astPath){
    // scale factor
    static double scaleFactor = 0.1;
    Asteroid * asteroid = new Asteroid(scatterX, scatterY, astWidth, astHeight, astPath);
    // the asteroid no longer needs to be collided
    asteroid->setCollided(true);
    // store the tiny asteoroid just for releasing memory when the game ends
    tinyAsteroids.push_front(asteroid);
    AsteroidRenderer * asteroidRenderer = new AsteroidRenderer(asteroid);
    asteroidRenderer->setScale(scaleFactor);
    Scene::getScene()->addItem(asteroidRenderer);
    // store for releasing memory later at the end
    tinyAst.push_back(asteroidRenderer);
}

// a function which returns the list of all large, rendered asteroids
list<AsteroidRenderer *>& AsteroidFactory::getAsteroidRenderers()
{
    return ast;
}

// a function which returns the list of all small, rendered asteoids
list<AsteroidRenderer *> &AsteroidFactory::getTinyAsteroidRenderers()
{
    return tinyAst;
}

// a function for removing asteroids renderers during the game
void AsteroidFactory::cleanAsteroidsInPlay()
{
    // get the scene object
    Scene * scene = Scene::getScene();
    // remove tiny asteroids renderers no longer visible dynamically
    for(list<AsteroidRenderer*>::iterator iter = tinyAst.begin();
        iter != tinyAst.end(); ++iter){
        if((*iter)->getY() >= Scene::getScene()->getHeight() + 10){
            // remove from the scene
            if(scene != nullptr) scene->removeItem(*iter);
            // remove from the collection
            tinyAst.remove(*iter);
            // release memory
            delete *iter;
        }
    }
    // remove large asteroids renderers no longer visible dynamically
    for(list<AsteroidRenderer*>::iterator iter = ast.begin();
        iter != ast.end(); ++iter){
        if((*iter)->getY() >= Scene::getScene()->getHeight() + 10){
            // remove from the scene
            if(scene != nullptr) scene->removeItem(*iter);
            // remove from the collection
            ast.remove(*iter);
            // release memory
            delete *iter;
        }
    }
    // delete large asteroids dynamically
    for(list<Asteroid*>::iterator iter = asteroids.begin();
        iter != asteroids.end(); ++iter){
        if((*iter)->getY() >= Scene::getScene()->getHeight() + 10){
            // remove from the collection
            asteroids.remove(*iter);
            // release memory
            delete *iter;
        }
    }
    // delete tiny asteroids dynamically
    for(list<Asteroid*>::iterator iter = tinyAsteroids.begin();
        iter != tinyAsteroids.end(); ++iter){
        if((*iter)->getY() >= Scene::getScene()->getHeight() + 10){
            // remove from the collection
            tinyAsteroids.remove(*iter);
            // release memory
            delete *iter;
        }
    }
}

// a function to clean up asteroids
void AsteroidFactory::cleanupAsteroids()
{
    // get the scene object
    Scene * scene = Scene::getScene();
    // clean all big asteroids renderer. remove them from the scene
    // remove all asteroid renderers
    for(list<AsteroidRenderer*>::iterator iter = ast.begin();
        iter != ast.end(); ++iter){
        // remove from the scene
        if(scene != nullptr) scene->removeItem(*iter);
        // release memory
        delete *iter;
    }
    for(list<AsteroidRenderer*>::iterator iter = tinyAst.begin();
        iter != tinyAst.end(); ++iter){
        // remove from the scene
        if(scene != nullptr) scene->removeItem(*iter);
        // release memory
        delete *iter;
    }
    // clean up the collection
    ast.clear();
    tinyAst.clear();
    // delete all asteroids
    for(list<Asteroid*>::iterator iter = asteroids.begin();
        iter != asteroids.end(); ++iter){
        delete *iter;
    }
    // delete all tiny asteroids
    for(list<Asteroid*>::iterator iter = tinyAsteroids.begin();
        iter != tinyAsteroids.end(); ++iter){
        delete *iter;
    }
    // clean up the collections
    asteroids.clear();
    tinyAsteroids.clear();
}

// a destructor to destroy asteroids and release resources
AsteroidFactory::~AsteroidFactory(){
    delete timer;
    // clean up everything asteroids
    cleanupAsteroids();
}



/**
    // delete all asteroids
    for(list<Asteroid*>::iterator iter = asteroids.begin();
        iter != asteroids.end(); ++iter){
        delete *iter;
    }
    // remove all asteroid renderers
    for(list<AsteroidRenderer*>::iterator iter = ast.begin();
        iter != ast.end(); ++iter){
        delete *iter;
    }

    // delete all tiny asteroids
    for(list<Asteroid*>::iterator iter = tinyAsteroids.begin();
        iter != tinyAsteroids.end(); ++iter){
        delete *iter;
    }
    // remove all tiny asteroid renderers
    for(list<AsteroidRenderer*>::iterator iter = tinyAst.begin();
        iter != tinyAst.end(); ++iter){
        delete *iter;
    }
*/
