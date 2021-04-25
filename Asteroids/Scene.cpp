#include "Scene.h"

// initialise the scene object
Scene * Scene::scene = nullptr;

// constructor for the scene
Scene::Scene(int x, int y, int w, int h) : QGraphicsScene(x,y,w,h){
    xCoord = x;
    yCoord = y;
    width = w;
    height = h;
}

// singleton methods
Scene* Scene::getScene(int x, int y, int w, int h){
    if(scene == nullptr){
        scene = new Scene(x,y,w,h);
    }
    return scene;
}

// second singleton method
Scene* Scene::getScene(){
    return scene;
}

// a function to reset the scene
void Scene::resetScene()
{
    delete scene;
    scene = nullptr;
}
