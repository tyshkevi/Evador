/*
Creator: 	Irina Tyshkevich
File:	shootup.h 
--------------------------

This file holds the Shootup class declarations. 


*/

#ifndef SHOOTUP_H
#define SHOOTUP_H

#include <QImage>
#include <QRect>

class Shootup
	{
	public:
    		Shootup();
    		~Shootup();

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
