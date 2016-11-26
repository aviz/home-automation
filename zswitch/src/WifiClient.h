//
// Created by Avi Zrachya on 18/11/2016.
//

#ifndef ZSWITCH_WIFICLIENT_H
#define ZSWITCH_WIFICLIENT_H


#include <WString.h>
#include "Runable.h"


class WifiClient : public Runable {
public:
    virtual void onLoop();
    virtual void onSetup();

private:
    char *password;
    char *ssid;
    char wifiHost[32] = {0};


    void generateWifiHost();
    void connectToWifi();
    void setDefaults();
};


#endif //ZSWITCH_WIFICLIENT_H
