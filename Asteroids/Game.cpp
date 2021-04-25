#include "Game.h"
#include <time.h>

// a constructor for the game class
Game::Game(){
    // create the scene object
    Scene* scene = Scene::getScene(0,0, 800, 600);

    // add the player to the scene and let it gain focus
    player = Player::getPlayer();
    playerRenderer = new PlayerRenderer(player);
    playerRenderer->setFlag(QGraphicsItem::ItemIsFocusable);
    playerRenderer->setFocus();
    scene->addItem(playerRenderer);

    // create enemies: the asteroid factory uses the asteroid renderer
    // which uses the asteroid
    factory = new AsteroidFactory();

    // enable collision detection
    collisionController = new CollisionController;

    // display the score
    score = new Score();
    // add the score to the scene
    scene->addItem(score);

    // display time
    timed = new Timer();
    scene->addItem(timed);

    // display player's life
    life = new Life();
    scene->addItem(life);

    // set a background image for the game
    this->setBackgroundBrush(QBrush(QImage(":/assets/assets/sky.png")));
    // set the scene for the game
    this->setScene(scene);

    // play the background music
    QString path = "qrc:/sounds/sounds/background.mp3";

    int number = QRandomGenerator::global()->bounded(1, 100); // between 1 and 100
    if(number % 5 == 0 || number % 3 == 0) path = "qrc:/sounds/sounds/background2.mp3";
    mediaPlayer.setMedia(QUrl(path));
    mediaPlayer.play();
    // make the music play continuously
    timer = new QTimer();
    this->connect(timer, SIGNAL(timeout()), this, SLOT(replay()));
    timer->start(500); // timer shoots every second
}

// a function to replay the background music
void Game::replay(){
    // replay the background music if necessary
    if(mediaPlayer.state() == QMediaPlayer::StoppedState){
        mediaPlayer.play();
    }
    static bool night = false;
    // change the background to a darker sky when time is almost up
    if(!night && Timer::getTime() <= 60){
        night = true;
        // set a background image for the game
        this->setBackgroundBrush(QBrush(QImage(":/assets/assets/nightsky.png")));
    }
}

// destructor for the game class
Game::~Game(){
   // release resources
   delete timer;
   delete playerRenderer;
   delete player;
   delete factory;
   delete collisionController;
   delete timed;
   delete score;
    delete life;
}

// a function used to start the game
void Game::startGame()
{

}

// a function used to restart the game
void Game::restartGame()
{

}
