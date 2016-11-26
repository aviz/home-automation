//
// Created by Avi Zrachya on 19/11/2016.
//

#ifndef ZSWITCH_ARDUINOAPPMANAGER_H
#define ZSWITCH_ARDUINOAPPMANAGER_H


#include "Runable.h"

class ArduinoAppManager {
public:
    ArduinoAppManager();

    void registerObject(Runable *obj);
    void onSetup();
    void onLoop();

private:
    Runable *runableObjects[100];
    int runableObjectsCount;
};


#endif //ZSWITCH_ARDUINOAPPMANAGER_H
