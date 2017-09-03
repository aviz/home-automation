//
// Created by Avi Zrachya on 03/12/2016.
//

#include "ConfigValueMapper.h"

void ConfigValueMapper::toJson(JsonObject& obj) {

    if(var_ptr == _NULL) {
        return;
    }
    switch(type) {
        case STRING:
            obj[name.c_str()] = (*((std::string *)var_ptr)).c_str();
            break;
        case INT:
            obj[name.c_str()] = *((int *)var_ptr);
            break;
    }

}

void ConfigValueMapper::fromJson(JsonObject &obj) {
    if(var_ptr == _NULL) {
        return;
    }
    switch(type) {
        case STRING:
            *((std::string *)var_ptr) = obj[name.c_str()].asString();
            break;
        case INT:
            *((int *)var_ptr) = obj[name.c_str()].as<int>();
            break;
    }
}

ConfigValueMapper::ConfigValueMapper(const std::string &name, void *var_ptr, valueType type, size_t length) : name(name),
                                                                                                  var_ptr(var_ptr),
                                                                                                  type(type),
                                                                                                  length(length) {

}
