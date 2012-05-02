/*
Creator: 	Irina Tyshkevich
File:	objects.h 
--------------------------

This file holds the Objects class declarations. 
Objects class is responsible for creating and controlling the objects. 

*/

#ifndef OBJECTS_H
#define OBJECTS_H

#include <QImage>
#include <QRect>

class Objects
	{
	public:
    		Objects(int, int);
    		~Objects();

  	public:
    		void resetState();		// function resets the states of the enemy object at top of screen   
    		void startState();  		
    		void autoMove();		// function moves the enemy object down continuously
		void autoMoveFast();
    		
    		QRect getRect();		// gets the pixel location of the object instance 
    		QImage & getImage();	// gets teh image of the object instance

  	private:
    		int speed;
    		
    		int xdir;			// controls x-coordinate of object
    		int ydir;			// controls y-coordinate of object
    		
    		bool stuck;
    		
    		QImage image;		// creates image
    		QRect rect;		// creates location
	};

#endif
