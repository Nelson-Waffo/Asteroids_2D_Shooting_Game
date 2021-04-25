#include "Score.h"
#include "Life.h"
#include <QFont>

// initialise score
int Score::score = 0;

// constructor
Score::Score(QGraphicsItem* parent): QGraphicsTextItem(parent){
    // intialise the score
    score = 0;
    // set the text
    this->setPlainText(QString("Score: ") + QString::number(score));
    // set the position
    this->setPos(1, 1);
    // set font and colour: bold text
    this->setDefaultTextColor(Qt::black);
    this->setFont(QFont("Times New Roman", 14));
    QFont f = this->font();
    f.setBold(true);
    this->setFont(f);
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
