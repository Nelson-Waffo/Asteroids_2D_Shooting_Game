#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

// a class to provide a unique scene instance throughout
// the application

class Scene : public QGraphicsScene{
public:
    // singleton methods
    static Scene* getScene(int x, int y, int w, int h);
    static Scene* getScene();
    // scene data interface
    int getHeight(){return height;}
    int getWidth(){return width;}
private:
    // private scene constructor
    Scene(int x, int y, int w, int h);
    // singleton: scene unique instance
    static Scene * scene;
    // coordinates of the scene
    int xCoord;
    int yCoord;
    int width;
    int height;
};

#endif // SCENE_H
