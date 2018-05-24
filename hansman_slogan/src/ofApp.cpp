/**
 * Hans Steinbrecher May 2018, Piding, Germany
 * Design inspired by Dimitri Likissas 'DESIRE'
 */

#include "ofApp.h"


void ofApp::setup(){
    
    font.load("helvetica-regular.otf", 190, true, true, true);
    
    fbo.allocate(width, height, GL_RGBA);
    
    ofSeedRandom(0);
    
    redColors.push_back(ofColor(155, 59,	85));
    redColors.push_back(ofColor(182, 101, 111));
    redColors.push_back(ofColor(194, 99, 120));
    redColors.push_back(ofColor(216, 132, 150));
    redColors.push_back(ofColor(168, 68,	97));
    redColors.push_back(ofColor(201, 112, 127));
    redColors.push_back(ofColor(124, 54, 92));
    redColors.push_back(ofColor(226, 154, 157));
    redColors.push_back(ofColor(137, 64, 46));
    redColors.push_back(ofColor(182, 79, 112));
    redColors.push_back(ofColor(219, 121, 139));
    redColors.push_back(ofColor(136, 56, 100));
    redColors.push_back(ofColor(175, 118, 61));
    redColors.push_back(ofColor(198, 78, 107));
    redColors.push_back(ofColor(194, 58, 55));
    redColors.push_back(ofColor(150, 58, 113));
    redColors.push_back(ofColor(238, 163, 171));
    
    yellowColors.push_back(ofColor(199,	158, 63));
    yellowColors.push_back(ofColor(246,	208, 64));
    yellowColors.push_back(ofColor(248,	240, 70));
    yellowColors.push_back(ofColor(191,	224, 76));
    yellowColors.push_back(ofColor(236, 249, 80));
    yellowColors.push_back(ofColor(242,	244, 88));
    yellowColors.push_back(ofColor(245,	209, 48));
    yellowColors.push_back(ofColor(197,	233, 82));
    yellowColors.push_back(ofColor(244,	244, 171));
    yellowColors.push_back(ofColor(242,	240, 186));
    yellowColors.push_back(ofColor(245,	202, 51));

    
    fbo.begin();
    ofClear(255, 255, 255, 0);
    ofSetColor(255,0,0);
    int yOffset = 195;
    int xOffset = 300;
    font.drawString("HANS", xOffset, 220);
    font.drawString("STEI", xOffset, 220 + yOffset);
    font.drawString("NBRE", xOffset, 220 + yOffset + yOffset);
    font.drawString("CHER", xOffset, 220 + yOffset + yOffset + yOffset);
    
    fbo.readToPixels(pixels);
    fbo.end();
    
    ofBackground(0, 0, 0);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    for (int x = 0; x < width; x += stride) {
        for (int y = 0; y < height; y += stride) {
            if (pixels.getColor(x, y) != ofColor(255, 255, 255, 0)) {
                ofSetColor( yellowColors[ofRandom(0, yellowColors.size())] );
            } else {
                ofSetColor( redColors[ofRandom(0, redColors.size())] );
            }
            ofDrawCircle(x, y, radius);
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
