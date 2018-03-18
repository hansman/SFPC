#include "ofApp.h"
#include <unistd.h>


int getTextWidth(ofTrueTypeFont * font, string text) {
    return font->getStringBoundingBox(text, 0, 0).getWidth();
}


//--------------------------------------------------------------
void ofApp::setup(){
    
    sloganPart1 = "LOVE";
    sloganPart2 = "CODE";
    
    font.load("Consolas.ttf", 100, true, true, true);
    
    
    sloganHeight = font.stringHeight(sloganPart1);
    
    // take the longer part of the two word slogan
    sloganPartWidthLong = getTextWidth(&font, sloganPart2) > getTextWidth(&font, sloganPart1) ? getTextWidth(&font, sloganPart2) : getTextWidth(&font, sloganPart1);
    // make its width dividable by 2
    sloganPartWidthLong = sloganPartWidthLong % 2 ? (sloganPartWidthLong + 1) : sloganPartWidthLong;
    
    
    // take the longer part of the two word slogan
    sloganPartWidthShort = getTextWidth(&font, sloganPart2) < getTextWidth(&font, sloganPart1) ? getTextWidth(&font, sloganPart2) : getTextWidth(&font, sloganPart1);
    // make its width dividable by 2
    sloganPartWidthShort = sloganPartWidthShort % 2 ? (sloganPartWidthShort + 1) : sloganPartWidthShort;
    sloganShortIndention = (sloganPartWidthLong - sloganPartWidthShort) / 2;
    
    spaceWidth = 80;
    
    centerHeight = height / 2 + sloganHeight / 2;

    mergingSlogans.s1 = ofPoint(- 2 * sloganPartWidthLong - spaceWidth, centerHeight);
    mergingSlogans.s2 = ofPoint(width, centerHeight);
    
    splittingSlogans.s1 = ofPoint(width / 2 - spaceWidth / 2 - sloganPartWidthLong, centerHeight);
    splittingSlogans.s2 = ofPoint(width / 2 + spaceWidth / 2, centerHeight);
    
    rotatingSlogans.rotation0 = 0;
    rotatingSlogans.rotation1 = 0;
    rotatingSlogans.rotation2 = 0;
    
    ofBackground(255);
    currentState = 5;
    
    // yellow
    // ofSetColor(247, 212, 72, 255 / 2);
}

//--------------------------------------------------------------
void ofApp::update(){

}


void ofApp::slogansMerging(int speed) {
    int centerWidth = width / 2 - spaceWidth / 2 - sloganPartWidthLong;
    
    if (mergingSlogans.s1.x <= centerWidth) {
        mergingSlogans.s1.x += speed;
    } else {
        mergingSlogans.s1.x = centerWidth;
        mergingSlogans.s2.x = centerWidth;
    }
    
    if (mergingSlogans.s2.x >= centerWidth) {
        mergingSlogans.s2.x -= speed;
    } else {
        mergingSlogans.s2.x = centerWidth;
        mergingSlogans.s1.x = centerWidth;
    }
   
    // orange
    ofSetColor(227, 124, 59, 255 / 2);
    font.drawString(sloganPart1, mergingSlogans.s1.x + sloganShortIndention, mergingSlogans.s1.y);
    font.drawString(sloganPart2, mergingSlogans.s1.x + sloganPartWidthLong + spaceWidth, mergingSlogans.s1.y);
    
    // blue
    ofSetColor(118, 172, 195, 255 / 2);
    font.drawString(sloganPart1, mergingSlogans.s2.x + sloganShortIndention, mergingSlogans.s2.y);
    font.drawString(sloganPart2, mergingSlogans.s2.x + sloganPartWidthLong + spaceWidth, mergingSlogans.s2.y);
    
    
    cout << mergingSlogans.s2.x + sloganShortIndention << endl;
    cout << mergingSlogans.s1.x + sloganShortIndention << endl;
    
    if (mergingSlogans.s1.x == mergingSlogans.s2.x) {
        currentState = SLOGANS_SPLITTING;
    }
    
}


