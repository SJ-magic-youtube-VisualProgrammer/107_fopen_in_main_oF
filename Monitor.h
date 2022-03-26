/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include <ofMain.h>
#include "ofApp.h"

/************************************************************
************************************************************/
class MONITOR : public ofBaseApp{
private:
	enum{
		MAIN_WINDOW_W = 1280,
		MAIN_WINDOW_H = 720,
		
		MONITOR_WINDOW_W = 1280,
		MONITOR_WINDOW_H = 720,
		
		FINAL_DATA_W = 1280,
		FINAL_DATA_H = 720,
	};

	ofImage img_Screen;
	
public:
	MONITOR();
	~MONITOR();
	void exit();
	
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
	
	shared_ptr<ofApp> main_obj;
};


