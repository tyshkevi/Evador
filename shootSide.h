/*
Creator: 	Irina Tyshkevich
File:	shootSide.h 
--------------------------

This file holds the shootSide class declarations. 
 

*/

#ifndef SHOOTSIDE_H
#define SHOOTSIDE_H

#include <QImage>
#include <QRect>

class shootSide
	{
	public:
    		shootSide();
    		~shootSide();

  	public:
    		  
    		void startState(int,int);  		
    		void shoot();		// function moves the enemy object down continuously

    		
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
