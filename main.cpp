/*
Creator: 	Irina Tyshkevich
File:	main.cpp 
--------------------------

Essentially this file creates the screen of the game. 
It calls in the Evador game files which control the actual game. 

*/

#include "evador.h"
#include <QDesktopWidget>
#include <QApplication>

using namespace std; 


void center(QWidget &widget)
	{	
	int x, y;
  	int screenWidth;
  	int screenHeight;

	// these variables set the screen width to 300 and height to 400
  	int WIDTH = 300;
  	int HEIGHT = 400;
  

  	QDesktopWidget *desktop = QApplication::desktop();

  	screenWidth = desktop->width();
  	screenHeight = desktop->height();
 
 	// this code sets the center of the screen
  	x = (screenWidth - WIDTH) / 2;
  	y = (screenHeight - HEIGHT) / 2;

  	widget.setGeometry(x, y, WIDTH, HEIGHT);
  	widget.setFixedSize(WIDTH, HEIGHT);
	}


int main(int argc, char *argv[])
	{
  	QApplication app(argc, argv);  
    
    	// creates the window based on the instructions of the Evador class 
  	Evador window;
  
  	window.setWindowTitle("Evador");
  	window.show();
  	center(window);

  	return app.exec();
	}
