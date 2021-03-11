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
    timer->start(1200);
}

// a function to determine the image for the asteroid
QString asteroid_image(){
    int random = rand() % 1000; // between 0 and 99
    QString path = "";
    if(random % 9 == 0) {
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
        int x = (rand() % 100) * 8; // a random number 0 and 99
        static Scene * scene = Scene::getScene();
        static int scene_width = scene->getWidth();
        // 50 represents the width of the asteroid
        if(x + 50 > scene_width){
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

// a destructor to destroy asteroids and release resources
AsteroidFactory::~AsteroidFactory(){
    delete timer;
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
}
