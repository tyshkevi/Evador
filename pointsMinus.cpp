/*
Creator: 	Irina Tyshkevich
File:	pointsMinus.cpp 
--------------------------

This file holds the pointsMinus class definitions. 
If the paddle collides with this object, the player loses 10 points.  

*/

#include "pointsMinus.h"

#include <iostream>
#include <QTime>

using namespace std; 

// this function creates an instance of the pointsMinus class
pointsMinus::pointsMinus(int x, int y) : Thing(0,0)
	{
	xdir = y; 
	ydir = x; 
	
	image.load("pointsMinus.png");	// loads in an image
  	rect = image.rect();	// sets the location
	
	startState();
	}

// this function destroys the instance 
pointsMinus::~pointsMinus()
	{
	cout << ("Thing deleted\n"); 
	}
	
	
// this function resets the state of the Objects instance	
void pointsMinus::startState() 
	{
	// this code generates a random value for the x-coordinate
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Objects instance to a random location on the top row of the screen		
  	rect.moveTo(random, 30);
	}

// this function returns Objects instance location
QRect pointsMinus::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & pointsMinus::getImage()
	{
  	return image;
	}
	
// this function moves the pointsMinus instance down the screen		
void pointsMinus::autoMove()
	{
		rect.translate(0, 5); 
	}
	
	
