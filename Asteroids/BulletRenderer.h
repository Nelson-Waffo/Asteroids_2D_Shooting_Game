#ifndef BULLETRENDERER_H
#define BULLETRENDERER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "Bullet.h"
#include "Timer.h"
#include <QTimer>

// class used to render bullets on the screen
class BulletRenderer : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BulletRenderer(Bullet* b, QGraphicsItem* parent = 0);
    // destructor
    ~BulletRenderer();
    int getId(){return id;}
public slots:
    void update();
private:
    QTimer* timer;
    Bullet* bullet;
    // unique id for retrieval
    int id;
};

#endif // BULLETRENDERER_H
