#include "MainWindow.hpp"
#include <QLayout>
#include "./ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->newGame, SIGNAL(released()), this, SLOT(newGameEvent()));
    

}

void MainWindow::setGameView(QWidget* widget) 
{
    QGridLayout* layout = new QGridLayout(this->ui->centralwidget); // no initialization here
    
    layout->setContentsMargins(0, 40, 0, 0);
    layout->addWidget(widget);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::newGameEvent()
{
    this->ui->newGame->setText("End game");
    this->timer->start(Config::update_rate);
    this->pongModel->reset();
    this->ui->newGame->disconnect();
    connect(this->ui->newGame, SIGNAL(released()), this, SLOT(endGame()));

}

void MainWindow::endGame()
{
    this->ui->newGame->setText("New game");
    this->timer->stop();
    this->ui->newGame->disconnect();
    connect(this->ui->newGame, SIGNAL(released()), this, SLOT(newGameEvent()));

}


void MainWindow::lifeChanged(int player) {

    QString s = QString::number(this->pongModel->getPlayer(player).life);

    if (player == 0) {
        this->ui->score1->setText(s);
    }

    if (player == 1) {
        this->ui->score2->setText(s);
    }
};

void MainWindow::gameOver(int player) {
    if (player == 0) {
        this->ui->score1->setText("LOSER");
    }

    if (player == 1) {
        this->ui->score2->setText("LOSER");
    }

    this->endGame();
};
