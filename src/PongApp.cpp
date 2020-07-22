#include "mainwindow.hpp"
#include "PongApp.hpp"

namespace pong {

PongApp::PongApp(int& argc, char* argv[]) : QApplication(argc, argv)  {
     qDebug()<<"press";
     p = new PongView();
     w.setGameView(p);
     w.show();
}


}  // pong namespace