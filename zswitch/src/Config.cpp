//
// Created by Avi Zrachya on 24/11/2016.
//

#include "Config.h"


ConfigClass::ConfigClass() {
    for( int i = 0; i < sizeof(ConfigValues); ++i ) {
        buffer[i] = EEPROM.read(i);
    }
    values = (ConfigValues *) buffer;

}



//write the buffer into the eeprom
//be careful writting too often to the eeprom. It only has 100,000 writes
void ConfigClass::flush() {
    for( int i = 0; i < sizeof(ConfigValues); ++i ) {
        EEPROM.write(i, buffer[i]);
    }
}


void ConfigClass::registerListener(ConfigListener *obj) {
    listenerObjects[listenerObjectsCount] = obj;
    listenerObjectsCount++;
}

void ConfigClass::onConfigChange() {
    for (int i = 0; i < listenerObjectsCount; i++) {
        listenerObjects[i]->onConfigChange();
    }
}


ConfigClass Config;