/*
Creator: 	Irina Tyshkevich
File:	evador.cpp 
--------------------------

This file holds the Evador class definitions. 
Evador class is responsible for the gameplay. 

*/

#include "evador.h"

#include <QPainter>
#include <QApplication>
#include <QString>
#include <QTimer>
#include <QTime>




// these values control the life remaining, the score incrementation during the game, and the duration of the game
int life = 100; 
int score = 0;
int tiempo = 0; 

// this function creates an 'instance' of the game in the beginning
Evador::Evador(QWidget *parent): QWidget(parent)
	{
  	x = 0;
  	gameOver = FALSE;		// sets gameOver to FALSE, because game hasn't begun or ended yet
  	
  	paused = FALSE;		// sets paused to FALSE, because game isn't paused or started yet
  	gameStarted = FALSE;	// sets gameStarted to FALSE, because the game isn't in play yet
  	menu = TRUE;			// sets meny to TRUE because the menu with game instructions should be displayed before game start
 
	shootUp = FALSE; 
	shootFromSide = FALSE;
	following = FALSE;
	
	for( int i=0 ; i<10 ; i++)
		{  	
  		objects[i] = new Objects((35*i), 40);	// places the 10 enemy instances on different points across the top of the screen
  		} 
  	
   	ball = new Ball();   	
  	paddle = new Paddle();					// places the paddle on the screen
  	
  	follow = new Follow;
 	shootup = new Shootup;
 	shootside = new shootSide();  
 
  		thing3 = new lifePlus(0,0); 
  		thing4 = new lifePlusPlus(0,0); 
 
  	
  		thing7 = new pointsPlus(0,0); 
  		thing8 = new pointsPlusPlus(0,0);  
  		  
  		thing1 = new lifeMinus(0,0); 
  		thing2 = new lifeMinusMinus(0,0); 
  	
  	  	thing5 = new pointsMinus(0,0); 
  		thing6 = new pointsMinusMinus(0,0); 
  	

  		
  	
	}

// this function deletes all instances of objects and the paddle 
Evador::~Evador() 
	{
 	delete paddle;	// deletes paddle 
 	delete ball; 
 	
 	delete follow;
 	delete shootside; 
 	delete shootup; 
 
 	for (int i=0; i<10; i++) 
 		{
   		delete objects[i];	// deletes all objects
 		}
 		
 	delete thing1; 
 	delete thing2; 
 	delete thing3; 
 	delete thing4; 
 	
 	delete thing5; 
 	delete thing6; 
 	delete thing7; 
 	delete thing8; 
 	
 	
	}

