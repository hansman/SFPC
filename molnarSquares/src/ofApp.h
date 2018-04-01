#pragma once

#include "ofMain.h"

#define _USE_TEXTURED_SQUARES

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
        void drawRect(float x1,float y1,float w,float h);
        int width;
        int rectSpace;
        int rectCount;
        int rectSize;
        int maxDistortion;
        int dotSize;
        int distortion;
        int topSpace;
        int leftSpace;
        int seed;
        ofImage purplePaperSquare;
        ofImage purpleDot;
		
};
