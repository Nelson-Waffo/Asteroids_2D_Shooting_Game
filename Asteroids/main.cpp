#include "mainwindow.h"
#include <QApplication>
#include "Game.h"

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

    // create and display the game
    Game * game = new Game();
    game->show();

    // run the application
    a.exec();

    // release game resources after the end of the game
    delete game;

    return 0;
}
