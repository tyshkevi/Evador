/*
Creator: 	Irina Tyshkevich
File:	shootSide.cpp
--------------------------

This file holds the shooSide class definitions. 
This class finds the location of the paddle and shoots an enemy at it from the top of the screen.

*/

#include "shootSide.h"


#include <iostream>
#include <QTime>


 

// this constructor creates the object
shootSide::shootSide()
	{	
	
	//xdir = y;		// x coordinate
  	//ydir = x;		// y coordinate

  	image.load("shoot.png");	// loads in an image

  	rect = image.rect();	// sets the location 
  		 
  	//resetState();			// resets State to print to screen
  	//startState(); 
	}

// this destructor deletes the Objects instance
shootSide::~shootSide() 
	{
  	std::cout << ("shootSide deleted\n");
	}

// this function automatically moves and translates the object down one
void shootSide::shoot()
	{
	rect.translate(0,10);
	
	

	}


	
// this function resets the state of the Objects instance	
void shootSide::startState(int x, int y) 
	{
	// this code generates a random value for the x-coordinate
/*	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); */
		 
	// this moves the Objects instance to a random location on the top row of the screen		
 	rect.moveTo(x, 0);
	}


// this function returns Objects instance location
QRect shootSide::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & shootSide::getImage()
	{
  	return image;
	}
	
	
