/*
Creator: 	Irina Tyshkevich
File:	pointsPlus.cpp 
--------------------------

This file holds the pointsPlus class definitions. 
If the paddle collides with this object, the player gains 10 points.  

*/

#include "pointsPlus.h"

#include <iostream>
#include <QTime>

using namespace std; 

// this function creates an instance of the class
pointsPlus::pointsPlus(int x, int y) : Thing(0,0)
	{
	xdir = y; 
	ydir = x; 
	
	image.load("pointsPlus.png");	// loads in an image
  	rect = image.rect();	// sets the location
  	 
	startState();	
	}

// this function destroys that instance
pointsPlus::~pointsPlus()
	{
	cout << ("Thing deleted\n"); 
	}
	
	
// this function resets the state of the Objects instance	
void pointsPlus::startState() 
	{
	// this code generates a random value for the x-coordinate
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Objects instance to a random location on the top row of the screen		
  	rect.moveTo(random, 30);
	}

// this function returns Objects instance location
QRect pointsPlus::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & pointsPlus::getImage()
	{
  	return image;
	}
	
// this function moves the instance down the screen		
void pointsPlus::autoMove()
	{
		rect.translate(0, 10);
	}
	
	
