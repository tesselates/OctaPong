#pragma once

#include <QApplication>
#include "GraphicsManager.hpp"
#include <QDebug>
#include "MainWindow.hpp"
#include "PongView.hpp"
#include <iostream>

namespace pong {


/**
 *  Overachring class to control or instate controllers for the game model, game view and model
 */ 
class PongApp : public QApplication
{
	Q_OBJECT

public:
	PongApp(int& argc, char* argv[]);
	virtual ~PongApp() = default;
	

public slots:
	/**
	 *  Updates the game model based on the progression of time
	 */ 
	void updateGame();


private:
	PongModel pongModel;  // the game model
	MainWindow window;  // the main window
	PongView* pongView;  // the game view
	QTimer* timer;  // time controller for the game model
	GraphicsManager gm;  // the manager of the graphics for the view

	KeyFilter keyFilters[8];  // key input filers to control the game model
};


}  // pong namespace
