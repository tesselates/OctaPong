#include "MainWindow.hpp"
#include "PongApp.hpp"
#include "PongModel.hpp"
#include "KeyFilter.hpp"
#include "GraphicsManager.hpp"

namespace pong {

PongApp::PongApp(int& argc, char* argv[]) : QApplication(argc, argv)  {
     timer = new QTimer();
     connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
     
     pongModel = PongModel();
     pongModel.setUpTwoPlayerGame();
     QGraphicsScene* scene = new QGraphicsScene();
     pongView = new PongView();
     gm = GraphicsManager(pongView, &pongModel);

     pongView->setFixedSize(Config::view_height, Config::view_height);
     pongView->setSceneRect(0, 0, 500, 500);
     pongView->setScene(scene);
     pongView->fitInView(0, 0, 500, 500, Qt::KeepAspectRatio);
     window.setGameView(pongView);
     window.setGameModel(&pongModel);
     window.setTimeController(timer);
     
     pongModel.addListener(&gm);
     pongModel.addLifeChangeListener(&window);

     auto p1 = gm.createPaddle(0);
     auto p2 = gm.createPaddle(1);
     auto b = gm.createBall(0);
     gm.fireChangeEvent();
     scene->addItem(p1);
     scene->addItem(p2);
     scene->addItem(b);
     
     std::function<void(bool)> up0 = [this](bool b) { this->pongModel.setUpPaddle(0, b); };
     std::function<void(bool)> down0 = [this](bool b) { this->pongModel.setDownPaddle(0, b); };
     std::function<void(bool)> up1 = [this](bool b) { this->pongModel.setUpPaddle(1, b); };
     std::function<void(bool)> down1 = [this](bool b) { this->pongModel.setDownPaddle(1, b); };
     
     keyFilters[0] = KeyFilter(Qt::Key_Up, Qt::Key_Down, up1, down1);
     keyFilters[1] = KeyFilter(Qt::Key_Z, Qt::Key_S, up0, down0);
     pongView->addKeyListener(&keyFilters[0]);
     pongView->addKeyListener(&keyFilters[1]);
     window.show();
}

void PongApp::updateGame() {
     this->pongModel.progressGame(Config::frequency);
}


}  // pong namespace
