//
// Created by Avi Zrachya on 18/11/2016.
//

#include "WifiClient.h"
#include <ESP8266WiFi.h>


void WifiClient::setDefaults() {
    generateWifiHost();
    ssid = strdup("zwifi_2.4");
    password = strdup("a1234567890");
}

void WifiClient::onSetup() {
    setDefaults();
    connectToWifi();
}


void WifiClient::onLoop() {
    if (WiFi.status() != WL_CONNECTED) {
        connectToWifi();
    }
}

void WifiClient::generateWifiHost() {
    uint8_t mac[6];

    WiFi.macAddress((uint8_t *) &mac);
    sprintf(wifiHost, "ZSwitch_%02X.%02X.%02X.%02X.%02X.%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

void WifiClient::connectToWifi() {
    WiFi.hostname(wifiHost);
    WiFi.begin(ssid, password);
    Serial.printf("Connecting host: [%s] ssid: [%s] password: [%s]", wifiHost, ssid, password);


    for (int retries = 0; WiFi.status() != WL_CONNECTED && retries < 10; retries++) {
        delay(250);
        Serial.print(".");
    }
    Serial.println('.');

    if (WiFi.status() == WL_CONNECTED) {
        Serial.printf("Connected to %s\n", ssid);
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }
}