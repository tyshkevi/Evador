/*
Creator: 	Irina Tyshkevich
File:	lifePlusPlus.cpp 
--------------------------

This file holds the lifePlusPlus class declarations. 
If the paddle hits this object, the player gets 10 lives. 

*/

#include "lifePlusPlus.h"

#include <iostream>
#include <QTime>

using namespace std; 

// this function creates an instance of the lifePlusPlus class
lifePlusPlus::lifePlusPlus(int x, int y) : Thing(0,0)
	{
	xdir = y; 
	ydir = x; 
	
  	image.load("lifePlusPlus.png");	// loads in an image
  	rect = image.rect();	// sets the location 
	
	startState(); 	
	}

// this function destroys an instance of the class
lifePlusPlus::~lifePlusPlus()
	{
	cout << ("Thing deleted\n"); 
	}
	
	
// this function resets the state of the Objects instance	
void lifePlusPlus::startState() 
	{
	// this code generates a random value for the x-coordinate
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Objects instance to a random location on the top row of the screen		
  	rect.moveTo(random, 30);
	}

// this function returns Objects instance location
QRect lifePlusPlus::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & lifePlusPlus::getImage()
	{
  	return image;
	}

// this function moves the instance down the screen	
void lifePlusPlus::autoMove()
	{
		rect.translate(0, 10);
	}
	