void ofApp::slogansSplitting(int speed) {
    
    // orange
    ofSetColor(227, 124, 59, 255 / 2);
    font.drawString(sloganPart1, width / 2 - spaceWidth / 2 - sloganPartWidthLong + sloganShortIndention, splittingSlogans.s1.y);
    font.drawString(sloganPart2, width / 2 + spaceWidth / 2, centerHeight);
    
    // blue
    ofSetColor(118, 172, 195, 255 / 2);
    font.drawString(sloganPart1, width / 2 - spaceWidth / 2 - sloganPartWidthLong + sloganShortIndention, centerHeight);
    font.drawString(sloganPart2, width / 2 + spaceWidth / 2, splittingSlogans.s2.y);
    
    if (splittingSlogans.s2.y >= -speed) {
        splittingSlogans.s2.y -= speed;
        splittingSlogans.s1.y += speed;
    } else {
        usleep(1000000);
        currentState = SLOGANS_ROTATING;
    }
    
}



void ofApp::twoPartsRotating(int speed) {

    
    ofPushMatrix();
    ofTranslate(width / 2, height / 2);
    ofRotateY(rotatingSlogans.rotation0);
    if (rotatingSlogans.rotation0 < 180) {
        rotatingSlogans.rotation0 += speed;
        
        // blue
        ofSetColor(118, 172, 195, 255 / 2);
        font.drawString(sloganPart1, - spaceWidth / 2 - sloganPartWidthLong + sloganShortIndention, sloganHeight / 2);
        
        // orange
        ofSetColor(227, 124, 59, 255 / 2);
        font.drawString(sloganPart2, spaceWidth / 2, sloganHeight / 2);
        
    } else if (rotatingSlogans.rotation0 != 180) {
        rotatingSlogans.rotation0 = 180;
        
        // blue
        ofSetColor(118, 172, 195, 255 / 2);
        font.drawString(sloganPart1, - spaceWidth / 2 - sloganPartWidthLong + sloganShortIndention, sloganHeight / 2);
        
        // orange
        ofSetColor(227, 124, 59, 255 / 2);
        font.drawString(sloganPart2, spaceWidth / 2, sloganHeight / 2);
    } else {
        ofPushMatrix();
        
        ofTranslate( spaceWidth / 2 + sloganPartWidthLong / 2, 0);
        ofRotateY(rotatingSlogans.rotation1);
        
        if (rotatingSlogans.rotation1 < 180) {
            rotatingSlogans.rotation1 += speed;
        } else if (rotatingSlogans.rotation1 != 180) {
            rotatingSlogans.rotation1 = 180;
        }
        
        
        // orange
        ofSetColor(227, 124, 59, 255 / 2);
        font.drawString(sloganPart2, - sloganPartWidthLong / 2, sloganHeight / 2);
        
        ofPopMatrix();
        
        ofPushMatrix();
        
        ofTranslate( - spaceWidth / 2 - sloganPartWidthLong / 2, 0);
        ofRotateY(rotatingSlogans.rotation1);
        
        if (rotatingSlogans.rotation2 < 180) {
            rotatingSlogans.rotation2 += speed;
        } else if (rotatingSlogans.rotation2 != 180) {
            rotatingSlogans.rotation2 = 180;
        }
        
        
        // blue
        ofSetColor(118, 172, 195, 255 / 2);
        font.drawString(sloganPart1, - sloganPartWidthLong / 2 + sloganShortIndention, sloganHeight / 2);
        
        ofPopMatrix();
        
    }
    
    ofPopMatrix();

}


//--------------------------------------------------------------
void ofApp::draw() {
    
    switch(currentState) {
        case SLOGANS_MERGING:
            slogansMerging(3);
            break;
        case SLOGANS_SPLITTING:
            slogansSplitting(3);
            break;
        case SLOGANS_ROTATING:
            twoPartsRotating(1);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    currentState = SLOGANS_MERGING;
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
