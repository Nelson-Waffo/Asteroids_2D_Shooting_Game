#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QTimer>
#include "Timer.h"

// a class responsible for displaying the score to the user
class Score: public QGraphicsTextItem{
    Q_OBJECT
public:
    // constructor
    Score(QGraphicsItem * parent = nullptr);
    // destructor
    ~Score(){delete timer;}
    // functions to set and return the score
    static void updateScore(){score += 1;}
    static int getScore(){return score;}
public slots:
    // a function used to display the updated score
    void displayScore();
private:
    // a variable to keep track of the score
    static int score;
    // timer variable for periodic execution
    QTimer* timer;
};

#endif // SCORE_H
