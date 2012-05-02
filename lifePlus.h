/*
Creator: 	Irina Tyshkevich
File:	lifePlus.h
--------------------------

This file holds the lifePlus class declarations. 
*/

#ifndef LIFEPLUS_H_
#define LIFEPLUS_H_

#include "thing.h"

#include <QImage>
#include <QRect>

using namespace std; 

class lifePlus : public Thing
	{
	private:
		QImage image; 
		QRect rect; 
		
		int xdir; 
		int ydir; 
		
	public:
		lifePlus(int, int);
		~lifePlus();
		
		// creates start instance and controls movement
		void startState();
		void autoMove();
		
		// returns location and image
		QRect getRect(); 
		QImage & getImage(); 		
	}; 
	
#endif
