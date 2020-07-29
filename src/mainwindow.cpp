#include "mainwindow.hpp"
#include <QLayout>
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
    QGridLayout* layout = new QGridLayout(this->ui->centralwidget); // no initialization here
    
    layout->setContentsMargins(0, 40, 0, 0);
    layout->addWidget(widget);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::change()
{
    this->ui->newGame->setText("LOL");
}
