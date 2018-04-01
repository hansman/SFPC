#include "ofApp.h"


bool sort_brightness(ofImage a, ofImage b) {
    float aBrightness = 0;
    float bBrightness = 0;
    
    for (int m = 0; m < a.getWidth(); m++) {
        for (int n = 0; n < a.getHeight(); n++) {
            aBrightness += a.getColor(m, n).getBrightness();
        }
    }
    
    aBrightness = aBrightness / (a.getWidth()*a.getHeight());
    
    for (int m = 0; m < b.getWidth(); m++) {
        for (int n = 0; n < b.getHeight(); n++) {
            bBrightness += b.getColor(m, n).getBrightness();
        }
    }
    bBrightness = bBrightness/ (b.getWidth()*b.getHeight());
    
    return aBrightness < bBrightness;
}

//--------------------------------------------------------------
void ofApp::setup(){
    int factor = 2;
    
    img.load("lederhosen.png");
    img.setImageType(OF_IMAGE_GRAYSCALE);
    img.resize(img.getWidth() / factor, img.getHeight() / factor);
    
    fbo.allocate(img.getWidth()*6, img.getHeight()*6, GL_RGBA, 4);
    gridSize = 2;

    
    for (int i = 0; i < IMAGE_COUNT; i++) {
        ofImage temp;
        temp.load(to_string(i+1) + ".jpg");
        images.push_back(temp);
    }
    
    ofSort(images, sort_brightness);
    
    images.push_back(img);
    
    fbo.begin();
    ofClear(0, 0, 0, 255);
    ofSetColor(255);
    
    for(int i = 0; i < img.getWidth(); i+=gridSize) {
        vector<int> rowImg;
        for(int j = 0; j < img.getHeight(); j+=gridSize) {
            float brightness = 0;
            
            for (int m = 0; m < gridSize; m++) {
                for (int n = 0; n < gridSize; n++) {
                    brightness += img.getColor(m+i, n+j).getBrightness();
                }
            }
            
            brightness = brightness / (gridSize * gridSize);
            
            int idx = (int)ofMap(brightness, 0, 255, 1, IMAGE_COUNT - 1);
            images[idx].draw(i*6, j*6, gridSize*6, gridSize*6);
            rowImg.push_back(idx);
        }
        // store the image at each index location, so what image is drawn at 1,1 etc
        imgArr.push_back(rowImg);
    }
    fbo.end();
    
    ofPixels pixels;
    fbo.readToPixels(pixels);
    img.setFromPixels(pixels);
    images.push_back(pixels);
    idx = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    int width = ofGetWidth();
    int height = img.getHeight() / img.getWidth() * width;
    
    fbo.draw(0, 0, width, height);
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
