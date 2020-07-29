#pragma once

#include <QApplication>
#include "GraphicsFactory.hpp"
#include <QDebug>
#include "mainwindow.hpp"
#include "PongView.hpp"
#include <iostream>

namespace pong {

class PongApp : public QApplication
{
	Q_OBJECT

	public:
		PongApp(int& argc, char* argv[]);
		virtual ~PongApp() = default;
		
	private:
		PongModel pongModel;
		MainWindow w;
		PongView* p;
};


}  // pong namespace
