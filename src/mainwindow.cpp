#include "mainwindow.hpp"
#include "./ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->newGame, SIGNAL(released()), this, SLOT(change()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::change()
{
    this->ui->newGame->setText("LOL");
}