// this function paints all of the instances and writing when needed throughout the game
void Evador::paintEvent(QPaintEvent *event)
	{
  	QPainter painter(this);


	// the following code display the score and player life on the top left-hand corner of the screen
	QString string1; 
	QString string2; 
	
	QFont font("Courier", 12, QFont::DemiBold);
	QFontMetrics fm(font); 
	
	painter.setFont(font); 
	int h = height(); 
	int w = width(); 
	
	if( levelOne==TRUE )
		{
		painter.drawText(10, 20, "LEVEL 1");
		
		painter.drawText(10, 40, "Score: ");
		painter.drawText(70, 40, string1.append(QString("%1").arg(score)));

		painter.drawText(10, 60, "Life: ");
		painter.drawText(70, 60, string2.append(QString("%1").arg(life)));
		}
	if( levelTwo==TRUE )
		{
		painter.drawText(10, 20, "LEVEL 2");
		
		painter.drawText(10, 40, "Score: ");
		painter.drawText(70, 40, string1.append(QString("%1").arg(score)));

		painter.drawText(10, 60, "Life: ");
		painter.drawText(70, 60, string2.append(QString("%1").arg(life)));
		}
	if( levelThree==TRUE )
		{
		painter.drawText(10, 20, "LEVEL 3");
		
		painter.drawText(10, 40, "Score: ");
		painter.drawText(70, 40, string1.append(QString("%1").arg(score)));

		painter.drawText(10, 60, "Life: ");
		painter.drawText(70, 60, string2.append(QString("%1").arg(life)));
		}			

	// before the game starts, this function prints out the instruction menu onto the screen
	if (menu == TRUE)
		{
    		QFont font("Courier", 8, QFont::DemiBold);
    		QFontMetrics fm(font);
    		int textWidth = fm.width("Evador");

    		painter.setFont(font);
    		int h = height();
    		int w = width();

    		painter.translate(QPoint(w/2, h/2));
    		painter.drawText(-100, -100, "Welcome to EVADOR");	
    		painter.drawText(-100, -80, "~ Use your right/left arrow");	
    		painter.drawText(-100, -60, "  keys to avoid the moving aliens,");
    		painter.drawText(-100, -40, "  keep the astronaut away from ground");
    		painter.drawText(-100, -20, "  some objects give you life/points");
    		painter.drawText(-100, 0, "  some objects take life/points");	    		
    		painter.drawText(-100, 20, "Press the spacebar to start.");
    		painter.drawText(-100, 40, "Press 'r' to restart");
    		painter.drawText(-100, 60, "Press 'p' to pause");
    		painter.drawText(-100, 80, "Press 'Esc' to quit");    			
		}
	
	// if the game is over, the player has lost, this function displays Game Over on the screen	
  	else if (gameOver) 
  		{
    		QFont font("Courier", 15, QFont::DemiBold);
    		QFontMetrics fm(font);
    		int textWidth = fm.width("Game Over");

    		painter.setFont(font);
    		int h = height();
    		int w = width();

    		painter.translate(QPoint(w/2, h/2));
    		painter.drawText(- textWidth/2, 0, "Game Over");
  		}  		
  	// if the game has been started and the game isn't over, this code will continuously paint the objects and paddle images to the screen
  	 else 
  		{
    		painter.drawImage(paddle->getRect(), paddle->getImage());
    		painter.drawImage(ball->getRect(), ball->getImage());
    		
    		if( levelOne == TRUE || levelThree == TRUE )
    			{ 		
  			for( int i=0 ; i<10 ; i++ )
  				{
    				painter.drawImage(objects[i]->getRect(), objects[i]->getImage());
    				}
    			
			}
    		
    		
    		if( levelTwo == TRUE )
    			{
    			painter.drawImage(thing1->getRect(), thing1->getImage()); 
    			painter.drawImage(thing2->getRect(), thing2->getImage()); 
    			painter.drawImage(thing3->getRect(), thing3->getImage()); 
    			painter.drawImage(thing4->getRect(), thing4->getImage()); 
    			painter.drawImage(thing5->getRect(), thing5->getImage()); 
    			painter.drawImage(thing6->getRect(), thing6->getImage()); 
    			painter.drawImage(thing7->getRect(), thing7->getImage()); 
    			painter.drawImage(thing8->getRect(), thing8->getImage()); 

  			
    			}
    		if( levelThree == TRUE )
    			{
    			painter.drawImage(shootup->getRect(), shootup->getImage());
    			painter.drawImage(shootside->getRect(), shootside->getImage());
			painter.drawImage(follow->getRect(), follow->getImage());

    			} 

  		}
	}

