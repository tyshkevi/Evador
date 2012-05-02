/*
Creator: 	Irina Tyshkevich
File:	pointsPlusPlus.cpp 
--------------------------

This file holds the pointsPlusPlus class declarations. 
If the paddle collides with this object, the player gains 20 points.  

*/

#include "pointsPlusPlus.h"

#include <iostream>
#include <QTime>

using namespace std; 

// this function creates the instance
pointsPlusPlus::pointsPlusPlus(int x, int y) : Thing(0,0)
	{
	xdir = y; 
	ydir = x; 
	
	image.load("pointsPlusPlus.png");	// loads in an image
  	rect = image.rect();	// sets the location
	
	startState();	
	}

// this function destroys the instance
pointsPlusPlus::~pointsPlusPlus()
	{
	cout << ("Thing deleted\n"); 
	}
	
	
// this function resets the state of the Objects instance	
void pointsPlusPlus::startState() 
	{
	// this code generates a random value for the x-coordinate
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Objects instance to a random location on the top row of the screen		
  	rect.moveTo(random, 30);
	}

// this function returns Objects instance location
QRect pointsPlusPlus::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & pointsPlusPlus::getImage()
	{
  	return image;
	}
	
// this function moves the instance down the screen	
void pointsPlusPlus::autoMove()
	{
		rect.translate(0, 10);
	}
	
