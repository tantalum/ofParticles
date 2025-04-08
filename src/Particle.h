#include "ofMain.h"

// Represents a particle in 2d space
class Particle {
public:
    void setup();
    void update();
    void draw();

    void setParticles(vector<Particle>* particles);
    bool isInteracting(Particle * particle);
    void updateParticles(Particle * particle2);

    ofVec2f p; // position (centre of mass)
    ofVec2f v; // velocity
    ofVec2f w; // angular velocity
    float m; // mass
    ofColor colour;
    float radius;

    bool updated; // has this particle been updated

    vector<Particle>* particles; // pointer to other particles
};


