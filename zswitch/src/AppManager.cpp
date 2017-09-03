//
// Created by Avi Zrachya on 19/11/2016.
//

#include "AppManager.h"
#include <Esp.h>

void AppManager::registerObject(Runable *obj) {
    runableObjects[runableObjectsCount] = obj;
    runableObjectsCount++;
}
void AppManager::registerInitalizableObject(Initializeable *obj) {
    initializeableObjects[initializeableObjectsCount] = obj;
    initializeableObjectsCount++;
}

void AppManager::onSetup() {
    Serial.println();
    Serial.println("-----------------------------");
    Serial.println("          App Setup");
    Serial.println("-----------------------------");

    for (int i = 0; i < initializeableObjectsCount; i++) {
        initializeableObjects[i]->onInit();
    }

    for (int i = 0; i < runableObjectsCount; i++) {
        runableObjects[i]->onSetup();
    }
}

void AppManager::onLoop() {
    for (int i = 0; i < runableObjectsCount; i++) {
        runableObjects[i]->onLoop();
    }
}

AppManager::AppManager() {
    runableObjectsCount = 0;
    initializeableObjectsCount = 0;
}
