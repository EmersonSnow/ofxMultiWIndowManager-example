#pragma once

#include "ofMain.h"
#include "MultiWindowManager.h"

struct ImageTranslationContainer
{
	ofImage image;
	ofVec2f globalPosition;
	float drawWidth, drawHeight;
	std::vector<ofVec2f> localPositions;
	std::vector<unsigned int> windowIndices;
};

class ImageTranslationWrapper
{
	//Base functions
public:
	void setup();
	void update();
	void draw(unsigned int windowIndex);
	





	//Add image
private:
	std::vector<ImageTranslationContainer> images;
public:
	void addImage(std::string filePath, ofVec2f position, float width, float height);









	//Pass windows shared ptrs;
private:
	//std::vector<std::weak_ptr<ofAppBaseWindow>> ptr;
public:
	//void passWindowsPtr(std::vector<std::weak_ptr<ofAppBaseWindow>> & windows);
	//std::shared_ptr<ofAppBaseWindow> & getPtr(unsigned int index) const;
	
};