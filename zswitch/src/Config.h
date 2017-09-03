//
// Created by Avi Zrachya on 24/11/2016.
//

#ifndef ZSWITCH_CONFIG_H
#define ZSWITCH_CONFIG_H


#include "Initializeable.h"
#include "ConfigListener.h"
#include "ConfigValueMapper.h"
#include <string>
#include <map>

#define MAX_PASS_LENGTH 16
#define MAX_SSID_LENGTH 128
#define MAX_VERSION 1


typedef struct {
    int version;
    std::string ap_password;
    std::string ap_ssid;
    std::string wifi_ssid;
    std::string wifi_password;
} ConfigValues;


class ConfigClass : public Initializeable {
private:
    bool serializeToConfig();
    bool deserialize(const char *data);
    bool loadConfigFile();
    bool save();
    void set(std::string &name, std::string &value);
    void onConfigChange();
    ConfigListener *listenerObjects[100];
    int listenerObjectsCount;

public:
    virtual void onInit();
    void loadDefaults();
    void registerListener(ConfigListener *obj);
    ConfigValues values;

private:
    std::map<std::string, ConfigValueMapper *> values_map;
    bool addTuple(std::string name, valueType type, void *var_ptr, size_t length);

    bool serializeToString(std::string &out);
};

extern ConfigClass Config;

#endif //ZSWITCH_CONFIG_H

