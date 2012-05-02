/*
Creator: 	Irina Tyshkevich
File:	pointsMinusMinus.h
--------------------------

This file holds the pointsMinusMinus class declarations. 
*/

#ifndef POINTSMINUSMINUS_H_
#define POINTSMINUSMINUS_H_

#include "thing.h"

#include <QImage>
#include <QRect>

using namespace std; 

class pointsMinusMinus : public Thing
	{
	private:
		QImage image; 
		QRect rect; 
		
		int xdir; 
		int ydir; 
	public:
		pointsMinusMinus(int, int);
		~pointsMinusMinus();
		
		// controls start and movement
		void startState();
		void autoMove();
		
		// returns image and location
		QRect getRect(); 
		QImage & getImage(); 		
	}; 
	
#endif
