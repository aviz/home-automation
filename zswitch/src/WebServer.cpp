//
// Created by Avi Zrachya on 02/12/2016.
//


//#include <iostream>
//#include <functional>
#include "WebServer.h"
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include <FS.h>
#include <Config.h>


WebServer::WebServer() : server(80) {
    Serial.println("WebServer Created");

}

void WebServer::onSetup() {
    server.on("/var", HTTP_POST, [](){
        WebServer::getInstance().onHandleSetVar();
    });

    server.serveStatic("/index.htm", SPIFFS, "/index.htm");
    server.serveStatic("/fonts", SPIFFS, "/fonts", "max-age=86400");
    server.serveStatic("/js", SPIFFS, "/js");
    server.serveStatic("/css", SPIFFS, "/css", "max-age=86400");
    server.serveStatic("/images", SPIFFS, "/images", "max-age=86400");
    server.serveStatic("/", SPIFFS, "/index.htm");

    server.onNotFound([]() {
        WebServer::getInstance().onHandleNotFound();
    });
    server.begin();
}

void WebServer::onLoop() {
    server.handleClient();
}

void WebServer::onHandleSetVar() {
    String name = server.arg("name");
    String value = server.arg("value");

    Serial.println(name);
    Serial.println(value);

    DynamicJsonBuffer jsonBuffer;
    JsonObject& json = jsonBuffer.createObject();

    JsonObject& data = json.createNestedObject("data");
    //data["name"] =
    //data["value"] = name;


    String responsJson;
    json.printTo(responsJson);

    server.send ( 200, "text/json", responsJson);
}


void WebServer::onHandleNotFound() {
    Serial.println("Got Not Found CB");
    server.send ( 404, "text/plain", "not found" );
}





