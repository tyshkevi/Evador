/*
Creator: 	Irina Tyshkevich
File:	ball.cpp 
--------------------------

This file holds the Ball class declarations. 
The Ball class is responsible for the movement of the astronaut. 

*/

#include "ball.h"
#include <iostream>

// this funcation creates an instance of the Ball in the game
// sets its initial location
// brings in a picture of an astronaut
Ball::Ball()
	{
  	xdir = 1;
  	ydir = -1;

  	image.load("ball.png");

  	rect = image.rect();
  	resetState();
	}

// this function deletes the instance of Ball
Ball::~Ball() 
	{
  	std::cout << ("Ball deleted\n");
	}

// this function controlls movement of the ball... 
// ... how it rebounds upon hitting a wall or the paddle
void Ball::autoMove()
	{
  	rect.translate(xdir, ydir);

  	if (rect.left() == 0) 
  		{
    		xdir = 1;
  		}

  	if (rect.right() == 300) 
  		{
    		xdir = -1;
  		}

  	if (rect.top() == 0) 
  		{
    		ydir = 1;
  		}
	}

// this function resets the state of the paddle
void Ball::resetState() 
	{
  	rect.moveTo(155, 55);
	}

// this function moves the ball to the bottom of the screen
void Ball::moveBottom(int bottom)
	{
  	rect.moveBottom(bottom);
	}

// this function moves the ball to the top of the screen
void Ball::moveTop(int top)
	{
  	rect.moveTop(top);
	}
	
// this function moves the ball to the left of the screen
void Ball::moveLeft(int left)
	{
  	rect.moveLeft(left);
	}

// this function moves the ball to the right of the screen
void Ball::moveRight(int right)
	{
  	rect.moveRight(right);
	}
	
	
// this function sets x
void Ball::setXDir(int x)
	{
  	xdir = x;
	}
	
// this function sets y
void Ball::setYDir(int y)
	{
  	ydir = y;
	}
	
// this function returns the x
int Ball::getXDir()
	{
  	return xdir;
	}
	
// this function returns the y
int Ball::getYDir()
	{
  	return ydir;
	}

// this function returns the location of the Ball
QRect Ball::getRect()
	{
  	return rect;
	}

// this function returns the image of the Ball
QImage & Ball::getImage()
	{
  	return image;
	}

