#pragma once

#include "ofMain.h"

class MotionDetector {
public:
    void setup();
    void update();
    void draw();

private:
    int camWidth;
    int camHeight;
    ofVideoGrabber videoGrabber;
    bool hasVideo;
};
