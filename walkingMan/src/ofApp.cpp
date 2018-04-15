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
    //----------------------------------------------------------------
    
    ofBackground(0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    int distance = 200;     // distance between each walking man
    int size = 7;           // size of each element of the man
    int timeFactor = 76;    // time between camera perspective switches
    
    
    ofPoint data3d[24];
    ofPoint data2d[24];
    
    
    int frameNumber =(int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[ frameNumber][i];
        data2d[i] = frames2d[frameNumber][i];
    }
    
    float time = ofGetElapsedTimef() * 10;
    int opacity = (int)(time * 10.1) % 255;
    
    // switch camera perspective and position
    if (((int)(time / timeFactor ) % 3) == 0) {
        // front
        cam.setOrientation(ofVec3f(0, 0, 1));
        cam.setGlobalPosition(0, 0, 665.107);
    } else if (((int)(time / timeFactor ) % 3) == 1) {
        // diagonal
        cam.setGlobalOrientation(ofQuaternion(-0.1202, 0.256807, 0.0322075, 0.958418));
        cam.setGlobalPosition(322.254, 164.246, 558.161);
    }  else if (((int)(time / timeFactor ) % 3) == 2) {
        // side
        cam.setGlobalOrientation(ofQuaternion(0.00305331, 0.665469, -0.00272219, 0.746414));
        cam.setGlobalPosition(660.727, -5.44134, 76.0105);
    }

    /**
     * measure camera perspective and position
     * cout << "global position "  << cam.getGlobalPosition() << endl;
     *  cout << "global orientation "  << cam.getGlobalOrientation() << endl;
     */
    
    cam.begin();
    cam.enableOrtho();
    
    // draw each walking man
    for (int i = 0; i < 24; i++) {
        
        float x = data3d[i].x;
        float y = data3d[i].y;
        float z = data3d[i].z;
        
        ofSetColor(60, 120, 73, (opacity + 60) % 255); // green
        ofDrawSphere(ofPoint(x,y, z + distance), size);
        
        ofSetColor(213, 254, 254, (opacity + 120) % 255); // blue
        ofDrawBox(ofPoint(x,y, z), size, size, size * 2);
        
        ofSetColor(239, 225, 108, (opacity + 180) % 255); // yellow
        ofDrawCylinder(ofPoint(x,y, z - distance), size, size * 2);
        
        ofSetColor(101, 45, 183, (opacity + 240) % 255); // lila
        ofDrawCone(ofPoint(x,y, z - distance * 2), size, size * 2);
        
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
