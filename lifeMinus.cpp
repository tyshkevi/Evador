/*
Creator: 	Irina Tyshkevich
File:	lifeMinus.cpp 
--------------------------

This file holds the lifeMinus class declarations. 
If the paddle collides with this objects, the player loses 5 lives.

*/

#include "lifeMinus.h"

#include <iostream>
#include <QTime>

using namespace std; 

// this creates an instance of lifeMinus at the start of the game
lifeMinus::lifeMinus(int x, int y) : Thing(0,0)
	{
	xdir = y; 
	ydir = x; 

  	image.load("lifeMinus.png");	// loads in an image
  	rect = image.rect();	// sets the location 
  		
	startState(); 	
	}

// this deletes an instance
lifeMinus::~lifeMinus()
	{
	cout << ("Thing deleted\n"); 
	}
	
	
// this function resets the state of the Objects instance	
void lifeMinus::startState() 
	{
	// this code generates a random value for the x-coordinate
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Objects instance to a random location on the top row of the screen		
  	rect.moveTo(random, 30);
	}

// this function returns Objects instance location
QRect lifeMinus::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & lifeMinus::getImage()
	{
  	return image;
	}
	
// this function automatically moves the lifeMinus instance down	
void lifeMinus::autoMove()
	{
		rect.translate(0, 5);
	
	}
