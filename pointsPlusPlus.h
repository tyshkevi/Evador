/*
Creator: 	Irina Tyshkevich
File:	pointsPlusPlus.h
--------------------------

This file holds the pointsPlusPlus class declarations. 
*/

#ifndef POINTSPLUSPLUS_H_
#define POINTSPLUSPLUS_H_

#include "thing.h"

#include <QImage>
#include <QRect>

using namespace std; 

class pointsPlusPlus : public Thing
	{
	private:
		QImage image; 
		QRect rect; 
		
		int xdir; 
		int ydir; 
		
	public:
		pointsPlusPlus(int, int);
		~pointsPlusPlus();
		
		// controls start and movement
		void startState();
		void autoMove();
		
		// returns image and location
		QRect getRect(); 
		QImage & getImage(); 		
	}; 
	
#endif
