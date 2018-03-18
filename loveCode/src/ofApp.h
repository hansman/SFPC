#pragma once

#include "ofMain.h"

#define SLOGANS_MERGING 0
#define SLOGANS_SPLITTING 1
#define SLOGANS_ROTATING 2

struct MergingSlogans {
    ofPoint s1;
    ofPoint s2;
};

struct RotatingSlogans {
    float rotation0;
    float rotation1;
    float rotation2;
};

struct SplittingSlogans {
    ofPoint s1;
    ofPoint s2;
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
    
        void slogansMerging(int speed);
        void twoPartsRotating(int speed);
        void slogansSplitting(int speed);
        ofTrueTypeFont font;
    
        int width = 1024;
        int height = 768;
        string slogan;
        string sloganPart1;
        string sloganPart2;
    
        int sloganPartWidthLong;
        int sloganPartWidthShort;
        int sloganShortIndention;
        int sloganHeight;
        int spaceWidth;
        int currentState;
    
        MergingSlogans mergingSlogans;
        RotatingSlogans rotatingSlogans;
        SplittingSlogans splittingSlogans;
    
        int centerWidth;
        int centerHeight;
		
};
