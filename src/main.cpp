#include "ofMain.h"
#include "ofApp.h"
#include "MultiWindowManager.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settingsWindow;
#ifdef _WIN32
	settingsWindow.setGLVersion(4, 6);
#else
	settingsWindow.setGLVersion(4, 1);
#endif
	settingsWindow.setSize(1920, 1080);
	settingsWindow.setPosition(ofVec2f(0, 0)); //Set to other monitor?
	//settingsWindow.multiMonitorFullScreen = true;
	//settingsWindow.windowMode = OF_FULLSCREEN;
	settingsWindow.monitor = 0;
	//Create the window
	std::shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settingsWindow);


	ofGLFWWindowSettings settingsWindowAdditional;
#ifdef _WIN32
	settingsWindowAdditional.setGLVersion(4, 6);
#else
	settingsWindowAdditional.setGLVersion(4, 1);
#endif
	settingsWindowAdditional.setSize(1920, 1080);
	settingsWindowAdditional.setPosition(ofVec2f(1921, 0)); //Set to other monitor?
	//settingsWindowAdditional.multiMonitorFullScreen = true;
	//settingsWindowAdditional.windowMode = OF_FULLSCREEN;
	settingsWindowAdditional.monitor = 1;
	settingsWindowAdditional.shareContextWith = mainWindow;
	std::shared_ptr<ofAppBaseWindow> additionalWindow = ofCreateWindow(settingsWindowAdditional);
	additionalWindow->setVerticalSync(false);

	std::shared_ptr<ofApp> mainApp(new ofApp);
	ofAddListener(additionalWindow->events().draw, mainApp.get(), &ofApp::drawAdditionalWindow);
	//Pass the points to ofApp
	//mainApp->addWindowPtr(mainWindow);
	//mainApp->addWindowPtr(additionalWindow);
	MultiWindowManager::get().addPtr(mainWindow);
	MultiWindowManager::get().addPtr(additionalWindow);

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();

}
