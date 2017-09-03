//
// Created by Avi Zrachya on 03/12/2016.
//

#ifndef ZSWITCH_CONFIGVALUE_H
#define ZSWITCH_CONFIGVALUE_H


#include <string>
#include <ArduinoJson.h>

enum valueType {
    STRING,
    INT,
};


class ConfigValueMapper {
public:
    ConfigValueMapper(const std::string &name, void *var_ptr, valueType type, size_t length);

    void toJson(JsonObject &obj);
    void fromJson(JsonObject &obj);
private:
    std::string name;
    void *var_ptr;
    valueType type;
    size_t length;
};


#endif //ZSWITCH_CONFIGVALUE_H
