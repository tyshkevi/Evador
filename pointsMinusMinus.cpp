/*
Creator: 	Irina Tyshkevich
File:	pointsMinusMinus.cpp 
--------------------------

This file holds the pointsMinusMinus class definitions. 
If the paddle collides with this object, the player loses 20 points.  

*/

#include "pointsMinusMinus.h"

#include <iostream>
#include <QTime>

using namespace std; 

// this funcation creates an instance of the pointsMinusMinus class
pointsMinusMinus::pointsMinusMinus(int x, int y) : Thing(0,0)
	{
	xdir = y; 
	ydir = x; 
	
	image.load("pointsMinusMinus.png");	// loads in an image
  	rect = image.rect();	// sets the location
	
	startState();
	}

// this function deletes the class
pointsMinusMinus::~pointsMinusMinus()
	{
	cout << ("Thing deleted\n"); 
	}
	
	
// this function resets the state of the Objects instance	
void pointsMinusMinus::startState() 
	{
	// this code generates a random value for the x-coordinate
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Objects instance to a random location on the top row of the screen		
  	rect.moveTo(random, 30);
	}

// this function returns Objects instance location
QRect pointsMinusMinus::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & pointsMinusMinus::getImage()
	{
  	return image;
	}
	
// this function moves the instance down the screen		
void pointsMinusMinus::autoMove()
	{
		rect.translate(0, 10);
	}
	
