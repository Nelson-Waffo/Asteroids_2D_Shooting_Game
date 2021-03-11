#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QTimer>

// a class responsible for showing the life of a player
class Life : public QGraphicsTextItem{
   Q_OBJECT
public:
    Life(QGraphicsItem* parent = nullptr);
    virtual ~Life(){delete timer;}
    // a function to return life
    static int getLife(){return life;}
    static void updateLife(){life -= 1;}
public slots:
    // a function to update the life of a player
    void update();
private:
    static int life;
    QTimer* timer;
};

#endif // LIFE_H
