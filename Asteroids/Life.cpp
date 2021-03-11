#include "Life.h"
#include "Timer.h"
#include <QFont>

// initialise the life variable
int Life::life = 50;

// implement the constructor
Life::Life(QGraphicsItem* parent) : QGraphicsTextItem(parent){
    // set the position
    this->setPos(0, 50);
    // set the text
    this->setPlainText("Life: " + QString::number(life));
    // set colour
    this->setDefaultTextColor(Qt::black);
    this->setFont(QFont("Tahoma", 14));

    // periodic update of the life of a player
    timer = new QTimer();
    this->connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(40);
}

// a function to update the player's life
void Life::update(){
    // make sure this stops once timer stops
    if(Timer::getTime() <= 0 || life <= 0){
        timer->stop();
    }
    // update life
    this->setPlainText("Life: " + QString::number(life));

}
