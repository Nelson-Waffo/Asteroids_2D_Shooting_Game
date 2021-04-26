#include "mainwidget.h"
#include "ui_mainwidget.h"

// constructor to merely set up what is in the .UI file
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    // create all the elements in the .ui file and set them up
    ui->setupUi(this);
    // set the title of the window
    this->setWindowTitle("Asteroids");
}

// the destructor
MainWidget::~MainWidget()
{
    delete ui;
    // release resources
    delete timer;
    delete playerRenderer;
    delete player;
    // clean up all asteroids and free memory
    delete factory;
    delete collisionController;
    delete timed;
    delete score;
     delete life;
}

// a function to start the game
void MainWidget::startGame()
{
    // create the scene object
    scene = Scene::getScene(0,0, 800, 600);

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
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/assets/assets/sky.png")));
    // set the scene for the game
    ui->graphicsView->setScene(scene);

    // play the background music
    QString path = "qrc:/sounds/sounds/background.mp3";
    // randomize the background music
    int number = QRandomGenerator::global()->bounded(1, 100); // between 1 and 100
    if(number % 5 == 0 || number % 3 == 0) path = "qrc:/sounds/sounds/background2.mp3";
    mediaPlayer.setMedia(QUrl(path));
    mediaPlayer.play();
    // make the music play continuously
    timer = new QTimer();
    this->connect(timer, SIGNAL(timeout()), this, SLOT(replay()));
    timer->start(500); // timer shoots every second
    // enable the restart of the game
    this->connect(playerRenderer, SIGNAL(restart()), this, SLOT(restartGame()));
    // display the widget: the game
    this->show();
}

// a function to replay the background music
void MainWidget::replay(){
    // replay the background music if necessary
    if(mediaPlayer.state() == QMediaPlayer::StoppedState){
        mediaPlayer.play();
    }
    static bool night = false;
    // change the background to a darker sky when time is almost up
    if(!night && Timer::getTime() <= 60){
        night = true;
        // set a background image for the game
        ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/assets/assets/nightsky.png")));
    }
}


// a function to restart the game
void MainWidget::restartGame()
{
    // clean up the game
    cleanup();
    // start the game anew
    startGame();
}

// a function to release resources to enable a clean restart
// of the game
void MainWidget::cleanup()
{
    // clean the scene
    // remove the player
    if(scene != nullptr){
        scene->removeItem(playerRenderer);

        // remove the asteroids
        // factory->cleanupAsteroids();
        delete factory;

        // remove the score
        scene->removeItem(score);

        // remove time recorder
        scene->removeItem(timed);

        // remove life displayer
        scene->removeItem(life);
    }
    // release resources
    delete score;
    delete timed;
    delete life;
    delete timer;
    delete playerRenderer;
    delete collisionController;
}


