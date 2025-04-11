#include "ofApp.h"

//--------------------------------------------------------------
// ofApp Implementation
//--------------------------------------------------------------

void ofApp::setup(){
    camWidth = 640;
    camHeight = 480;

    // Initialize the Camera Device
    vector<ofVideoDevice> devices = videoGrabber.listDevices();
    for(size_t i = 0; i < devices.size(); i++) {
        ofVideoDevice device = devices[i];
        if(device.bAvailable) {
            ofLogNotice() << device.id << ": " << device.deviceName << " - Available";
        } else {
            ofLogNotice() << device.id << ": " << device.deviceName << " - Unavailanle";
        }
    }
    videoGrabber.setDeviceID(0);
    videoGrabber.setDesiredFrameRate(30);
    videoGrabber.setup(camWidth, camHeight);

    ofSetVerticalSync(true);

    // set the background to black for max contrast
    ofBackground(0);

    // Initialize the Partcile Field
    for(unsigned int i=0; i<NUM_PARTICLES; i++){
        Particle particle;
        particle.setup();
        particles.push_back(particle);
    }

    for(unsigned int i=0; i<particles.size(); i++){
        particles[i].setParticles(&particles);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    videoGrabber.update();

    // first set all of the particles updated to be false
    for(unsigned int i=0; i<particles.size(); i++){
        particles[i].updated = false;
    }
    for(unsigned int i=0; i<particles.size(); i++){
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0x444444);
    videoGrabber.draw(20, 20, ofGetWidth(), ofGetHeight());
    for(unsigned int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
}

