/*
Creator: 	Irina Tyshkevich
File:	evador.h 
--------------------------

This file holds the Evador class declarations. 
Evador class is responsible for the gameplay. 
Calls in the Objects and Paddle classes. 

*/


#ifndef EVADOR_H
#define EVADOR_H

#include "objects.h"
#include "paddle.h"
#include "ball.h"

#include "shootup.h"
#include "shootSide.h"
#include "follow.h"

#include "lifeMinus.h"
#include "lifeMinusMinus.h"
#include "lifePlus.h"
#include "lifePlusPlus.h"

#include "pointsMinus.h"
#include "pointsMinusMinus.h"
#include "pointsPlus.h"
#include "pointsPlusPlus.h"

#include <QWidget>
#include <QKeyEvent>

class Evador : public QWidget
	{
  	Q_OBJECT

  	public:
    		Evador(QWidget *parent = 0);
    		~Evador();

    		bool levelOne; 
    		bool levelTwo; 
    		bool levelThree;   
    		
    		bool shootUp;   	
    		bool shootFromSide;
    		bool following; 	
 

  	protected:
    		void paintEvent(QPaintEvent *event);	// function that paints the images as they move around the screen
    		void timerEvent(QTimerEvent *event);	// function that times the game play and controls pausing
    		void keyPressEvent(QKeyEvent *event);	// function that takes input from keyboard to control game

		void thingHappens(); 

    		void startGame();		// function that starts game when space bar is pressed
    		void pauseGame();		// function that pauses the game when 'p' is pressed
    		void stopGame();		// function that stops the game once the player runs out of lives
    		
    		void checkCollision();	// function that checks for collisions

  	private:
    		int x;		
    		int timerId;

    		Paddle *paddle;		// this creates an instance of the paddle which the player controls
    		Objects * objects[10];	// this creates 10 instances of enemy objects the player must avoid 
		Ball *ball; 
		
		Shootup *shootup;
		shootSide *shootside; 
		Follow *follow; 
		
		lifeMinus *thing1;
		lifeMinusMinus *thing2; 
		lifePlus *thing3; 
		lifePlusPlus *thing4; 
		
		pointsMinus *thing5; 
		pointsMinusMinus *thing6; 
		pointsPlus *thing7; 
		pointsPlusPlus *thing8; 
		
    		bool gameOver;			// function that determines whether the game is over or still r`unning			
    		bool gameStarted;		// function that determines whether the game has started or not
    		
    		
    		bool paused;			// function that determines whether the game is paused or not
    		bool menu; 			// function that determines whehter the menu should or shouldn't be displayed
    		

		};

#endif
