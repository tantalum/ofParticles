#include "ofApp.h"

//--------------------------------------------------------------
// ofApp Implementation
//--------------------------------------------------------------

void ofApp::setup(){
    // set the background to black for max contrast
    ofBackground(0);

    const int NUM_PARTICLES = 200;

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
    for(unsigned int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
}

