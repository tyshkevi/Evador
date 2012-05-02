 /*
Creator: 	Irina Tyshkevich
File:	follow.cpp
--------------------------

This file holds the Follow class Declarations. 
The Follow class is an objec that follows the paddle and tries to hit it. 
If the object collides with the paddle the player loses lives. 
*/

#include "follow.h"


#include <iostream>
#include <QTime>




// this constructor creates the object
Follow::Follow()
	{	
	image.load("shoot.png");	// loads in an image

  	rect = image.rect();	// sets the location 
  		 
	}

// this destructor deletes the Objects instance
Follow::~Follow() 
	{
  	std::cout << ("Follow deleted\n");
	}

// this function controls the movement of the Ball instance
// basically it compares its location to that of the paddle and adjusts accordingly
void Follow::autoMove(int x, int y)
	{
	if( rect.x() > x )
		{
		rect.translate(-1,0);
		}
	if( rect.x() < x )
		{
		rect.translate(1,0);
		}
	if( rect.y() > y )
		{
		rect.translate(0,-1);
		} 
	if( rect.y() < y )
		{
		rect.translate(0,1); 
		} 
	}




// this function resets the state of the Objects instance	
void Follow::startState() 
	{
	// this code generates a random value for the x-coordinate
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Follow instance to a random location on the screen		
  	rect.moveTo(random, (random/2));
	}


// this function returns Objects instance location
QRect Follow::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & Follow::getImage()
	{
  	return image;
	}
	
	
	
