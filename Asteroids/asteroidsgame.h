#ifndef ASTEROIDSGAME_H
#define ASTEROIDSGAME_H

#include <QMainWindow>
#include "mainwidget.h"

namespace Ui {
class AsteroidsGame;
}

class AsteroidsGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit AsteroidsGame(QWidget *parent = nullptr);
    ~AsteroidsGame();
public slots:
    // function to start the game
    void startGame();

private:
    Ui::AsteroidsGame *ui;
};

#endif // ASTEROIDSGAME_H
