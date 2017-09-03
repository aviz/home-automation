//
// Created by Avi Zrachya on 19/11/2016.
//

#ifndef ZSWITCH_ARDUINOAPPMANAGER_H
#define ZSWITCH_ARDUINOAPPMANAGER_H


#include "Runable.h"
#include "Initializeable.h"

class AppManager {
public:
    AppManager();

    void registerObject(Runable *obj);
    void registerInitalizableObject(Initializeable *obj);
    void onSetup();
    void onLoop();

private:
    Runable *runableObjects[100];
    int runableObjectsCount;

    Initializeable *initializeableObjects[100];
    int initializeableObjectsCount;
};


#endif //ZSWITCH_ARDUINOAPPMANAGER_H
