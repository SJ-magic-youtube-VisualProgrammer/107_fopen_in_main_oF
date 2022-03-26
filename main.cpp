#include "ofMain.h"
#include "ofApp.h"

#include "Monitor.h"
#include <ofAppGLFWWindow.h>

/************************************************************
************************************************************/
void ReadConfigFile(int &r, int &g, int &b);

/************************************************************
************************************************************/

/******************************
******************************/
int main( int argc, char** argv ){
	/********************
	comment out for multi-window
	********************/
	/*
	int r = 255;
	int g = 0;
	int b = 0;
	
	ofSetupOpenGL(1024,768,OF_WINDOW);
	ReadConfigFile(r, g, b);
	ofRunApp(new ofApp(r, g, b));
	*/
	
	/********************
	C++11スマートポインタ入門
		https://qiita.com/hmito/items/db3b14917120b285112f
	********************/
	int r = 255;
	int g = 0;
	int b = 0;
	
	ofGLFWWindowSettings settings;

    settings.setSize(600, 600); // temporary.
	settings.setPosition(glm::vec2(0,0));
	settings.resizable = true;
	// settings.shareContextWith = secondWindow;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	
    settings.setSize(300, 300); // temporary
	settings.setPosition(glm::vec2(400,200));
	settings.resizable = true;
	settings.shareContextWith = mainWindow; // texure(Graphic memory)領域は、mainWindowと共有する : この設定がないと、fboなど、texture関連memoryの やり取りができない。
	shared_ptr<ofAppBaseWindow> secondWindow = ofCreateWindow(settings);
	
	ReadConfigFile(r, g, b);
	
	shared_ptr<ofApp> mainApp( new ofApp(r, g, b) );
	shared_ptr<MONITOR> MonitorApp( new MONITOR() );
	MonitorApp->main_obj = mainApp;
	
	ofRunApp(mainWindow, mainApp);
	ofRunApp(secondWindow, MonitorApp);
	
	ofRunMainLoop();
}

/******************************
******************************/
void ReadConfigFile(int &r, int &g, int &b)
{
	/********************
	********************/
	FILE* fp = fopen("../../../data/Config.txt", "r");
	FILE* fp_out = fopen("../../../data/sj_out.txt", "w");
	if(fp_out){
		fprintf(fp_out, "Saijo\n");
		fclose(fp_out);
	}
	
	/********************
	********************/
	printf("---------------------------------\n");
	if(!fp){
		printf("> config file not exist\n");
		fflush(stdout);
		return;
	}else{
		printf("> Read settings from config file\n");
		fflush(stdout);
	}
	
	/********************
	********************/
	enum{
		BUF_SIZE = 512,
	};
	char buf[BUF_SIZE];
	while(fgets(buf, BUF_SIZE, fp) != NULL){
		char buf_item[BUF_SIZE];
		int val;
		if(2 <= sscanf(buf, "%s%d", buf_item, &val)){
			if(strcmp(buf_item, "r") == 0)	r = val;
			if(strcmp(buf_item, "g") == 0)	g = val;
			if(strcmp(buf_item, "b") == 0)	b = val;
		}
	}
	
	/********************
	********************/
	printf("(R, G, B) =  (%d, %d, %d)\n", r, g, b);
	fflush(stdout);
	
	fclose(fp);
}


