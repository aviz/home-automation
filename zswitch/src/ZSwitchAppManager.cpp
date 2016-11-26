//
// Created by Avi Zrachya on 19/11/2016.
//

#include "ZSwitchAppManager.h"
#include "WifiClient.h"
#include "WifiAP.h"

ZSwitchAppManager::ZSwitchAppManager() : ArduinoAppManager() {
    WifiClient *wifiClient = new WifiClient();
    registerObject(wifiClient);

    WifiAP *wifiAP = new WifiAP();
    registerObject(wifiAP);

}
