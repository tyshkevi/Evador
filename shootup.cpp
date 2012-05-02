/*
Creator: 	Irina Tyshkevich
File:	shootup.cpp
--------------------------

This file holds the shootUp class definitions. 
This function finds the paddles location and shoots an enemy at it from the bottom of the screen.

*/

#include "shootup.h"


#include <iostream>
#include <QTime>


 

// this constructor creates the object
Shootup::Shootup()
	{	
	
	//xdir = y;		// x coordinate
  	//ydir = x;		// y coordinate

  	image.load("shoot.png");	// loads in an image

  	rect = image.rect();	// sets the location 
  		 
  	//resetState();			// resets State to print to screen
  	//startState(x,y); 
	}

// this destructor deletes the Objects instance
Shootup::~Shootup() 
	{
  	std::cout << ("Shootup deleted\n");
	}

// this function automatically moves and translates the object down one
void Shootup::shoot()
	{
	rect.translate(0,-10);	
	}


	
// this function resets the state of the Objects instance	
void Shootup::startState(int x,int y) 
	{
	// this code generates a random value for the x-coordinate
	//QTime time = QTime::currentTime(); 
	//qsrand((uint)time.msec()); 
	
	//int random = (((rand() % (300)) + 1)); 
		 
	// this moves the Objects instance to a random location on the top row of the screen		
  	rect.moveTo(x, 400);
	}


// this function returns Objects instance location
QRect Shootup::getRect()
	{
  	return rect;
	}

// this function returns Objects instance image to be printed on screen
QImage & Shootup::getImage()
	{
  	return image;
	}
	
	