// this function controls the movement of the enemy objects in relation to time
void Evador::timerEvent(QTimerEvent *event)
	{
 	int round = 0;
 	int speedTimes = 0;


	if( tiempo <= 100 )
		{
		levelOne = TRUE;
		levelTwo = FALSE; 
		levelThree = FALSE;
		}
	else if( 100 < tiempo && tiempo < 300 )
		{
		levelOne = FALSE; 
		levelTwo = TRUE;
		levelThree = FALSE;
		}
	else if( tiempo >= 300 )
		{
		levelOne = FALSE; 
		levelTwo = FALSE; 
		levelThree = TRUE;
		}
		


	if( levelOne==TRUE )
		{	
		speedTimes = 3; 
		
		while( speedTimes > 0 )
			{
			ball->autoMove();
			checkCollision();		// check to make sure the paddle hasn't hit the object at that location
  			repaint();
  			
  			speedTimes--;
  			}		
		for( int i=0 ; i<10 ; i++ )
			{
  			objects[i]->autoMove();	// hypothetically move the object to new location  			
  			checkCollision();		// check to make sure the paddle hasn't hit the object at that location
  			repaint();			// repaint the object at that new location
  			
			
  			if (objects[i]->getRect().bottom() > 400)
				{
    				objects[i]->resetState(); 	// when the object reaches the bottom of the screen, recreate it at the top
  				}
 			}	
		}
  	//----------------------------------------//	
  	if( levelTwo==TRUE )
  		{

		//	speedTimes = 3;
			
  		
  		for(int i=0; i<5; i++)
  			{
  			ball->autoMove();	
  			checkCollision();		// check to make sure the paddle hasn't hit the object at that location
			repaint(); 
  			}  	
  				
  		//while( speedTimes > 0 )
  		//	{
  		
  		for( int i=0; i<3; i++)
  			{
 			thingHappens(); 
 			}
  					
  				
		  	speedTimes--;	

  		//	}  			
  		}
  	//----------------------------------------//	
   	
  		
  	if( levelThree==TRUE )
  		{
		
			


  			for(int i=0; i<5; i++)
  				{
  				ball->autoMove();
				checkCollision();		// check to make sure the paddle hasn't hit the object at that location
  				repaint();  				
  				}
			 
			/*if(follow->getRect().x() > paddle->getRect().x())
				{
				follow->autoMoveLeft();
				}
			else if(follow->getRect().x() < paddle->getRect().x())
				{
				follow->autoMoveRight();
				}*/				
			
  			if ( round/3 == 1 )
  				{
  				shootUp = TRUE; 
  				}  				
  			if ( shootUp = TRUE )
  				{
 				
  				shootup->shoot(); 
  				checkCollision(); 
  				repaint(); 
  				} 
  				
  			if ( round/5 == 1 )
  				{
  				shootFromSide = TRUE; 
  				}	
  			if ( shootFromSide = TRUE )
  				{  				
  				shootside->shoot();
  				checkCollision(); 
  				repaint(); 
  				}	
	
			if ( round/6 == 1 )
				{
				following = TRUE;
				}
			if ( following = TRUE )
				{
				int xd = paddle->getRect().x(); 
				int yd = paddle->getRect().y(); 
				
				follow->autoMove(xd, yd);
				checkCollision();
				repaint(); 
				}
			
			for( int i=0 ; i<10 ; i++ )
				{
  				objects[i]->autoMoveFast();	// hypothetically move the object to new location  			
  				checkCollision();		// check to make sure the paddle hasn't hit the object at that location
  				repaint();			// repaint the object at that new location
  		
  				if (objects[i]->getRect().bottom() > 400)
					{
    					objects[i]->resetState(); 	// when the object reaches the bottom of the screen, recreate it at the top
  					}
 				}			
  		
  		round++;	  
  			
  		}		
  	score++; 
  	tiempo++;  	
  	}  
  
  			
  		
  	   		
  				
	

void Evador::thingHappens()
	{
	QTime time = QTime::currentTime(); 
	qsrand((uint)time.msec()); 
	
	int randomThing = (((rand() % (12)) + 1)); 
	
	if( randomThing == 1 )
		{
		thing1->resetState(); 
		thing1->autoMove(); 
		checkCollision(); 
		repaint(); 
		
		if (thing1->getRect().bottom() > 400)
			{
  			thing1->startState();   	// when the object reaches the bottom of the screen, recreate it at the top
    			}
    		}
		

	if( randomThing == 2 )
		{	
		thing2->resetState(); 
		thing2->autoMove(); 
		checkCollision(); 
		repaint(); 
		
		if (thing2->getRect().bottom() > 400)
			{
  			thing2->startState();   	// when the object reaches the bottom of the screen, recreate it at the top
    			}
		}

	if( randomThing == 3 )
		{
		thing3->resetState(); 
		thing3->autoMove(); 
		checkCollision(); 
		repaint(); 
		
		if (thing3->getRect().bottom() > 400)
			{
  			thing3->startState();  	// when the object reaches the bottom of the screen, recreate it at the top
    			}
    		}
    		
	if( randomThing == 4 )
		{
		thing4->resetState(); 
		thing4->autoMove(); 
		checkCollision(); 
		repaint(); 
		
		if (thing4->getRect().bottom() > 400)
			{
  			thing4->startState();  	// when the object reaches the bottom of the screen, recreate it at the top
    			}
    		}
    		
	if( randomThing == 5 )
		{
		thing5->resetState(); 
		thing5->autoMove(); 
		checkCollision(); 
		repaint();
		
		if (thing5->getRect().bottom() > 400)
			{
  			thing5->startState();   	// when the object reaches the bottom of the screen, recreate it at the top
    			}
    		}
    		
	if( randomThing == 6 )
		{ 
		thing6->resetState(); 
		thing6->autoMove(); 
		checkCollision(); 
		repaint();
		
		if (thing6->getRect().bottom() > 400)
			{
  			thing6->startState();   	// when the object reaches the bottom of the screen, recreate it at the top
    			} 
    		}
    		
	if( randomThing == 7 )
		{
		thing7->resetState(); 
		thing7->autoMove(); 
		checkCollision(); 
		repaint(); 
		
		if (thing7->getRect().bottom() > 400)
			{
  			thing7->startState();   	// when the object reaches the bottom of the screen, recreate it at the top
    			}
    		}
    		
	if( randomThing == 8 )
		{
		thing8->resetState(); 
		thing8->autoMove(); 
		checkCollision(); 
		repaint(); 
		
		if (thing8->getRect().bottom() > 400)
			{
  			thing8->startState();  	// when the object reaches the bottom of the screen, recreate it at the top
    			}
    		}
											
	}

