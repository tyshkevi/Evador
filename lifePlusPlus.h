/*
Creator: 	Irina Tyshkevich
File:	lifePlusPlus.h
--------------------------

This file holds the lifePlusPlus class declarations. 
*/

#ifndef LIFEPLUSPLUS_H_
#define LIFEPLUSPLUS_H_

#include "thing.h"

#include <QImage>
#include <QRect>

using namespace std; 

class lifePlusPlus : public Thing
	{
	private:
		QImage image; 
		QRect rect; 
		
		int xdir; 
		int ydir; 
		
	public:
		lifePlusPlus(int, int);
		~lifePlusPlus();
		
		// controls start location and movement
		void startState();
		void autoMove();
		
		// returns location and image
		QRect getRect(); 
		QImage & getImage(); 		
	}; 
	
#endif
