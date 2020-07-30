#include "MainWindow.hpp"
#include "PongApp.hpp"
#include "PongModel.hpp"
#include "GraphicsManager.hpp"

namespace pong {

PongApp::PongApp(int& argc, char* argv[]) : QApplication(argc, argv)  {
     timer = new QTimer();
     connect(timer, SIGNAL(timeout()), this, SLOT(invokeChange()));
     
     pongModel = PongModel();
     pongModel.setUpTwoPlayerGame();
     QGraphicsScene* scene = new QGraphicsScene();
     pongView = new PongView();
     gm = GraphicsManager(pongView, &pongModel);




     pongView->setFixedSize(500, 500);
     pongView->setSceneRect(0, 0, 500, 500);
     pongView->setScene(scene);
     pongView->setSceneRect(0, 0, 500, 500);
     pongView->fitInView(0, 0, 500, 500, Qt::KeepAspectRatio);
     window.setGameView(pongView);
     window.setGameModel(&pongModel);
     window.setTimeController(timer);
     
     pongModel.addListener(&gm);

     auto p1 = gm.createPaddle(0);
     auto p2 = gm.createPaddle(1);
     auto b = gm.createBall(0);
     gm.fireChangeEvent();
     scene->addItem(p1);
     scene->addItem(p2);
     scene->addItem(b);
     window.show();
}

void PongApp::invokeChange() {
     this->pongModel.progressGame(Config::frequency);
}


}  // pong namespace