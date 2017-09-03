//
// Created by Avi Zrachya on 02/12/2016.
//

#ifndef ZSWITCH_ZWEBSERVER_H
#define ZSWITCH_ZWEBSERVER_H

#include "Runable.h"
#include <ESP8266WebServer.h>
#include <functional>

class WebServer : public Runable {


public:
    // Routes
    void onHandleSetVar();
    void onHandleNotFound();


    static WebServer &getInstance() {
        static WebServer instance;
        return instance;
    }

private:
    ESP8266WebServer server;

    WebServer();

public:
    WebServer(WebServer const &) = delete;
    void operator=(WebServer const &)  = delete;

    virtual void onLoop();
    virtual void onSetup();
};


#endif //ZSWITCH_ZWEBSERVER_H
