//
// Created by Avi Zrachya on 18/11/2016.
//

#include <ESP8266mDNS.h>
#include "ZSwitchAppManager.h"

ZSwitchAppManager *app;

void setup() {
    Serial.begin(115200);

    app = new ZSwitchAppManager();
    app->onSetup();
}

void loop() {
    app->onLoop();
}