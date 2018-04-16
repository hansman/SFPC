#include "ofApp.h"
#include "data.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    
    //----------------------------------------------------------------
    // the data is stored in a big flat array, let's copy it into something more managable
    // don't have to touch this :)
    
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 24; j++){
            float x = data3d[ i * 24 * 3  + j * 3 + 0 ];
            float y = data3d[ i * 24 * 3  + j * 3 + 1 ];
            float z = data3d[ i * 24 * 3  + j * 3 + 2 ];
            frames[i][j].set(x,y,z);
        }
    }
    
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 24; j++){
            float x = data2d[ i * 24 * 2  + j * 2 + 0 ];
            float y = data2d[ i * 24 * 2  + j * 2 + 1 ];
            frames2d[i][j].set(x,y);
        }
    }
    
    background.load("img13.jpg");
    background.resize(1024,768);
    
    ofSeedRandom(0);
    
    for (int i = 0; i < 25; i++) {
        randoms["blue"].push_back(ofRandom(0, 25));
        randoms["green"].push_back(ofRandom(0, 25));
        randoms["lila"].push_back(ofRandom(0, 25));
        randoms["yellow"].push_back(ofRandom(0, 25));
    }
    
    //----------------------------------------------------------------
    
    ofBackground(0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(160);
    background.draw(0, 0);
    
    
    ofPoint data3d[24];
    ofPoint data2d[24];
    
    
    int frameNumber =(int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[ frameNumber][i];
        data2d[i] = frames2d[frameNumber][i];
    }
    
    float time = ofGetElapsedTimef() * 10;
    
    int opacity = ofMap(fmod(time, sceneDuration / 2), 0, (sceneDuration / 2), 0, 255);
    
    // switch camera perspective and position
    if (((int)(time / (sceneDuration * 2) ) % 3) == 0) { // front
        cam.enableOrtho();
        cam.setOrientation(ofVec3f(0, 0, 1));
        cam.setGlobalPosition(0, 0, 665.107);
    } else if (((int)(time / (sceneDuration * 2) ) % 3) == 1) { // diagonal
        cam.disableOrtho();
        cam.setGlobalOrientation(ofQuaternion(-0.1202, 0.256807, 0.0322075, 0.958418));
        cam.setGlobalPosition(322.254, 164.246, 558.161);
    }  else if (((int)(time / (sceneDuration * 2) ) % 3) == 2) { // side
        cam.enableOrtho();
        cam.setGlobalOrientation(ofQuaternion(0.00305331, 0.665469, -0.00272219, 0.746414));
        cam.setGlobalPosition(660.727, -5.44134, 76.0105);
    }

    /**
     * measure camera perspective and position
     * cout << "global orientation "  << cam.getGlobalOrientation() << endl;
     * cout << "global position "  << cam.getGlobalPosition() << endl;
     */
    
    cam.begin();
    
    
    // draw each man
    for (int i = 0; i < 24; i++) {
        
        float x = data3d[i].x;
        float y = data3d[i].y;
        float z = data3d[i].z;
        
        // vera molnar colors
        
        // green man
        int size = minElementSize + (i + 1) % 5;
        
        if (((int)(time / (sceneDuration / 2) ) % 4) == 1) {
            ofSetColor(60, 120, 73, min(opacity + randoms["green"][i], 255) );
        } else {
            ofSetColor(60, 120, 73);
        }
        ofDrawSphere(ofPoint(x,y, z + distance), size);

        // blue man
        size = minElementSize + (i + 2) % 5;
        
        if (((int)(time / (sceneDuration / 2) ) % 4) == 2) {
            ofSetColor(213, 254, 254, min(opacity + randoms["blue"][i], 255));
        } else {
            ofSetColor(213, 254, 254);
        }
        ofDrawBox(ofPoint(x, y, z), size, size, size * 2);
        
        
        // yellow man
        size = minElementSize + (i + 3) % 5;
        
        if (((int)(time / (sceneDuration / 2) ) % 4) == 3) {
            ofSetColor(239, 225, 108, min(opacity + randoms["yellow"][i], 255));
        } else {
            ofSetColor(239, 225, 108);
        }
        ofDrawCylinder(ofPoint(x, y, z - distance), size, size * 2);
        
        
        // lila man
        size = minElementSize + (i + 4) % 5;
        
        if (((int)(time / (sceneDuration / 2) ) % 4) == 0) {
            ofSetColor(101, 45, 183, min(opacity + randoms["lila"][i], 255));
        } else {
            ofSetColor(101, 45, 183);
        }
        ofDrawCone(ofPoint(x, y, z - 2 * distance), size, size * 2);
        
        
    }
    
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    // distance = mouseX;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
