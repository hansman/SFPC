#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int factor = 2;
    
    img.load("lederhosen.png");
    img.setImageType(OF_IMAGE_GRAYSCALE);
    img.resize(img.getWidth() / factor, img.getHeight() / factor);
    
    tile.load("kuh.jpg");
    tile.resize(21, 21);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    // img.draw(0,0);
    
    // ofTranslate(0, img.getHeight());
    
    for (int i = 0; i < img.getWidth(); i+=21){
        for (int j = 0; j < img.getHeight(); j+=21){
            ofColor pixel = img.getColor(i, j);
            float brightness = pixel.getBrightness();
            float b = ofMap(brightness, 0, 255, 0, 350);
            ofPushMatrix();
            ofTranslate(i, j);
            //ofRotateY(ofMap(brightness, 0, 255, 0, 180));
            // ofScale(0.3, 1);
            ofSetColor(255, 255, 255, b);
            // ofDrawCircle(0, 0, 5);
            tile.draw(0,0);
            ofPopMatrix();
        }
    }
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
