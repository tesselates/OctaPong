#pragma once

#include <QApplication>
#include "PaddleFactory.hpp"
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
	
	public slots:
		void newGame() {};
	private:
		MainWindow w;
		PongView* p;
};


}  // pong namespace