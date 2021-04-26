#include "mainwindow.h"
#include <QApplication>
#include "mainwidget.h"
#include "asteroidsgame.h"

/**
 * This is an asteroid game. a player piloting a plane
 * this to destroy asteroids falling from the sky so as
 * to make sure they do not hit the ground to cause damage.
 *
 * The player must destroy 100 asteroids in 180 seconds to win the game.
 *
 * @brief qMain
 * @param argc
 * @param argv
 * @return
 */

// main function to start the game execution
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create the instance of the main window for the game
    AsteroidsGame game;
    // display the game window
    game.show();
    // run the application
    a.exec();
    return 0;
}

// restarting the game
// simply make sure that the scene is empty
// also release all resources in the clean-up method
// also clear all the collections
// the scene does not need to be deleted and created again
// it just needs to be emptied for every restart
