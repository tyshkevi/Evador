/*
Creator: 	Irina Tyshkevich
File:	objects.cpp
--------------------------

This file holds the Objects class definitions. 

*/

#include "objects.h"
#include "evador.h"

#include <iostream>
#include <QTime>



// this constructor creates the object
Objects::Objects(int x, int y)
	{	
	
	xdir = y;		// x coordinate
  	ydir = x;		// y coordinate

  	image.load("object.png");	// loads in an image

  	rect = image.rect();	// sets the location 
  		 
  	//resetState();			// resets State to print to screen
  	startState(); 
	}

// this destructor deletes the Objects instance
Objects::~Objects() 
	{
  	std::cout << ("Object deleted\n");
	}

// this function automatically moves and translates the object down one
void Objects::autoMove()
	{
	rect.translate(0,5);
	}
	
void Objects::autoMoveFast()
	{
	rect.translate(0,15);
	}

// this function resets the state of the Objects instance	
void Objects::resetState() 
	{
	// this code generates a random value for the x-coordinate
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Objects instance to a random location on the top row of the screen		
  	rect.moveTo(random, 40);
	}
// this function resets the state of the Objects instance	
void Objects::startState() 
	{
	// this code generates a random value for the x-coordinate
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Objects instance to a random location on the top row of the screen		
  	rect.moveTo(random, (random/2));
	}


// this function returns Objects instance location
QRect Objects::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & Objects::getImage()
	{
  	return image;
	}
	
	
	
