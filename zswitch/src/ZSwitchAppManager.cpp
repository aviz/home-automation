//
// Created by Avi Zrachya on 19/11/2016.
//

#include "ZSwitchAppManager.h"
#include "WifiClient.h"
#include "WifiAP.h"
#include "WebServer.h"
#include "Config.h"

ZSwitchAppManager::ZSwitchAppManager() : AppManager() {
    registerInitalizableObject(&Config);

    registerObject(&WebServer::getInstance());
    registerObject(new WifiClient());
    registerObject(new WifiAP());

}