// this function controls the paddle movement based on keyboard input
void Evador::keyPressEvent(QKeyEvent *event)
	{
    		switch (event->key()) 
    			{
    			// if left key pressed, move paddle to the left
    			case Qt::Key_Left:
       			{  
         			int x = paddle->getRect().x();
        			for (int i=1; i<=5; i++)
        				{
          			paddle->moveLeft(x-3);
          			}
        			break;
       			}
       		// if right key pressed, move paddle to the right
    			case Qt::Key_Right:
        			{ 
          		int x = paddle->getRect().x();
          		for (int i=1; i<=5; i++)
          			{
          			paddle->moveRight(x+3);
          			}
        			}
        		
        		break;
        		
        		// if 'p' key pressed, pause the game
    			case Qt::Key_P:
        			{ 
          		pauseGame();
        			}
        
        		break;
        		
        		// if 'r' key pressed, restart the game        		
    			case Qt::Key_R:
        			{ 
        			life = 100; 
        			score = 0; 
        			tiempo = 0; 
        			
    				paddle->resetState();
    				ball->resetState();
    				
    				int ex = paddle->getRect().x();
  				int why = paddle->getRect().y(); 
  				
  				shootup->startState(ex,why);
  			
    			
    				//shootside->startState(); 
    				follow->startState();
    				
    				thing1->startState();   
    				thing2->startState();  
    				thing3->startState();  
    				thing4->startState();  
    				thing5->startState();  
    				thing6->startState();  
    				thing7->startState();  
    				thing8->startState();  


    				for (int i=0; i<10; i++) 
    					{
    					objects[i]->resetState(); 
    					} 
        			}
        
        		break;
        		
        		// if space key pressed, start the game
    			case Qt::Key_Space:
        			{
          		startGame();
        			}
        			
        		break;
        		
        		// if escape key pressed, end the game
    			case Qt::Key_Escape:
        			{
          		qApp->exit();
        			}

        		break;
        		
        		// when a key is pressed, an event occurs, program reacts accordinglly
    			default:
   				{
        			QWidget::keyPressEvent(event);
        			}
    			}
	}

// once the space bar is pressed, this function starts the game play 
void Evador::startGame()
	{ 
  	if (!gameStarted) 
  		{
  		menu = FALSE; 			// turns off menu
    		paddle->resetState();	// resets the paddle
    		ball->resetState(); 
    		
    		if( levelTwo == TRUE )
    			{
    			thing1->startState();  
    			thing2->startState();  
    			thing3->startState();  
    			thing4->startState();  
    			thing5->startState();  
    			thing6->startState();  
    			thing7->startState();  
    			thing8->startState();  
   

    			}
    			
    		if( levelThree == TRUE )
    			{
    			int ex = paddle->getRect().x();
  			int why = paddle->getRect().y(); 
  				
  			shootup->startState(ex, why);
    			
    			follow->startState();
    			shootside->startState(ex, why);
    			

			}

    		for (int i=0; i<10; i++) 
    			{
    			if ( tiempo == i*10 )
    				{
    				objects[i]->startState(); 	// resets enemy objects to the screen
    				}
    			
    			}  
    			
    		gameOver = FALSE; 			// sets gameOver to FALSE because game isn't over 	
    		gameStarted = TRUE;			// sets gameStarted to TRUE because the game has started
    		levelOne = TRUE; 


    		timerId = startTimer(150); 	// sets the time and thus the object movement
    		
      		
    		life = 100; 				// initializes life to 100%
    		score = 0;  				// initializes score to 0
    		tiempo = 0; 
  		}
	}
// once the 'p' key is pressed, this function pauses the game
void Evador::pauseGame()
	{
  	if (paused) 
  		{
    		timerId = startTimer(10);
    		paused = FALSE;
  		} 
  	else 
  		{
    		paused = TRUE;
    		killTimer(timerId); 
   		}
	}
// once the 'Esc' key is pressed, or under other game ending conditions, this function ends game play
void Evador::stopGame()
	{
  	killTimer(timerId);   	// ends the timer and thus the movement and thus stops score incrementation 
  	gameOver = TRUE;      	// sets gameOver to TRUE because the game is over	
 	gameStarted = FALSE;	// sets gameStarted to FALSE because the game is now over and no longer going	
	}



