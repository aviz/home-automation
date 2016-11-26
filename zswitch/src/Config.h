//
// Created by Avi Zrachya on 24/11/2016.
//

#ifndef ZSWITCH_CONFIG_H
#define ZSWITCH_CONFIG_H

#include <EEPROM.h>
#include "ConfigListener.h"

typedef struct {

} ConfigValues;

class ConfigClass {
private:
    uint8_t buffer[sizeof(ConfigValues)];
    void onConfigChange();

    ConfigListener *listenerObjects[100];
    int listenerObjectsCount;

public:
    ConfigClass();
    void flush();
    void registerListener(ConfigListener *obj);

    ConfigValues *values;
};

extern ConfigClass Config;

#endif //ZSWITCH_CONFIG_H

