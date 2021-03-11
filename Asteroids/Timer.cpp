#include "Timer.h"
#include "Scene.h"
#include "Life.h"

// initialise the timing variable
int Timer::timing = 180; // 3 minutes

// constructor to display the text
Timer::Timer(QGraphicsItem* parent): QGraphicsTextItem(parent){
    // set the position
    this->setPos(Scene::getScene()->getWidth() - 110, 1);
    // set the timer text
    this->setPlainText(QString("Time: ") + QString::number(timing));
    // set the colour and font
    this->setDefaultTextColor(Qt::red);
    this->setFont(QFont("Tahoma", 14));

    // set up the update for the game timer
    timer = new QTimer();
    this->connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));
    timer->start(1000); // shoot every second
}

// update the time on the screen
void Timer::displayTime(){
    // set a winning condition
    static int winning_condition = 110;
    // update time when possible
    if(timing > 0 && Life::getLife() > 0){
        timing -= 1;
        this->setPlainText(QString("Time: ") + QString::number(timing));
    }
    else{
        // display final text
        this->setDefaultTextColor(Qt::black);
        this->setPos(Scene::getScene()->getWidth()/2 - 100, Scene::getScene()->getHeight()/2);
        if(Score::getScore() >= winning_condition){
            this->setPlainText( "You succeeded. Congratulations!!");
        }
        else{
            this->setPlainText("Sorry. You failed. Sorry!");
        }
        // stop the timer. time is up
        timer->stop();
    }
}
