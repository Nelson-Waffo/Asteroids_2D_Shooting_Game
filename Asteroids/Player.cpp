#include "Player.h"
Player* Player::player = nullptr;
int Player::width = 100;
int Player::height = 95;
QString Player::path = "";

// initialise the collection of bullets
std::list<Bullet*> Player::bullets;

// singleton method: single instance of player
Player* Player::getPlayer(){
    if(player == nullptr){
        Scene* scene = Scene::getScene();

        player = new Player(scene->getWidth()/2 - width/2,
                           scene->getHeight() - height, width, height,
                            ":/assets/assets/player.png");
    }
    return player;
}

// constructor for the player class
Player::Player(int x, int y, int w, int h, QString p) : Actor(x, y){
    width = w;
    height = h;
    path = p;
    // initialise the media player
    media.setMedia(QUrl("qrc:/sounds/sounds/gunshot1.mp3"));
}

// a function used to reset the position X of the player
int& Player::resetX(){
    // place the player in the middle
    Scene* scene = Scene::getScene();
    xCoord = scene->getWidth()/2 - width/2;
}

// destructor
Player::~Player(){
    // delete the remaining bullets bullets
    for(std::list<Bullet*>::iterator it = bullets.begin(); it != bullets.end();
        ++it){
        delete *it;
    }
    // player = nullptr;
}

// a method which enables the player to shoot
Bullet* Player::shoot(){
    static QString path = "";
    static int random = 0;
    random = (rand() % 10) + 1; // from 1 to 10
    path = (random % 2 == 0) ? ":/assets/assets/bullet.png" : ":/assets/assets/bullet3.png" ;
    // create a bullet from the top of the player
    Bullet* bullet = new Bullet(xCoord + width/2 - (7/2), yCoord - (40), 7, 40, path);
    // add the bullet to the list
    bullets.push_back(bullet);
    // play the shooting sound
    if(media.state() == QMediaPlayer::PlayingState){
        // restart the media if it was already playing
        media.setPosition(0);
    }else if(media.state() == QMediaPlayer::StoppedState){
        media.play();
    }
    return bullet;
}

// a method to collect bullets of the player for collision check
std::list<Bullet*>& Player::getBullets(){
    return bullets;
}

// a function which determines the player's image
void Player::setPlayerImage()
{
    int randomNumber = QRandomGenerator::global()->bounded(1, 200);
    if(randomNumber % 5 == 0){
        path = QString(":/assets/assets/fighterjet.png");
        return;
    }
    path = (randomNumber % 2 == 0) ? QString(":/assets/assets/spacecraft.png") : QString(":/assets/assets/player.png");
}

// a function which determines the bullet sound at run time
void Player::setBulletSound()
{
    // randomize the gun sound
    int randomNumber = QRandomGenerator::global()->bounded(1, 200);
    if(randomNumber % 2 == 0){
        media.setMedia(QUrl("qrc:/sounds/sounds/357-magnum.mp3"));
    }else{
        media.setMedia(QUrl("qrc:/sounds/sounds/gunshot1.mp3"));
    }
}