// this function checks for collision between enemy objects and player's paddle
void Evador::checkCollision()
	{
	for( int i=0 ; i<10 ; i++ )
		{
		if ((objects[i]->getRect()).intersects(paddle->getRect())) 
			{
			if( life==0 )
				{
				stopGame();
    				}    					
    			else
    				{
    				life--;
    				objects[i]->resetState();
    				}
  			}
  		} 

	if ((shootup->getRect()).intersects(paddle->getRect())) 
		{
		if( life==0 )
			{
			stopGame();
    			}    					
    		else
    			{
    			life= life-5;
    			shootup->startState(0,0);
    			}
  		}
  	if( shootup->getRect().top() < 0 )
  		{
  		int ex = paddle->getRect().x(); 
  		int why = paddle->getRect().y(); 
  		
  		shootup->startState(ex,why); 
  		shootUp = FALSE;
  		}
  		
	if((shootside->getRect()).intersects(paddle->getRect()))
		{
		if( life==0 )
			{
			stopGame(); 
			}
		else
			{
			life= life-5; 
			shootside->startState(0,0); 
			}
		}	
  	if( shootside->getRect().bottom() > 400 )
  		{
  		int exx = paddle->getRect().x(); 
  		int whyy = paddle->getRect().y();
  		 		
  		shootside->startState(exx, whyy); 
  		shootFromSide = FALSE;
  		}
  		
  		
	if((follow->getRect()).intersects(paddle->getRect()))
		{
		if( life==0 )
			{
			stopGame(); 
			}
		else
			{
			life= life-5; 
			follow->startState(); 
			following = FALSE;
			}
		}
  	
  		
  	if (ball->getRect().bottom() > 400)
  		{
		if( life==0 )
			{
			stopGame();
    			}    					
    		else
    			{
    			life = life - 5;
    			ball->resetState();
    			}
		}
		
  	if ((ball->getRect()).intersects(paddle->getRect())) 
  		{

    		int paddleLPos = paddle->getRect().left();  
    		int ballLPos = ball->getRect().left();   

    		int first = paddleLPos + 8;
    		int second = paddleLPos + 16;
    		int third = paddleLPos + 24;
    		int fourth = paddleLPos + 32;

    		if (ballLPos < first) 
    			{
      		ball->setXDir(-1);
      		ball->setYDir(-1);
    			}

    		if (ballLPos >= first && ballLPos < second) 
    			{
      		ball->setXDir(-1);
      		ball->setYDir(-1*ball->getYDir());
    			}

    		if (ballLPos >= second && ballLPos < third) 
    			{
       		ball->setXDir(0);
       		ball->setYDir(-1);
    			}

    		if (ballLPos >= third && ballLPos < fourth) 
    			{
       		ball->setXDir(1);
       		ball->setYDir(-1*ball->getYDir());
    			}

   	 	if (ballLPos > fourth) 
   	 		{
      		ball->setXDir(1);
      		ball->setYDir(-1);
    			}
    		}
  
  
    		
	if ((paddle->getRect()).intersects(thing1->getRect())) 
		{
		life = life - 5; 
		
		if( life<=0 )
			{
			stopGame();
    			} 
    			
    		thing1->startState(); 
  		}     		
 	if ((paddle->getRect()).intersects(thing2->getRect())) 
		{
		life = life - 10; 
		
		if( life <= 0 )
			{
			stopGame();
    			} 
    		
    		thing2->startState(); 
  		}     		
	if ((paddle->getRect()).intersects(thing3->getRect())) 
		{
		life = life + 5; 
    		thing3->startState(); 
  		}    		
 	if ((paddle->getRect()).intersects(thing4->getRect())) 
		{
		life = life + 10; 
	 	thing4->startState(); 
  		}  

  		
  		
	if ((paddle->getRect()).intersects(thing5->getRect())) 
		{
		score = score - 20;  
    		thing5->startState(); 
  		}   
  	if ((paddle->getRect()).intersects(thing6->getRect())) 
		{
		score = score - 50;  
    		thing6->startState(); 
  		}  
  	if ((paddle->getRect()).intersects(thing7->getRect())) 
		{
		score = score + 20;  
    		thing7->startState(); 
  		}  
  	if ((paddle->getRect()).intersects(thing8->getRect())) 
		{
		score = score + 50;  
    		thing8->startState(); 
  		}  		 

	
    	

	}
  		
	


