#ifndef TIMER_H
#define TIMER_H

#include <QGraphicsTextItem>
#include <QTimer>
#include "Score.h"

// a class to display the timer of the game
class Timer: public QGraphicsTextItem{
    Q_OBJECT
public:
    // constructor
    Timer(QGraphicsItem* parent = nullptr);
    // destructor
    ~Timer(){delete timer;}
    // a function which returns the time
    static int getTime(){return timing;}
public slots:
    // a function to periodically display the updated time
    void displayTime();
private:
    // timing variable to keep track of the time
    static int timing;
    QTimer* timer;
};

#endif // TIMER_H
