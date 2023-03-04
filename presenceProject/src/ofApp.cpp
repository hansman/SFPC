#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("helvetica-regular.otf", 150, true, true);
    ofClear(0);
    rauschen.load("Hans_Noise.wav");
    rauschen.setPosition(0.9);
    rauschen.play();
    rauschen.setPosition(0.9);
    rauschen.setLoop(true);
    ofBackground(32, 78, 135);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    float* freq = ofSoundGetSpectrum(128);
    
    int delta = 500;
    float y = (768 / 2) + font.stringHeight("2020") / 2;
    float x = (1024 / 2) - font.stringWidth("2020")/2;
    
    if (rauschen.getPosition() < 0.36) {
        font.drawString("2020", (rand() % delta - delta / 2) * freq[2] + x, (rand() % delta - delta / 2) * freq[2] + y);
    } else if (rauschen.getPosition() < 0.72) {
        font.drawString("2021", (rand() % delta - delta / 2) * freq[2] + x, (rand() % delta - delta / 2) * freq[2] + y);
    } else {
        font.drawString("2022", (rand() % delta - delta / 2) * freq[2] + x, (rand() % delta - delta / 2) * freq[2] + y);
    }
    
    ofSetColor(221, 87, 39);
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
