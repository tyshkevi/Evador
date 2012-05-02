/*
Creator: 	Irina Tyshkevich
File:	pointsMinus.h
--------------------------

This file holds the pointsMinus class declarations. 
*/

#ifndef POINTSMINUS_H_
#define POINTSMINUS_H_

#include "thing.h"

#include <QImage>
#include <QRect>

using namespace std; 

class pointsMinus : public Thing
	{
	private:
		QImage image; 
		QRect rect; 
		
		int xdir; 
		int ydir; 
		
	public:
		pointsMinus(int, int);
		~pointsMinus();
		
		// controls start and movement
		void startState();
		void autoMove();
		
		// returns location and image
		QRect getRect(); 
		QImage & getImage(); 		
	}; 
	
#endif
