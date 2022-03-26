/************************************************************
************************************************************/
#include "MONITOR.h"

/************************************************************
************************************************************/

/******************************
******************************/
MONITOR::MONITOR(){
	printf("> MONITOR::ctr\n");
	fflush(stdout);
}

/******************************
******************************/
MONITOR::~MONITOR(){
	printf("> MONITOR::dtr\n");
	fflush(stdout);
}

/******************************
******************************/
void MONITOR::exit(){
	printf("> MONITOR::exit\n");
	fflush(stdout);	
}

/******************************
******************************/
void MONITOR::setup(){
	/********************
	********************/
	ofSetBackgroundAuto(true);
	
	ofSetWindowTitle("Monitor");
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetWindowShape(MONITOR_WINDOW_W, MONITOR_WINDOW_H);
	ofSetEscapeQuitsApp(false);
}

/******************************
******************************/
void MONITOR::update(){

}

/******************************
******************************/
void MONITOR::draw(){
	/********************
	********************/
	ofDisableAlphaBlending(); // fbo上のαが2重で効いてしまうのを防止
	ofDisableSmoothing();
	
	ofBackground(0, 0, 0, 255);
	
	ofSetColor(255);
	main_obj->getFbo_FinalData().draw(0, 0, ofGetWidth(), ofGetHeight());
}

/******************************
******************************/
void MONITOR::keyPressed(int key){
	switch(key){
		case 'j':
			img_Screen.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
			img_Screen.save("screenshot.jpg");
			
			printf("> saved image\n");
			fflush(stdout);
			break;
			
		case 'p':
			img_Screen.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
			img_Screen.save("screenshot.png");
			
			printf("> saved image\n");
			fflush(stdout);
			break;
	}
}

/******************************
******************************/
void MONITOR::keyReleased(int key){

}

/******************************
******************************/
void MONITOR::mouseMoved(int x, int y ){

}

/******************************
******************************/
void MONITOR::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void MONITOR::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void MONITOR::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void MONITOR::mouseEntered(int x, int y){

}

/******************************
******************************/
void MONITOR::mouseExited(int x, int y){

}

/******************************
******************************/
void MONITOR::windowResized(int w, int h){

}

/******************************
******************************/
void MONITOR::gotMessage(ofMessage msg){

}

/******************************
******************************/
void MONITOR::dragEvent(ofDragInfo dragInfo){ 

}


