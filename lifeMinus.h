/*
Creator: 	Irina Tyshkevich
File:	lifeMinus
--------------------------

This file holds the Ball class declarations. 
*/

#ifndef LIFEMINUS_H_
#define LIFEMINUS_H_

#include "thing.h"

#include <QImage>
#include <QRect>

using namespace std; 

class lifeMinus : public Thing
	{
	private:
		QImage image; 
		QRect rect; 
		
		int xdir; 
		int ydir; 
		
	public:
		lifeMinus(int, int);
		~lifeMinus();
		
		void startState();	// controls start state
		void autoMove();	// controls movement
			
		QRect getRect(); 		// returns the location
		QImage & getImage(); 	// returns the image
	}; 
	
#endif
