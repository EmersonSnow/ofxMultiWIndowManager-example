#pragma once

#include "ofMain.h"
#include "MultiWindowManager.h"
#include "ImageTranslationWrapper.h"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	void drawAdditionalWindow(ofEventArgs & args);

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	//Created a singleton class to handle window manager, so I don't have to repeat code
/*public:
	//Shared_ptr access
	void addWindowPtr(std::shared_ptr<ofAppBaseWindow> & window);
	std::shared_ptr<ofAppBaseWindow> & getPtr(unsigned int index);
	std::vector<std::weak_ptr<ofAppBaseWindow>> ptr;*/

public:
	//Additional objects
	ImageTranslationWrapper imageTranslationWrapper;
};
