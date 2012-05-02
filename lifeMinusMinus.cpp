/*
Creator: 	Irina Tyshkevich
File:	lifeMinusMinus.cpp 
--------------------------

This file holds the lifeMinusMinus class declarations. 
If the paddle collides with this object, the player loses 10 lives. 

*/

#include "lifeMinusMinus.h"

#include <iostream>
#include <QTime>

using namespace std; 

// this function creates an instance of the class at gamestart
lifeMinusMinus::lifeMinusMinus(int x, int y) : Thing(0,0)
	{
	xdir = y; 
	ydir = x; 
	
  	image.load("lifeMinusMinus.png");	// loads in an image
  	rect = image.rect();	// sets the location 	
	
	startState(); 	
	}

// this function deletes the lifeMinusMinus instance
lifeMinusMinus::~lifeMinusMinus()
	{
	cout << ("Thing deleted\n"); 
	}
	
	
// this function resets the state of the Objects instance	
void lifeMinusMinus::startState() 
	{
	// this code generates a random value for the x-coordinate
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Objects instance to a random location on the top row of the screen		
  	rect.moveTo(random, 30);
	}

// this function returns Objects instance location
QRect lifeMinusMinus::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & lifeMinusMinus::getImage()
	{
  	return image;
	}
	
// this funcation moves this instance down in a straight line
void lifeMinusMinus::autoMove()
	{
		rect.translate(0, 15);
	}
	
