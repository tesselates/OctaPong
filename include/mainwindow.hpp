#pragma once

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include "PongModel.hpp"
#include "config.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public pong::LifeChangeListener
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void setGameView(QWidget* widget);
    void setGameModel(pong::PongModel* pongModel) { this->pongModel = pongModel; };
    void setTimeController(QTimer* timer) { this->timer = timer; };

    void endGame();
    void lifeChanged(int player) {};
    void gameOver(int player) {};
private slots:
    void newGameEvent();

private:
    pong::PongModel* pongModel;
    QTimer* timer;
    Ui::MainWindow *ui;
};

