#include "mainwindow.hpp"
#include "PongApp.hpp"
#include "PongModel.hpp"
#include "GraphicsFactory.hpp"

namespace pong {

PongApp::PongApp(int& argc, char* argv[]) : QApplication(argc, argv)  {
     
     PongModel pm = PongModel();
     pm.setUpTwoPlayerGame();
     QGraphicsScene* scene = new QGraphicsScene();
     p = new PongView();
     
     GraphicsFactory gf = GraphicsFactory(p, &pm);
     auto p1 = gf.createPaddle(0);
     auto p2 = gf.createPaddle(1);
     auto b = gf.createBall(0);

     scene->addItem(p1);
     scene->addItem(p2);
     scene->addItem(b);
     p->setFixedSize(500, 500);
     //p->setSceneRect(50, 50, 500, 500);
     p->setScene(scene);
     w.setGameView(p);
     w.show();
}


}  // pong namespace