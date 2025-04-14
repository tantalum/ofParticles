#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "MotionDetector.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

private:
    vector<Particle> particles; // map of all the particles
    MotionDetector motionDetector;
};

