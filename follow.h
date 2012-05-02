/*
Creator: 	Irina Tyshkevich
File:	follow.h
--------------------------

This file holds the follow class declarations. 

*/

#ifndef FOLLOW_H
#define FOLLOW_H

#include <QImage>
#include <QRect>

class Follow
	{
	public:
    		Follow();
    		~Follow();

  	public:
    		//void resetState();		// function resets the states of the enemy object at top of screen   
    		void startState();  		
    		
    		void autoMove(int, int);		// function moves the enemy object down continuously
		void autoMoveLeft(); 
		void autoMoveRight(); 
    		
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
