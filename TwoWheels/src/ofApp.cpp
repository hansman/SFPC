#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofSetCircleResolution(100);

    r1 = 75;
    x1 = 150;
    y1 = 350;
    w1 = 20;
    h1 = 20;
    speed = 90;
    mainAngle = 360 / 8;
    
    iw1.r = 75;
    iw1.x = 150;
    iw1.y = 531;
    iw1.w = 22;
    iw1.h = 20;
    iw1.rotation = -6;
    iw1.startAngle = 46;
    iw1.endAngle = fmod(46 + mainAngle, 360);
    iw1.clockWise = false;
    iw1.soundPlayer.load("bell_a3.wav");
    
    iw2.r = 75;
    iw2.x = 331;
    iw2.y = 350;
    iw2.w = 22;
    iw2.h = 20;
    iw2.rotation = -6;
    iw2.startAngle = 317;
    iw2.endAngle = fmod(317 + mainAngle, 360);
    iw2.clockWise = false;
    iw2.soundPlayer.load("bell_a4.wav");
    
    iw3.r = 75;
    iw3.x = 331;
    iw3.y = 162;
    iw3.w = 22;
    iw3.h = 20;
    iw3.rotation = -6;
    iw3.startAngle = 317;
    iw3.endAngle = fmod(317 + mainAngle, 360);
    iw3.clockWise = true;
    iw3.soundPlayer.load("bell_b4.wav");
    
    iw4.r = 75;
    iw4.x = 520;
    iw4.y = 350;
    iw4.w = 22;
    iw4.h = 20;
    iw4.rotation = -6;
    iw4.startAngle = 317;
    iw4.endAngle = fmod(317 + mainAngle, 360);
    iw4.clockWise = true;
    iw4.soundPlayer.load("bell_c4.wav");
    
    iw5.r = 75;
    iw5.x = 685;
    iw5.y = 262;
    iw5.w = 22;
    iw5.h = 20;
    iw5.rotation = -14;
    iw5.startAngle = 317;
    iw5.endAngle = fmod(317 + mainAngle, 360);
    iw5.clockWise = false;
    iw5.soundPlayer.load("bell_d#4.wav");
    
    iw6.r = 75;
    iw6.x = 565;
    iw6.y = 112;
    iw6.w = 22;
    iw6.h = 20;
    iw6.rotation = -31;
    iw6.startAngle = 317;
    iw6.endAngle = fmod(317 + mainAngle, 360);
    iw6.clockWise = true;
    iw6.soundPlayer.load("bell_e4.wav");
    
    
    iw7.r = 75;
    iw7.x = 865;
    iw7.y = 207;
    iw7.w = 22;
    iw7.h = 20;
    iw7.rotation = -31;
    iw7.startAngle = 317;
    iw7.endAngle = fmod(317 + mainAngle, 360);
    iw7.clockWise = true;
    iw7.soundPlayer.load("bell_f4.wav");

    iw8.r = 75;
    iw8.x = 115;
    iw8.y = 167;
    iw8.w = 22;
    iw8.h = 20;
    iw8.rotation = -29;
    iw8.startAngle = 230;
    iw8.endAngle = fmod(230 + mainAngle, 360);
    iw8.clockWise = false;
    iw8.soundPlayer.load("bell_g4.wav");
    
    iw9.r = 75;
    iw9.x = 335;
    iw9.y = 587;
    iw9.w = 22;
    iw9.h = 20;
    iw9.rotation = -20;
    iw9.startAngle = 46;
    iw9.endAngle = fmod(46 + mainAngle, 360);
    iw9.clockWise = true;
    iw9.soundPlayer.load("bell_e4.wav");

    iw10.r = 75;
    iw10.x = 525;
    iw10.y = 587;
    iw10.w = 22;
    iw10.h = 20;
    iw10.rotation = -32;
    iw10.startAngle = 46;
    iw10.endAngle = fmod(46 + mainAngle, 360);
    iw10.clockWise = false;
    iw10.soundPlayer.load("bell_d#4.wav");
    
    ofBackground(0);
    
    rotation1 = 0;
    rotation1last = 0;
    
    
    phases = {0, 0, 0, 0};
    frequencies = { 65.41, 73.42, 98.00, 123.47 };
    updateWaveform(512);
    ofSoundStreamSetup(1, 0);
    
    int a = 0;
    
    for (float t = 0; t < 1; t += 0.05) {
        evolvente1.push_back(ofPoint(
            r1 * ( cos(t) + (t - a) * sin(t) ),
            r1 * ( sin(t) - (t - a) * cos(t) )
        ));
        
        evolvente2.push_back(ofPoint(
            r1 * ( cos(t) + (t - a) * sin(t) ),
            - r1 * ( sin(t) - (t - a) * cos(t) )
        ));
    }
    
    ofNoFill();
    
    soundPlayer.load("beat.wav");
    soundPlayer.play();
    soundPlayer.setLoop(true);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
}

