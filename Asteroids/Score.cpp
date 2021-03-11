#include "Score.h"
#include "Life.h"
#include <QFont>

// initialise score
int Score::score = 0;

// constructor
Score::Score(QGraphicsItem* parent): QGraphicsTextItem(parent){
    // set the text
    this->setPlainText(QString("Score: ") + QString::number(score));
    // set the position
    this->setPos(0, 0);
    // set font and colour
    this->setDefaultTextColor(Qt::black);
    this->setFont(QFont("Tahoma", 14));
    // set up the periodic execution of the function to show the score
    timer = new QTimer();
    this->connect(timer, SIGNAL(timeout()), this, SLOT(displayScore()));
    timer->start(40); // every 40 ms, execute displayScore()
}

// a function used to display the updated score
void Score::displayScore(){
    // show the score
    this->setPlainText(QString("Score: ") + QString::number(score));
    // stop the timer when time is up
    if(Life::getLife() <= 0 || Timer::getTime() <= 0) timer->stop();
}
