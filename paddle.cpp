/*
Creator: 	Irina Tyshkevich
File:	paddle.cpp  
--------------------------

This file holds the Paddle class definitions. 

*/

#include "paddle.h"
#include <iostream>

// this constructor creates a Paddle instance
Paddle::Paddle()
	{
  	image.load("paddle.png");	// loads in the image

  	rect = image.rect();		// finds the location
  	resetState();				// creates the player Paddle on the bottom of the screen
	}

// this constructor destroys the Paddle
Paddle::~Paddle()
	{
 	std::cout << ("Paddle deleted\n");
	}

// if the left key is entered, this function moves the Paddle to the left
void Paddle::moveLeft(int left)
	{
  	if (rect.left() >= 2)
  		{
    		rect.moveTo(left, rect.top());
    		}
	}

// if the right key is enetered, this function moves the Paddle to the right
void Paddle::moveRight(int right)
	{
  	if (rect.right() <= 298)
  		{
    		rect.moveTo(right, rect.top());
    		}
	}

// this function resets the Paddle to a certain position on the bottom of the screen
void Paddle::resetState()
	{
  	rect.moveTo(200, 330);
	}

// gets the pixel location of the Paddle
QRect Paddle::getRect()
	{
  	return rect;
	}

// gets the image of the Paddle
QImage & Paddle::getImage()
	{
  	return image;
	}
	
	
	
	
	