void ofApp::updateWaveform(int waveformResolution) {
    waveform.resize(waveformResolution);
    
    float waveformStep = (M_PI * 2.) / (float) waveform.size();
    int harmonics = 11;
    
    for(int i = 0; i < waveform.size(); i++) {
        float baseStep = i * waveformStep;
        waveform[i] = 0;
        for (int h = 1; h <= harmonics; h+=2) {
            waveform[i] += sin(baseStep * h) / h;
        }
        
    }
}

void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    
    // soundPlayer.play();
    /*
    float sampleRate = 44100;
    float phaseStep = frequencies[0] / sampleRate;
    
    
    for(int i = 0; i < bufferSize * nChannels; i += nChannels) {
        phases[0] += phaseStep;
        int waveformIndex = (int)(phases[0] * waveform.size()) % waveform.size();
        output[i] = waveform[waveformIndex];
    }
    
    if (rotation1 > iw1.triggerAngle && rotation1 < (iw1.triggerAngle + mainAngle)) {
        phaseStep = frequencies[3] / sampleRate;
        for(int i = 0; i < bufferSize * nChannels; i += nChannels) {
            phases[1] += phaseStep;
            int waveformIndex = (int)(phases[1] * waveform.size()) % waveform.size();
            output[i] += waveform[waveformIndex];
        }
    }
    
    if (rotation1 > iw2.triggerAngle && rotation1 < (iw2.triggerAngle + mainAngle)) {
        phaseStep = frequencies[2] / sampleRate;
        for(int i = 0; i < bufferSize * nChannels; i += nChannels) {
            phases[2] += phaseStep;
            int waveformIndex = (int)(phases[2] * waveform.size()) % waveform.size();
            output[i] += waveform[waveformIndex];
        }
    }
    
    if (rotation1 > iw3.triggerAngle && rotation1 < (iw3.triggerAngle + mainAngle)) {
        phaseStep = frequencies[1] / sampleRate;
        for(int i = 0; i < bufferSize * nChannels; i += nChannels) {
            phases[3] += phaseStep;
            int waveformIndex = (int)(phases[3] * waveform.size()) % waveform.size();
            output[i] += waveform[waveformIndex];
        }
    }
     */
    
}


void ofApp::drawToothWheelRotating(int r, int x, int y, int count, int offset, float toothHeight, float toothWidth, int speed) {
    ofPushMatrix();
    ofSetColor(255);
    ofTranslate(x, y);
    rotation1last = rotation1;
    rotation1 = fmod(speed * ofGetElapsedTimef(), 360);
    ofRotate(rotation1);
    drawToothWheel(r, count, offset, toothHeight, toothWidth);
    ofPopMatrix();
}


