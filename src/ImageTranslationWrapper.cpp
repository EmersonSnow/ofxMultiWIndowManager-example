#include "ImageTranslationWrapper.h"

void ImageTranslationWrapper::setup()
{
}

void ImageTranslationWrapper::update()
{

}


void ImageTranslationWrapper::draw(unsigned int windowIndex)
{
	for (unsigned int i = 0; i < MultiWindowManager::get().getNumber(); i++)
	{
		if (windowIndex == i)
		{
			for (unsigned int n = 0; n < images.size(); n++)
			{
				if (images[n].globalPosition.x < MultiWindowManager::get().getAbsoluteWidth(i))
				{
					//TODO: Images larger than two windows
					//if (!bFirstDraw)
					//{
						//TODO: Subsection off screen rendered section, oF might do this for me
						
						//bFirstDraw = true;
					//} else
					//{
						if ((images[n].globalPosition.x + images[n].drawWidth) < (MultiWindowManager::get().getAbsoluteWidth(i)))
						{
							ofVec2f calc(images[n].globalPosition.x-MultiWindowManager::get().getWidth(i), images[n].globalPosition.y);
							std::cout << calc << std::endl;
							images[n].image.draw(calc);
						} else
						{
							images[n].image.draw(images[n].globalPosition);
						}
					//}
					
					
				} 
			}
			break;
		}
	}
}

void ImageTranslationWrapper::addImage(std::string filePath, ofVec2f position, float width, float height)
{
	images.push_back(*new ImageTranslationContainer);
	images.back().image.load(filePath);
	images.back().globalPosition = position;
	images.back().drawWidth = width;
	images.back().drawHeight = height;
	//Because images are static in this version, we can work out which window the images will draw on
	//Cba do realtime

	unsigned int numWindows = MultiWindowManager::get().getNumber();
	for (unsigned int i = 0; i < numWindows; i++)
	{
		if (position.x < MultiWindowManager::get().getAbsoluteWidth(i))
		{
			if (position.x > MultiWindowManager::get().getAbsoluteX(i))
			{

			}
		}
	}
	/*unsigned int numWindows = MultiWindowManager::get().getNumber();
	images.back().localPositions.resize(numWindows);
	images.back().windowIndices.resize(numWindows);

	//Coded to support 2 windows only at first
	bool bFirstWindowWithin = false;
	for (unsigned int i = 0; i < numWindows; i++)
	{
		bool bFirstWindowThisLoop = false;
		if (position.x < MultiWindowManager::get().getAbsoluteWidth(i))
		{
			//Get first window it in
			//Checking if it in a former windows
			if (!bFirstWindowWithin)
			{
				//Perform code to do subsection of image, so it doesn't over draw
				if (i == 0)
				{
					std::cout << "Setting local position to - " << position << std::endl;
					images.back().localPositions.push_back(position);
					images.back().windowIndices.push_back(i);
				}
				else
				{
					images.back().localPositions.push_back(position - MultiWindowManager::get().getAbsoluteWidth(i)); //I think
					images.back().windowIndices.push_back(i);
				}
				bFirstWindowThisLoop = true;
				bFirstWindowWithin = true;
			}
			//Image is in window, or atleast in the former windows
			//Check if image is positon.x+width 
			if ((position.x + width) > (MultiWindowManager::get().getAbsoluteWidth(i)))
			{
				if (bFirstWindowThisLoop)
					break;
				//TODO:
			}
		}
	}*/
}


