/*
Creator: 	Irina Tyshkevich
File:	ball.h
--------------------------

This file holds the Ball class declarations. 
*/

#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QRect>

class Ball
	{
	public:
    		Ball();
    		~Ball();

  	public:
    		void resetState();		// resets ball state
    		
    		void moveBottom(int);	// moves Ball instance to bottom of screen
    		void moveTop(int);		// moves instance to top
   	 	void moveLeft(int);		// moves instance to left
    		void moveRight(int);	// moves instance to right
    			
    		void autoMove();		// controls movemnt
    		
    		void setXDir(int);		// sets x
    		void setYDir(int);		// sets y
    		int getXDir();			// gets x
    		int getYDir();			// gets y
    		
    		QRect getRect();		// returns location
    		QImage & getImage();	// gets image

  	private:
    		int angle;
    		int speed;
    
    		int xdir;	
    		int ydir;
    		bool stuck;
    
    		QImage image;
    		QRect rect;

	};

#endif


