#pragma once

#include "ofMain.h"

class MultiWindowManager
{
private:
	static MultiWindowManager instance;
public:
	static MultiWindowManager get();
private:
	std::vector<std::weak_ptr<ofAppBaseWindow>> ptr;
public:
	void addPtr(std::shared_ptr<ofAppBaseWindow> & window);
	std::shared_ptr<ofAppBaseWindow> & getPtr(unsigned int index) const;
	unsigned int getNumber() const;
	void setFullscreen(unsigned int index, bool b) const;
	void setVerticalSync(unsigned int index, bool b) const;
	float getAbsoluteX(unsigned int index);
	float getWidth(unsigned int index) const;
	float getAbsoluteWidth(unsigned int index) const;
	float getHeight(unsigned int index) const;
	void closeWindow(unsigned int index);

	
	
};