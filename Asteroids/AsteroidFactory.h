#ifndef ASTEROIDFACTORY_H
#define ASTEROIDFACTORY_H

#include "AsteroidRenderer.h"
#include "Asteroid.h"
#include <QObject>
#include <iostream>
#include <list>
#include <QTimer>
#include "Scene.h"
#include "Timer.h"
#include <QRandomGenerator>
#include <QDebug>

using namespace std;

// a class responsible for creating asteroids in the world
class AsteroidFactory : public QObject{
    Q_OBJECT
public:
    // constructor
    AsteroidFactory();
    // destructor
    ~AsteroidFactory();
    // a function to provide a list of asteroids
    static list<Asteroid*> getAsteroids();
    // a function which returns an asteroid renderer based on its id
    static AsteroidRenderer* getAsteroidRenderer(Asteroid* a);
    // a function responsible for scattering residues of an asteroid in the world
    static void scatter(Asteroid*);
    static void scatterHelper(int, int, int, int, QString);
    static list<AsteroidRenderer*>& getAsteroidRenderers();
    static list<AsteroidRenderer*>& getTinyAsteroidRenderers();
    // clean up all asteroids when the game is over
    void cleanupAsteroids();
public slots:
    void create();
    // clean asteroid renderers for better performance during game
    void cleanAsteroidsInPlay();
private:
    // rendering collections: store rendered data for collision detection
    // collection of large asteroids
    static list<Asteroid*> asteroids;
    // tiny asteroids
    static list<Asteroid*> tinyAsteroids;
    QTimer * timer;
    // collection of large, rendered asteroids
    static list<AsteroidRenderer*> ast;
    // tiny rendered asteroids
    static list<AsteroidRenderer*> tinyAst;
};

#endif // ASTEROIDFACTORY_H