void ofApp::drawToothWheelIntermittent(intermittentWheel * w, int count, int offset, float toothHeight, float toothWidth) {
    ofPushMatrix();
    ofTranslate(w->x, w->y);
    
    if (w->startAngle < w->endAngle && rotation1 > w->startAngle && rotation1 < w->endAngle) {
        if (w->latched) {
            w->soundPlayer.setLoop(true);
            w->soundPlayer.play();
        }
        w->latched = false;
        if (w->clockWise) {
            ofRotate(w->rotation + rotation1 - w->startAngle);
        } else {
            ofRotate(w->rotation - (rotation1 - w->startAngle));
        }
    } else if (w->startAngle > w->endAngle && (rotation1 > w->startAngle || rotation1 < w->endAngle)) {
        if (w->latched) {
            w->soundPlayer.setLoop(true);
            w->soundPlayer.play();
        }
        w->latched = false;
        double delta =  rotation1 > w->startAngle ? (rotation1 - w->startAngle) : (rotation1 + 360 - w->startAngle);
        if (w->clockWise) {
            ofRotate(w->rotation + delta);
        } else {
            ofRotate(w->rotation - delta);
        }
    } else if (!w->latched) {
        w->soundPlayer.stop();
        double step = w->endAngle > w->startAngle ? (w->endAngle - w->startAngle) : (w->endAngle + 360 - w->startAngle);
        // latch the next angle
        if (w->clockWise) {
            w->rotation += step;
        } else {
            w->rotation -= step;
        }
        w->latched = true;
        ofRotate(w->rotation);
    } else {
        ofRotate(w->rotation);
    }
    
    drawToothWheel(w->r, count, offset, toothHeight, toothWidth);
    ofPopMatrix();
    
}

/**
 * @param {int} r - wheel radius.
 * @param {int} x - wheel center x.
 * @param {int} y - wheel center y.
 * @param {int} count - tooth count.
 * @param {int} offset - offset in degree (0-360) between teeth.
 * @param {float} toothHeight - height of a tooth.
 * @param {float} toothWidth - width of a tooth. (0-100)
 * @param {int} speed - rotation speed.
 *
 */
void ofApp::drawToothWheel(int r, int count, int offset, float toothHeight, float toothWidth) {
    
    int resolution = 100;
    
    int i = toothWidth;
    int scaledToothWidth = ofMap(toothWidth, 0, 100, 0, resolution);
    
    float offsetRadian = ofMap(offset, 0, 360, 0, 2 * PI);
    
    ofBeginShape();
    for (int c = 0; c < count; c++) {
        float theta = 0 + c * offsetRadian;
        for (float t = theta; t < theta + toothHeight; t += 0.01) {
            float x = r * (cos(t) + (t - theta) * sin(t));
            float y = r * (sin(t) - (t - theta) * cos(t));
            ofVertex(x, y);
        }
        theta =  2 * PI * (resolution - scaledToothWidth) / resolution - c * offsetRadian;
        for (float t = theta + toothHeight; t >= theta; t -= 0.01) {
            float x = r * (cos(t) + (t - theta) * sin(t));
            float y = r * (sin(t) - (t - theta) * cos(t));
            ofVertex(x, -y);
        }
        
        for (i = ofMap(0.7 + c * offsetRadian, 0, 2 * PI, 0, resolution - 1); i < ofMap((c + 1) * offsetRadian, 0, 2 * PI, 0, resolution - 1); i++) {
            float theta = ofMap(i, 0, resolution - 1, 0, 2 * PI);
            ofVertex(r * cos(theta), r * sin(theta));
        }
        
    }
    
    for (; i < resolution; i++) {
        float theta = ofMap(i, 0, resolution - 1, 0, 2 * PI);
        ofVertex(r * cos(theta), r * sin(theta));
    }
    ofEndShape(true);
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    drawToothWheelRotating(r1, x1, y1, 1, 60, 0.9, 7, speed);
    drawToothWheelIntermittent(&iw1, 8, mainAngle, 1, 9);
    drawToothWheelIntermittent(&iw2, 8, mainAngle, 1, 9);
    drawToothWheelIntermittent(&iw3, 8, mainAngle, 1, 9);
    drawToothWheelIntermittent(&iw4, 8, mainAngle, 1, 9);
    drawToothWheelIntermittent(&iw5, 8, mainAngle, 1, 9);
    drawToothWheelIntermittent(&iw6, 8, mainAngle, 1, 9);
    drawToothWheelIntermittent(&iw7, 8, mainAngle, 1, 9);
    drawToothWheelIntermittent(&iw8, 8, mainAngle, 1, 9);
    drawToothWheelIntermittent(&iw9, 8, mainAngle, 1, 9);
    drawToothWheelIntermittent(&iw10, 8, mainAngle, 1, 9);
    
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
