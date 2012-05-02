/*
Creator: 	Irina Tyshkevich
File:	lifePlus.cpp 
--------------------------

This file holds the lifePlus class declarations. 
IF the paddle collides with this thing, the player gains 5 lives. 

*/

#include "lifePlus.h"

#include <iostream>
#include <QTime>

using namespace std; 

// this funcation creates the lifePlus instance
lifePlus::lifePlus(int x, int y) : Thing(0,0)
	{
	xdir = y; 
	ydir = x; 
	
  	image.load("lifePlus.png");	// loads in an image
  	rect = image.rect();	// sets the location 
	
	startState(); 	
	}

// this function destroys the lifePlus instance
lifePlus::~lifePlus()
	{
	cout << ("Thing deleted\n"); 
	}
	
	
// this function resets the state of the Objects instance	
void lifePlus::startState() 
	{
	// this code generates a random value for the x-coordinate
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Objects instance to a random location on the top row of the screen		
  	rect.moveTo(random, 30);
	}

// this function returns Objects instance location
QRect lifePlus::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & lifePlus::getImage()
	{
  	return image;
	}
	
// this function automatically moves the instance to the bottom of the screen
void lifePlus::autoMove()
	{
		rect.translate(0, 10);
	}
	
