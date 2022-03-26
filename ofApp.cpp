/************************************************************
************************************************************/
#include "ofApp.h"

/******************************
******************************/
ofApp::ofApp(int _r, int _g, int _b)
: col_Background(_r, _g, _b)
{
}

/******************************
******************************/
ofApp::~ofApp(){
}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetBackgroundAuto(true);
	
	ofSetWindowTitle("fopen_test");
	// ofSetVerticalSync(false);
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetWindowShape(MAIN_WINDOW_W, MAIN_WINDOW_H);
	ofSetEscapeQuitsApp(false);
	
	/********************
	********************/
	fbo_FinalData.allocate(FINAL_DATA_W, FINAL_DATA_H, GL_RGBA, 4);
	ClearFbo(fbo_FinalData);
}

/******************************
******************************/
void ofApp::ClearFbo(ofFbo& fbo)
{
	fbo.begin();
		ofBackground(0, 0, 0, 255);
	fbo.end();
}

/******************************
******************************/
void ofApp::update(){
	ClearFbo(fbo_FinalData);
}

/******************************
******************************/
ofFbo& ofApp::getFbo_FinalData(){
	return fbo_FinalData;
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(col_Background);
}

/******************************
******************************/
void ofApp::keyPressed(int key){

}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
