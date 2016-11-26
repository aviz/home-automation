//
// Created by Avi Zrachya on 24/11/2016.
//

#ifndef ZSWITCH_CONFIGLISTENER_H
#define ZSWITCH_CONFIGLISTENER_H


class ConfigListener {
public:
    virtual void onConfigChange() = 0;
    virtual void onConfigLoaded() = 0;
};
#endif //ZSWITCH_CONFIGLISTENER_H
