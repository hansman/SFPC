#pragma once

#include "ofMain.h"


struct intermittentWheel {
    int r;
    int x;
    int y;
    int w;
    int h;
    double rotation;
    double startAngle;
    double endAngle;
    Boolean latched;
    Boolean clockWise;
    ofSoundPlayer soundPlayer;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void drawWheelWithOneTooth();
        void inwardToothWheel();
    
        void drawToothWheel(int r, int count, int offset, float toothHeight, float toothWidth);
        void drawToothWheelRotating(int r, int x, int y, int count, int offset, float toothHeight, float toothWidth, int speed);
        void drawToothWheelIntermittent(intermittentWheel * w, int count, int offset, float toothHeight, float toothWidth);
    
        std::vector<double> phases;
        std::vector<double> frequencies;
    
        void audioOut(float * output, int bufferSize, int nChannels);
        void updateWaveform(int waveformResolution);
        std::vector<float> waveform;
    
    
        vector<ofPoint> evolvente1;
        vector<ofPoint> evolvente2;
    
        ofSoundStream soundStream;
        int speed;
        double mainAngle;
    
        int r1;
        int x1;
        int y1;
        int w1;
        int h1;
        double rotation1;
        double rotation1last;
    
        vector<intermittentWheel> iws;
    
        ofSoundPlayer soundPlayer;
    
};
