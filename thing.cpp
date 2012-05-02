/*
Creator: 	Irina Tyshkevich
File:	thing.cpp 
--------------------------

This file holds the Thing class definitions. 
This is the base class of all the falling objects which increase/decrease life/points

*/

#include "thing.h"

#include <iostream>
#include <QTime>

using namespace std; 

Thing::Thing(int x, int y)
	{
	xdir = y; 
	ydir = x; 
	
	resetState(); 	
	}

Thing::~Thing()
	{
	cout << ("Thing deleted\n"); 
	}
/*	
void Thing::autoMove()
	{
	rect.translate(0, 10); 
	}*/
	
void Thing::resetState()
	{
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int randomNumber = (((rand() % (300)) + 1)); 
	
  	rect.moveTo(randomNumber, 40);	
	}
