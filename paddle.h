/*
Creator: 	Irina Tyshkevich
File:	paddle.h 
--------------------------

This file holds the Paddle class declarations. 
Paddle class is responsible for creating the  player's Paddle and taking in input for Paddle movement. 

*/

#ifndef PADDLE_H
#define PADDLE_H

#include <QImage>
#include <QRect>

class Paddle
	{
	public:
    		Paddle();
    		~Paddle();

  	public:
    		void resetState();		// resets the state of the Paddle at the bottom of the screen
    		void moveLeft(int);		// this function moves the paddle left if the left key is pressed
    		void moveRight(int);	// this function moves the paddle right if the right key is pressed
    		
    		QRect getRect();		// this function controls the location of the Paddle
    		QImage & getImage();	// this function controls the image of the Paddle

  	private:
    		QImage image;			// sets image
    		QRect rect;			// finds location
	};

#endif
