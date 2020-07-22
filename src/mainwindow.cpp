#include "mainwindow.hpp"
#include "./ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->newGame, SIGNAL(released()), this, SLOT(change()));
    

}

void MainWindow::setGameView(QWidget* widget) 
{
    this->ui->verticalLayout->addWidget(widget);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::change()
{
    this->ui->newGame->setText("LOL");
}
