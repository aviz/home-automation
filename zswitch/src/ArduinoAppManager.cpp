//
// Created by Avi Zrachya on 19/11/2016.
//

#include "ArduinoAppManager.h"


void ArduinoAppManager::registerObject(Runable *obj) {
    runableObjects[runableObjectsCount] = obj;
    runableObjectsCount++;
}

void ArduinoAppManager::onSetup() {
    for (int i = 0; i < runableObjectsCount; i++) {
        runableObjects[i]->onSetup();
    }
}

void ArduinoAppManager::onLoop() {
    for (int i = 0; i < runableObjectsCount; i++) {
        runableObjects[i]->onLoop();
    }
}

ArduinoAppManager::ArduinoAppManager() {
    runableObjectsCount = 0;
}
