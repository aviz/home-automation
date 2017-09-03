//
// Created by Avi Zrachya on 19/11/2016.
//

#include "WifiAP.h"
#include <ESP8266WiFi.h>
#include "Config.h"

WifiAP::WifiAP() {

}

void WifiAP::setDefaults() {
    generateWifiHost();
    if (Config.values.ap_ssid.length() > 0) {
        ssid = Config.values.ap_ssid;
    }
    ssid = wifiHost;
    password = Config.values.ap_password;
}

void WifiAP::onLoop() {

}

void WifiAP::onSetup() {
    setDefaults();
    WiFi.softAP(ssid.c_str(), password.c_str());
    IPAddress myIP = WiFi.softAPIP();

    Serial.printf("AP: [%s] IP: [%s]\n", ssid.c_str(), myIP.toString().c_str());
}

void WifiAP::generateWifiHost() {
    uint8_t mac[6];

    WiFi.macAddress((uint8_t *) &mac);
    sprintf(wifiHost, "ZSwitch-%02X.%02X.%02X.%02X.%02X.%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}