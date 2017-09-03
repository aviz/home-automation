//
// Created by Avi Zrachya on 24/11/2016.
//

#include "Config.h"
#include <ArduinoJson.h>
#include <FS.h>
#include <WString.h>


bool ConfigClass::addTuple(std::string name, valueType type, void *var_ptr, size_t length) {
    values_map[name.c_str()] = new ConfigValueMapper(name, var_ptr, type, length);
    return true;
}

void ConfigClass::onInit() {
    SPIFFS.begin();
    memset(&values,'\0', sizeof(ConfigValues));
    loadDefaults();
    addTuple("version", INT, &values.version, sizeof(values.version));
    addTuple("ap_password", STRING, &values.ap_password, 0);
    addTuple("ap_ssid", STRING, &values.ap_ssid, 0);
    addTuple("wifi_ssid", STRING, &values.wifi_ssid, 0);
    addTuple("wifi_password", STRING, &values.wifi_password, 0);
    Serial.println("-----------------------------");
    Serial.println("          Config Init");
    Serial.println("-----------------------------");

    loadConfigFile();
    save();
}

bool ConfigClass::loadConfigFile() {
    File configFile = SPIFFS.open("/config.json", "r");
    if (!configFile) {
        Serial.println("Failed to open config file");
        return false;
    }

    size_t size = configFile.size();

    char *file_content = (char *) malloc(size);

    if (file_content == NULL) {
        Serial.println("Allocation error");
        return false;
    }

    configFile.readBytes(file_content, size);

    Serial.println(file_content);

    bool rc = false;//deserialize(file_content);
    free(file_content);


    return rc;
}

void ConfigClass::loadDefaults() {
    values.version = MAX_VERSION;
    values.ap_password = "AdminAdmin";
    values.ap_ssid = "";
    values.wifi_ssid = "";
    values.wifi_password = "";

}

bool ConfigClass::deserialize(const char *data) {

    size_t size = strlen(data);
    DynamicJsonBuffer jsonBuffer;
    JsonObject& json = jsonBuffer.parseObject(data);

    if (!json.success()) {
        Serial.println("Failed to parse config file");
        return false;
    }

    for(auto const&val : values_map) {
        val.second->fromJson(json);
    }
    values.version = MAX_VERSION;

    return true;
}

bool ConfigClass::serializeToConfig() {
    DynamicJsonBuffer jsonBuffer;
    JsonObject& json = jsonBuffer.createObject();


    for(auto const&val : values_map) {
        val.second->toJson(json);
    }
    values.version = MAX_VERSION;

    File config_file = SPIFFS.open("/config.json", "w");
    if (!config_file) {
        Serial.println("Failed to open config file for writing");
        return false;
    }

    json.printTo(config_file);
    config_file.close();

    return true;
}

bool ConfigClass::serializeToString(std::string &out) {
    DynamicJsonBuffer jsonBuffer;
    JsonObject& json = jsonBuffer.createObject();


    for(auto const&val : values_map) {
        val.second->toJson(json);
    }
    values.version = MAX_VERSION;

    String str(out.c_str());
    json.printTo(str);

    return true;
}

bool ConfigClass::save() {
    serializeToConfig();
    onConfigChange();
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