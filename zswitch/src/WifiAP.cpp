//
// Created by Avi Zrachya on 19/11/2016.
//

#include "WifiAP.h"
#include <ESP8266WiFi.h>

WifiAP::WifiAP() {

}

void WifiAP::setDefaults() {
    generateWifiHost();
    ssid = wifiHost;
    password = strdup("adminadmin");
}

void WifiAP::onLoop() {

}

void WifiAP::onSetup() {
    setDefaults();
    WiFi.softAP(ssid, password);
    IPAddress myIP = WiFi.softAPIP();

    Serial.printf("AP: [%s] IP: [%s]\n", ssid, myIP.toString().c_str());
}

void WifiAP::generateWifiHost() {
    uint8_t mac[6];

    WiFi.macAddress((uint8_t *) &mac);
    sprintf(wifiHost, "ZSwitch-%02X.%02X.%02X.%02X.%02X.%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}