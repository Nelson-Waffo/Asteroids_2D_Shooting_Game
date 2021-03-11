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
public slots:
    void create();
private:
    // rendering collections: store rendered data for collision detection
    static list<Asteroid*> asteroids;
    static list<Asteroid*> tinyAsteroids;
    QTimer * timer;
    static list<AsteroidRenderer*> ast;
    static list<AsteroidRenderer*> tinyAst;
};

#endif // ASTEROIDFACTORY_H
