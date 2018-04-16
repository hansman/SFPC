#pragma once

#include "ofMain.h"



class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    int xOffset;
    int yOffset;
    int zOffset;
    
    ofEasyCam cam;
    ofImage background;
    
    int opacityCorrection;
    int index = 0;
    int distance = 220;                 // distance between each walking man
    int minElementSize = 5;             // size of smalles element
    float sceneDuration = 75.7;         // time factor between camera perspective switches
    
    map<string, vector<int>> randoms;   // opacity offsets between elements
    
    ofPoint frames[30][24];         // 30 frames, 24 points per frame
    ofPoint frames2d[30][24];       // 30 frames, 24 points per frame
    
    
    
};
