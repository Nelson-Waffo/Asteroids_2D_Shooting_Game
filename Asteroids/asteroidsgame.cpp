#include "asteroidsgame.h"
#include "ui_asteroidsgame.h"

// constructor
AsteroidsGame::AsteroidsGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AsteroidsGame)
{
    // create all children of this main window object
    ui->setupUi(this);

    // name of the game
    this->setWindowTitle("Asteroids");

    // set up a connection for starting the game
    this->connect(ui->actionStart, SIGNAL(triggered()), this,
                  SLOT(startGame()));
    // set up a connection to exit the app. qApp is a pointer to
    // to this application
    this->connect(ui->actionExit, SIGNAL(triggered()), qApp,
                  SLOT(quit()));
}

// destructor
AsteroidsGame::~AsteroidsGame()
{
    delete ui;
}

// a function for restarting the game
void AsteroidsGame::startGame()
{
    static bool start = true;
    if(start){
         // start the game
        ui->gameBoard->startGame();
        start = false;
    }
    else if(!start){
        // restart the game
        ui->gameBoard->restartGame();
    }
}
