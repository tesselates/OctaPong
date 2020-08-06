#pragma once

#include "config.hpp"
#include "PongModel.hpp"

#include <QDebug>
#include <QTimer>
#include <QMainWindow>


/**
 *  Forward decleration of a MainWindow class, 
 *   this MainWindow is a seperate header that will be generated from a .ui file 
 *   by the make prodecure when building the project.
 */ 
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public pong::LifeChangeListener
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    /**
     *  Access methods
     */ 
    void setGameView(QWidget* widget);
    void setGameModel(pong::PongModel* pongModel) { this->pongModel = pongModel; };
    void setTimeController(QTimer* timer) { this->timer = timer; };

    /**
     *  Class logic
     */ 

    /**
     * @param player        indicates which player has lost a life
     */ 
    void lifeChanged(int player) override;

    /**
     * @param player        indicates which player has lost the game
     */ 
    void gameOver(int player) override;

private slots:

    /**
     *  Starts the game (starts the timer that updates the game model and allows inputs)
     */ 
    void newGameEvent();

    /**
     *  Ends the game, pauses the progression and resets the model
     */ 
    void endGame();

private:
    pong::PongModel* pongModel;  // the game model
    QTimer* timer;  // time controller for the game model
    Ui::MainWindow *ui;  // Qt's make generated ui
};

