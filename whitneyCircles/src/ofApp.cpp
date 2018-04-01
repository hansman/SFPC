#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float t = ofGetElapsedTimef();
    int distance = 40;
    
    int radius = 15;
    int circleOverlaps = 50;
    float yScaling = 1.1;
    float yScalingPower = ofMap(pow(sin(t * 0.345), 8), -1, 1, 1, 3);
    
    
    ofSeedRandom(0);
    ofPushMatrix();
    float xStart = ofMap(pow(sin(t * 1.7), 4), 0, 1, 0, 1024 / 3);
    int xEnd = ofMap(pow(sin(t * 2.1), 4), 0, 1, 1024 * 2 / 3, 1024);
    ofTranslate(xStart, 0);
    ofSetColor(167, 45, 30, 10);
    int height = 768;
    int x = 0;
    int y = 0;
    
    float xPhaseStart = ofMap(pow(sin(t * 1.3), 4), 0, 1, - PI / 5, - PI / 5);
    float xPhaseEnd = ofMap(pow(sin(t * 1.1), 4), 0, 1, 0.9 * PI / 2, 1.1 * PI / 2);
    
    for (int i = 0; i < 100; i++) {
        if (x > xEnd) {
            break;
        }
        float xPhase = ofMap(pow(sin(t), 4), 0, 1, 0, xPhaseEnd);
        float yScalingPhase = ofMap(pow(sin(t*1.34), 4), 0, 1, 0, xPhaseEnd);
        float d = ofMap(pow(sin(ofMap(i, 0, 60, 0, PI / 2) + xPhase), 4), -1, 1, distance / 6, 4 * distance / 3);
        float width = ofMap(d, 0, 2 * distance, 2 * distance / 3,  distance);
        float xOffsetRange = ofMap(sin(t * 0.8), -1, 1, 0, d / 4);
        for (int j = 0; j < 1000; j++) {
            
            float yScaling = pow(ofMap(sin(ofMap(i, 0, 15, 0, PI / 2) + yScalingPhase), 0, 1, 0.9, 1.05), yScalingPower);
            float factor = pow(j, yScaling);
            if ( distance * factor > height / 2) {
                break;
            }
            float ellipseHeight = 2.1 * radius * yScaling;
            float yOffsetRange = (ellipseHeight / 5);
            for (int k = 0; k < circleOverlaps; k++) {
                float offsetX = ofRandom(-xOffsetRange, xOffsetRange);
                float offsetY = ofRandom(-yOffsetRange, yOffsetRange);
                ofDrawEllipse(x, height / 2 + factor * distance + offsetY, width, ellipseHeight);
                if (j > 0) {
                    ofDrawEllipse(x, height / 2 - factor * distance + offsetY, width, ellipseHeight);
                }
            }
        }
        
        x += d;
    }
    ofPopMatrix();

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
