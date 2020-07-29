#pragma once

#include <QMainWindow>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public LifeChangeListener
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr, PongModel* pongModel);
    ~MainWindow();

    void setGameView(QWidget* widget);
    void endGame();

private slots:
    void newGameEvent();

private:
    PongModel* pongModel;
    Ui::MainWindow *ui;
};

