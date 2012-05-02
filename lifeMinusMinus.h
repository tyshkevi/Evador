/*
Creator: 	Irina Tyshkevich
File:	lifeMinusMinus.h
--------------------------

This file holds the lifeMinusMInus class declarations. 
*/

#ifndef LIFEMINUSMINUS_H_
#define LIFEMINUSMINUS_H_

#include "thing.h"

#include <QImage>
#include <QRect>

using namespace std; 

class lifeMinusMinus : public Thing
	{
	private:
		QImage image; 
		QRect rect; 
		
		int xdir; 
		int ydir; 
		
	public:
		lifeMinusMinus(int, int);
		~lifeMinusMinus();
		
		// control start state and movement
		void startState();
		void autoMove();
		
		// return image and the location
		QRect getRect(); 
		QImage & getImage(); 		
	}; 
	
#endif
