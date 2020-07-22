#pragma once

#include <QMainWindow>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void setGameView(QWidget* widget);

private slots:
    void change();

private:
    Ui::MainWindow *ui;
};

