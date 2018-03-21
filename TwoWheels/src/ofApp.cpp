#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofSetCircleResolution(100);
    
    int width = 1280;
    int height = 760;
    int toothCount = 8;

    r1 = 75;
    x1 = width / 2;
    y1 = height / 2;
    w1 = 20;
    h1 = 20;
    speed = 90;
    mainAngle = 360 / toothCount;

    
    /*
     * Pushing structs of `intermittenWheel` onto vector `iws`
     * Fine tuning each wheel to fit into one another
     * Parameters: r x y w h rotation startAngle endAngle latched clockWise
     */
    
    int r2 = 50;
    int w2 = 22;
    int h2 = 20;
    
    iws.push_back({r2, width / 2 + 110, height / 2 + 110, w2, h2, -6, 10, fmod(10 + mainAngle * r2 / r1, 360), false});
    iws[iws.size() - 1].soundPlayer.load("bell_d#4.wav");
    
    iws.push_back({r2, width / 2 + 200, height / 2 + 200, w2, h2, -6, 10, fmod(10 + mainAngle * r2 / r1, 360), true});
    iws[iws.size() - 1].soundPlayer.load("bell_f4.wav");

    
    iws.push_back({r2, width / 2 + 290, height / 2 + 290, w2, h2, -6, 10, fmod(10 + mainAngle * r2 / r1, 360), false});
    iws[iws.size() - 1].soundPlayer.load("bell_c4.wav");
    
    
    iws.push_back({r2, width / 2 + 150, height / 2 - 40, w2, h2, -30, 317, fmod(317 + mainAngle * r2 / r1, 360), false});
    iws[iws.size() - 1].soundPlayer.load("bell_b4.wav");
    
    
    iws.push_back({r2, (int)(width / 2 + 150 * 1.85), (int)(height / 2 - 40 * 1.85), w2, h2, -14, 317, fmod(317 + mainAngle * r2 / r1, 360), true});
    iws[iws.size() - 1].soundPlayer.load("bell_a3.wav");
    
    iws.push_back({r2, (int)(width / 2 + 150 * 2.66), (int)(height / 2 - 40 * 2.66), w2, h2, -21, 317, fmod(317 + mainAngle * r2 / r1, 360), false});
    iws[iws.size() - 1].soundPlayer.load("bell_e4.wav");
    
    iws.push_back({r2, (int)(width / 2 + 150 * 3.47), (int)(height / 2 - 40 * 3.47), w2, h2, 26, 317, fmod(317 + mainAngle * r2 / r1, 360), true});
    iws[iws.size() - 1].soundPlayer.load("bell_g4.wav");
    
    iws.push_back({r2, (int)(width / 2 + 45), height / 2 - 150, w2, h2, 0, 260, fmod(260 + mainAngle * r2 / r1, 360), false});
    iws[iws.size() - 1].soundPlayer.load("bell_a4.wav");
    
    iws.push_back({r2, (int)(width / 2 + 45 * 1.82), (int)(height / 2 - 150 * 1.82), w2, h2, 20, 260, fmod(260 + mainAngle * r2 / r1, 360), true});
    iws[iws.size() - 1].soundPlayer.load("bell_e4.wav");
    
    iws.push_back({r2, width / 2 - 110, height / 2 - 110, w2, h2, -6, 190, fmod(190 + mainAngle * r2 / r1, 360), false});
    iws[iws.size() - 1].soundPlayer.load("bell_a3.wav");

    iws.push_back({r2, width / 2 - 200, height / 2 - 200, w2, h2, -6, 190, fmod(190 + mainAngle * r2 / r1, 360), true});
    iws[iws.size() - 1].soundPlayer.load("bell_a4.wav");
    
    iws.push_back({r2, width / 2 - 290, height / 2 - 290, w2, h2, -6, 190, fmod(190 + mainAngle * r2 / r1, 360), false});
    iws[iws.size() - 1].soundPlayer.load("bell_d#4.wav");
    
    iws.push_back({r2, width / 2 - 150, height / 2 + 40, w2, h2, -30, 137, fmod(137 + mainAngle * r2 / r1, 360), false});
    iws[iws.size() - 1].soundPlayer.load("bell_c4.wav");
    
    iws.push_back({r2, (int)(width / 2 - 150 * 1.85), (int)(height / 2 + 40 * 1.85), w2, h2, -14, 137, fmod(137 + mainAngle * r2 / r1, 360), true});
    iws[iws.size() - 1].soundPlayer.load("bell_b4.wav");
    
    iws.push_back({r2, (int)(width / 2 - 150 * 2.66), (int)(height / 2 + 40 * 2.66), w2, h2, -21, 137, fmod(137 + mainAngle * r2 / r1, 360), false});
    iws[iws.size() - 1].soundPlayer.load("bell_g4.wav");
    
    iws.push_back({r2, (int)(width / 2 - 150 * 3.47), (int)(height / 2 + 40 * 3.47), w2, h2, 26, 137, fmod(137 + mainAngle * r2 / r1, 360), true});
    iws[iws.size() - 1].soundPlayer.load("bell_e4.wav");
    
    iws.push_back({r2, width / 2 - 45, height / 2 + 150, w2, h2, 0, 80, fmod(80 + mainAngle * r2 / r1, 360), false});
    iws[iws.size() - 1].soundPlayer.load("bell_f4.wav");
    
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
    
//    soundPlayer.load("beat.wav");
//    soundPlayer.play();
//    soundPlayer.setLoop(true);
    
    
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
            ofRotate(w->rotation + (rotation1 - w->startAngle) * r1 / 50);
        } else {
            ofRotate(w->rotation - (rotation1 - w->startAngle) * r1 / 50);
        }
    } else if (w->startAngle > w->endAngle && (rotation1 > w->startAngle || rotation1 < w->endAngle)) {
        if (w->latched) {
            w->soundPlayer.setLoop(true);
            w->soundPlayer.play();
        }
        w->latched = false;
        double delta =  rotation1 > w->startAngle ? (rotation1 - w->startAngle) : (rotation1 + 360 - w->startAngle);
        if (w->clockWise) {
            ofRotate(w->rotation + delta * r1 / 50);
        } else {
            ofRotate(w->rotation - delta * r1 / 50);
        }
    } else if (!w->latched) {
        w->soundPlayer.stop();
        double step = w->endAngle > w->startAngle ? (w->endAngle - w->startAngle) : (w->endAngle + 360 - w->startAngle);
        // latch the next angle
        if (w->clockWise) {
            w->rotation += step * r1 / 50;
        } else {
            w->rotation -= step * r1 / 50;
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
    
    ofPoint start;
    
    ofBeginShape();
    for (int c = 0; c < count; c++) {
        float theta = 0 + c * offsetRadian;
        for (float t = theta; t < theta + toothHeight; t += 0.01) {
            float x = r * (cos(t) + (t - theta) * sin(t));
            float y = r * (sin(t) - (t - theta) * cos(t));
            ofVertex(x, y);
            if (c == 0) start = ofPoint(x,y);
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
    ofCircle(start, 10);
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    drawToothWheelRotating(r1, x1, y1, 1, 60, 0.9, 7, speed);
    
    vector<intermittentWheel>::iterator iterator;
    for (iterator = iws.begin(); iterator != iws.end(); ++iterator) {
        drawToothWheelIntermittent(&*iterator, 8, mainAngle, 1, 9);
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
