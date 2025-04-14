#include "MotionDetector.h"

void MotionDetector::setup() {
    hasVideo = false;
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

    if(devices.size() > 0) {
        videoGrabber.setDeviceID(0);
        videoGrabber.setDesiredFrameRate(30);
        videoGrabber.setup(camWidth, camHeight);
        hasVideo = true;
    } else {
        ofLogNotice() << "No video devices available";
    }

    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void MotionDetector::update() {
    if(hasVideo) {
        videoGrabber.update();
    }
}

//--------------------------------------------------------------
void MotionDetector::draw() {
    if(hasVideo) {
        ofSetHexColor(0x444444);
        videoGrabber.draw(20, 20, ofGetWidth(), ofGetHeight());
    }
}
