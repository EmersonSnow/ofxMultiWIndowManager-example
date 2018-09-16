#include "MultiWindowManager.h"

MultiWindowManager MultiWindowManager::instance;

MultiWindowManager MultiWindowManager::get()
{
 	static MultiWindowManager instance = * new MultiWindowManager;
	return instance;
}


void MultiWindowManager::addPtr(std::shared_ptr<ofAppBaseWindow>& window)
{
	ptr.push_back(window);
}

std::shared_ptr<ofAppBaseWindow>& MultiWindowManager::getPtr(unsigned int index) const
{
	return ptr[index].lock();
}

unsigned int MultiWindowManager::getNumber() const
{
	return ptr.size();
}

void MultiWindowManager::setFullscreen(unsigned int index, bool b) const
{
	getPtr(index)->setFullscreen(b);
}

void MultiWindowManager::setVerticalSync(unsigned int index, bool b) const
{
	getPtr(index)->setVerticalSync(b);
}

float MultiWindowManager::getAbsoluteX(unsigned int index)
{
	float sumWidth = 0.0;
	for (unsigned int i = 0; i < getNumber(); i++)
	{
		if (index == i)
		{
			break;
		}
		sumWidth += getPtr(i)->getWidth();
	}
	return sumWidth;
}

float MultiWindowManager::getWidth(unsigned int index) const
{
	return getPtr(index)->getWidth();
}

float MultiWindowManager::getAbsoluteWidth(unsigned int index) const
{
	float sumWidth = 0.0;
	for (unsigned int i = 0; i < getNumber(); i++)
	{
		sumWidth += getPtr(i)->getWidth();
		if (index == i)
		{
			break;
		}
	}
	return sumWidth;
}

float MultiWindowManager::getHeight(unsigned int index) const
{
	return getPtr(index)->getHeight();
}

void MultiWindowManager::closeWindow(unsigned int index)
{
	getPtr(index)->close();
	ptr.erase(ptr.begin() + index);
}

