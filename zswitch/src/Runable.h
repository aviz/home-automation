//
// Created by Avi Zrachya on 18/11/2016.
//

#ifndef ZSWITCH_LOOPABLE_H
#define ZSWITCH_LOOPABLE_H

class Runable {
public:
    virtual void onLoop() = 0;
    virtual void onSetup() = 0;
};

#endif //ZSWITCH_LOOPABLE_H
