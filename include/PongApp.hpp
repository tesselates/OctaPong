#pragma once

#include <QApplication>
#include <PaddleFactory>
#include <iostream>

class PongApp : public QApplication
{
	Q_OBJECT

	public:
		PongApp(int& argc, char* argv[]);
		virtual ~PongApp();

	void keyPressEvent(QKeyEvent* event) {
        std::cout<<"press";
    };
    void keyReleaseEvent(QKeyEvent* event) {
        std::cout<<"release";
    };
	
	public slots:
		void newGame();
};

#endif // CUTE_CHESS_APPLICATION_H
