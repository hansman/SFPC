#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    rectCount = 10;
    rectSpace = -3;
    rectSize = 60;
    maxDistortion = 12;
    distortion = maxDistortion;
    ofSetBackgroundColor(255);
    topSpace = 30;
    leftSpace = 30;
    dotSize = 4;
    seed = 0;
    
    purplePaperSquare.load("purplePaperSquareBig.png");
    purpleDot.load("dot3.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(seed);
    ofSetColor(190, 140, 190, 200);
    
    
    for (int x = 0; x < rectCount; x++){
        for(int y = 0; y < rectCount; y++){
            float d = ofRandom(-distortion, distortion);
            
            
            #ifdef _USE_TEXTURED_SQUARES
                purplePaperSquare.draw(leftSpace + x * rectSize + (x + 1) * rectSpace + d, topSpace + y * rectSize + (y + 1) * rectSpace + d, 60, 60);
                purpleDot.draw(leftSpace + x * rectSize + (x + 1) * rectSpace + d + rectSize - dotSize, topSpace + y * rectSize + (y + 1) * rectSpace + d + rectSize - dotSize, dotSize, dotSize);
            #else
                ofDrawRectangle(leftSpace + x * rectSize + (x + 1) * rectSpace + d, topSpace + y * rectSize + (y + 1) * rectSpace + d, rectSize, rectSize);
                ofDrawRectangle(leftSpace + x * rectSize + (x + 1) * rectSpace + d + rectSize - dotSize, topSpace + y * rectSize + (y + 1) * rectSpace + d + rectSize - dotSize, dotSize, dotSize);
            #endif

            
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    seed+=100000;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    ofSeedRandom();
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
