#pragma once

#include <QApplication>
#include "GraphicsManager.hpp"
#include <QDebug>
#include "MainWindow.hpp"
#include "PongView.hpp"
#include <iostream>

namespace pong {

class PongApp : public QApplication
{
	Q_OBJECT

public:
	PongApp(int& argc, char* argv[]);
	virtual ~PongApp() = default;
	
public slots:
	void invokeChange();

private:
	PongModel pongModel;
	MainWindow window;
	PongView* pongView;
	QTimer* timer;
	GraphicsManager gm;
};


}  // pong namespace
