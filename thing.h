/*
Creator: 	Irina Tyshkevich
File:	thing.h
--------------------------

This file holds the Thing class declarations. 
*/

#ifndef THING_H_
#define THING_H_

#include <QImage>
#include <QRect>

using namespace std; 

class Thing
	{
	protected:
		int xdir; 
		int ydir; 
		
		QImage image;		// creates image
    		QRect rect;		// creates location		
	
	public:
		Thing(int, int); 
		~Thing(); 
		
		void resetState(); 
		
		virtual void startState() =0; // virtual startState function		
		// virtual void autoMove() =0; 

		
	};
	
#endif
