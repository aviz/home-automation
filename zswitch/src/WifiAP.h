//
// Created by Avi Zrachya on 19/11/2016.
//

#ifndef ZSWITCH_WIFIAP_H
#define ZSWITCH_WIFIAP_H


#include <string>
#include "Runable.h"


class WifiAP : public Runable {
public:
    virtual void onLoop();

    WifiAP();

    virtual void onSetup();
    void setDefaults();

private:
    std::string ssid;
    std::string password;
    char wifiHost[32] = {0};

    void generateWifiHost();
};


#endif //ZSWITCH_WIFIAP_H
