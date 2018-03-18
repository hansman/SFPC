#include "ofApp.h"
#include <unistd.h>

//--------------------------------------------------------------
void ofApp::setup(){
    
    sloganPart1 = "LOVE";
    sloganPart2 = "CODE";
    slogan = "LOVE CODE";
    
    font.load("Monaco.otf", 100, true, true, true);
    sloganWidth = font.stringWidth(slogan);
    sloganHeight = font.stringHeight(sloganPart1 + "p" + sloganPart2);
    
    cout << "'LOVE' length " << font.stringWidth(sloganPart1) << endl;
    cout << "'CODE' length " << font.stringWidth(sloganPart2) << endl;
    cout << "space length " << font.stringWidth(slogan) - font.stringWidth(sloganPart1 + sloganPart2) << endl;
    cout << "'LOVE CODE' length " << font.stringWidth(slogan) << endl;
    
    centerWidth = width / 2 - sloganWidth / 2;
    centerHeight = height / 2 + sloganHeight / 2;
    
    
    spaceWidth = font.stringWidth("p");
    // somehow the space width is not getting caluclated correctly -> correcting it manually
    // https://forum.openframeworks.cc/t/getstringboundingbox-and-space-characters/1662/2
    
    mergingSlogans.s1 = ofPoint(-sloganWidth, height / 2 + sloganHeight / 2);
    mergingSlogans.s2 = ofPoint(width, height / 2 + sloganHeight / 2 );
    
    rotatingSlogans.rotation0 = 0;
    rotatingSlogans.rotation1 = 0;
    rotatingSlogans.rotation2 = 0;
    
    splittingSlogans.s1 = ofPoint(centerWidth, centerHeight);
    splittingSlogans.s2 = ofPoint(centerWidth + font.stringWidth(sloganPart1) + spaceWidth, centerHeight);
    
    ofBackground(255);
    
    // yellow
    // ofSetColor(247, 212, 72, 255 / 2);
}

//--------------------------------------------------------------
void ofApp::update(){

}


void ofApp::slogansMerging(int speed) {

    
    if (mergingSlogans.s1.x < centerWidth) {
        mergingSlogans.s1.x += speed;
    } else {
        mergingSlogans.s1.x = centerWidth;
    }
    
    if (mergingSlogans.s2.x > centerWidth) {
        mergingSlogans.s2.x -= speed;
    } else {
        mergingSlogans.s2.x = centerWidth;
    }
   
    // orange
    ofSetColor(227, 124, 59, 255 / 2);
    font.drawString(slogan, mergingSlogans.s1.x, mergingSlogans.s1.y);
    
    // blue
    ofSetColor(118, 172, 195, 255 / 2);
    font.drawString(slogan, mergingSlogans.s2.x, mergingSlogans.s2.y);
    
    
    if (mergingSlogans.s1.x == mergingSlogans.s2.x) {
        
        usleep(1000000);
        currentState = SLOGANS_SPLITTING;
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
        font.drawString(sloganPart1, - (width / 2 - centerWidth), font.stringHeight(sloganPart1) / 2);
        
        // orange
        ofSetColor(227, 124, 59, 255 / 2);
        font.drawString(sloganPart2, spaceWidth / 2, font.stringHeight(sloganPart1) / 2);
        
    } else if (rotatingSlogans.rotation0 != 180) {
        rotatingSlogans.rotation0 = 180;
        
        // blue
        ofSetColor(118, 172, 195, 255 / 2);
        font.drawString(sloganPart1, - (width / 2 - centerWidth), font.stringHeight(sloganPart1) / 2);
        
        // orange
        ofSetColor(227, 124, 59, 255 / 2);
        font.drawString(sloganPart2, spaceWidth / 2, font.stringHeight(sloganPart1) / 2);
    } else {
        ofPushMatrix();
        
        ofTranslate((width / 2 - centerWidth) / 2, font.stringHeight(sloganPart1) / 2);
        ofRotateY(rotatingSlogans.rotation1);
        
        if (rotatingSlogans.rotation1 < 180) {
            rotatingSlogans.rotation1 += speed;
        } else if (rotatingSlogans.rotation1 != 180) {
            rotatingSlogans.rotation1 = 180;
        }
        
        
        // orange
        ofSetColor(227, 124, 59, 255 / 2);
        font.drawString(sloganPart2, -( font.stringWidth(sloganPart2)) / 2 + 20, 0);
        
        ofPopMatrix();
        
        
        ofPushMatrix();
        
        ofTranslate( - (width / 2 - centerWidth) / 2, 0);
        ofRotateY(rotatingSlogans.rotation2);
        
        if (rotatingSlogans.rotation2 < 180) {
            rotatingSlogans.rotation2 += speed;
        } else if (rotatingSlogans.rotation2 != 180) {
            rotatingSlogans.rotation2 = 180;
        }
        
        
        // blue
        ofSetColor(118, 172, 195, 255 / 2);
        font.drawString(sloganPart1, - (width / 2 - centerWidth) / 2, font.stringHeight(sloganPart1) / 2);
        
        ofPopMatrix();
        
    }
    
    ofPopMatrix();

}


void ofApp::slogansSplitting(int speed) {
    
    // orange
    ofSetColor(227, 124, 59, 255 / 2);
    font.drawString(sloganPart1, splittingSlogans.s1.x, splittingSlogans.s1.y);
    font.drawString(sloganPart2, centerWidth + font.stringWidth(sloganPart1) + spaceWidth, centerHeight);
    
    // blue
    ofSetColor(118, 172, 195, 255 / 2);
    font.drawString(sloganPart1, centerWidth, centerHeight);
    font.drawString(sloganPart2, splittingSlogans.s2.x, splittingSlogans.s2.y);
    
    if (splittingSlogans.s2.y > 0) {
        splittingSlogans.s2.y -= speed;
        splittingSlogans.s1.y += speed;
    } else {
        usleep(1000000);
        currentState = SLOGANS_ROTATING;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    switch(currentState) {
        case SLOGANS_MERGING:
            slogansMerging(4);
            break;
        case SLOGANS_SPLITTING:
            slogansSplitting(2);
            break;
        case SLOGANS_ROTATING:
            twoPartsRotating(1);
            break;
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
