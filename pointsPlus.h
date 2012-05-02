/*
Creator: 	Irina Tyshkevich
File:	pointsPlus.h
--------------------------

This file holds the pointsPlus class declarations. 
*/

#ifndef POINTSPLUS_H_
#define POINTSPLUS_H_

#include "thing.h"

#include <QImage>
#include <QRect>

using namespace std; 

class pointsPlus : public Thing
	{
	private:
		QImage image; 
		QRect rect; 
		
		int xdir; 
		int ydir; 
		
		
	public:
		pointsPlus(int, int);
		~pointsPlus();
		
		// controls start and movement
		void startState();
		void autoMove();
		
		// returns image and location
		QRect getRect(); 
		QImage & getImage(); 		
	}; 
	
#endif
